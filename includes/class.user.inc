<?php
/**
 *User class members to be saved in DB
 */
class User{
  protected $_id;
  protected $_first_name;
  protected $_last_name;
  protected $_username;
  protected $_password;
  protected $_type;
  protected $_comment;

  //Constructor to the User class.
  function __construct( $fname  ='',
                        $lname  ='',
                        $uname  ='',
                        $pword  ='123',
                        $ty     ='user',
                        $comm   ='No Comment.'){
    try {
      $this->__set('first_name', $fname); // __set is a custom function defined in this class
      $this->__set('last_name', $lname);
      $this->__set('username', $uname);
      $this->__set('password', $pword);
      $this->__set('type', $ty);
      $this->__set('comment', $comm);
    } catch (Exception $e) {
      throw $e;
    }
  }

  // __get function is called implicitly
  public function __get($var){
    $var = '_'.$var;
    if (property_exists($this, $var)) {
      return $this->$var;
    }else {
      throw new Exception("{$var} No such Attribute1.");
    }
  }
  public function __set($var, $value){
    $var = '_'.$var;
    //Check if $var is not an id
    if (property_exists($this, $var) && $var != '_id') {
      $func = '_set'.$var;
      try {
        /*
        *  Here we are calling functions that begin with _set_.
        *  value of $func will start from _set
        *  for ex: $func will be equal to _set_first_name
        *  :: is a scope resolution operator
        */
        static::$func($value); // eg _set_first_name(mzeb)
      } catch (Exception $e) {
        throw $e;
      }
    }else {
      throw new Exception("{$var} No such Attribute.");
    }
  }

// ctype_alpha — Checks for alphabetic character(s) and has a return type of Boolean
  private function _set_first_name($value){
    if(ctype_alpha($value)){
      $this->_first_name = $value;
    }else{
      throw new Exception("first_name must be a alpha string, while {$value} is not an alpha string");
    }
  }
  private function _set_last_name($value){
    if(ctype_alpha($value)){
      $this->_last_name = $value;
    }else{
      throw new Exception("last_name must be a alpha string, while {$value} is not an alpha string");
    }
  }

  //The empty() function is used to check whether a variable is empty or not.
  private function _set_username($value){
    if(!empty($value)){
      $this->_username = $value;
    }else{
      throw new Exception("username must be a nonempty string");
    }
  }
  private function _set_password($value){
    if(!empty($value)){
      $this->_password = $value;
    }else{
      throw new Exception("password must be a nonempty string");
    }
  }
  private function _set_type($value){
    if($value == 'user' || $value == 'admin'){
      $this->_type = $value;
    }else{
      throw new Exception("Not a valid use type");
    }
  }
  private function _set_comment($value){
    $this->_comment = $value;
  }

  /*
  * the db_functions is called from home.php
  * $var will be either 'add', 'delete' or 'find' based on the selection of user in the dropdown
  * if $var is 'add', this function will go to the function '_add_user'
  */

  public function db_functions($var){
    $func = '_'.$var.'_user'; // for eg: value of $func will be _add_user
      try {

        return static::$func();//it will execute the corresponding function
      } catch (Exception $e) {
        throw $e;
      }
  }
  private function _add_user(){
    global $db;
    $user_type = ($this->_type == "user") ? 'u' : 'a';
    $password = password_hash($this->_password, PASSWORD_DEFAULT);
    $first_name  = $db->quote($this->_first_name);
    $last_name   = $db->quote($this->_last_name);
    $username    = $db->quote($this->_username);
    $comment     = $db->quote($this->_comment);

    $sql = "SELECT * FROM users WHERE username = '".$this->_username."' LIMIT 1";

    /*
    * checks if username does not exist
    * query1($sql) function is written in pdo_connection.inc file
    */
    if(!$db->query1($sql)->rowCount()){
      $sql  = "INSERT INTO users (";
      $sql .= "first_name, last_name, username, password, type, comment";
      $sql .= ") VALUES ( ";
      $sql .= $first_name .", ". $last_name .", ". $username.", '". $password ."', '". $user_type."'," .$comment;
      $sql .= ")";
      try {
        //exec($sql) function is written in pdo_connection.inc file
        $db->exec($sql);
        return "User with username ".$username." added, query Successful.";
      } catch (Exception $e) {
        throw $e;
      }
    }else{
      throw new Exception("The username ".$this->_username. " alrady exists");
    }
  }

  /*
  *  _delete_user() functions deletes the requested user from database
  */
  private function _delete_user(){
    global $db;
    $sql  = "DELETE FROM users WHERE username = '".$this->_username."' LIMIT 1";
    try {
      //exec($sql) function is written in pdo_connection.inc file
      $db->exec($sql);
      return 'User with Username '.$this->_username.' deleted from DB';
    } catch (Exception $e) {
      return $e;
    }
  }

  /*
  *  _find_user() functions finds the requested user from database
  */
  private function _find_user(){
    global $db;
    $message = null;
    $sql = "SELECT * FROM users WHERE username = '".$this->_username."' LIMIT 1";
    try {
      //query($sql) function is written in pdo_connection.inc file
      $result = $db->query($sql);
      $row = $result->fetch();
      $message = "
      <table>
        <tr>
          <th>First Name</th>
          <th>Last Name</th>
          <th>Username</th>
          <th>User Type</th>
        </tr>
        <tr>
          <td>{$row['first_name']}</td>
          <td>{$row['last_name']} </td>
          <td>{$row['username']}</td>
          <td>{$row['type']}</td>
        </tr>
      </table>
      ";
      return $message;
    } catch (Exception $e) {
      throw $e;
    }
  }
}

/*
  public function set_first_name($value=''){
    if(ctype_alpha($value)){
      $this->_first_name = $value;
    }else{
      throw new Exception("first_name must be a alpha string, while {$value} is not an alpha string");
    }

  }*/
/*
  public function get_first_name(){
    return $this->_first_name;
  }*/
/*
  public function __set($var, $value){
    $var = '_'.$var;
    switch ($var) {
      case '_first_name':
        if(ctype_alpha($value)){
          $this->_first_name = $value;
        }else{
        throw new Exception("first_name must be a alpha string, while {$value} is not an alpha string");
        }
        break;
      case '_last_name':
        if(ctype_alpha($value)){
          $this->_last_name = $value;
        }else{
          throw new Exception("last_name must be a alpha string, while {$value} is not an alpha string");
        }
        break;
      case '_username':
        if(!empty($value)){
          $this->_username = $value;
        }else{
          throw new Exception("username must be a nonempty string");
        }
        break;
      case '_password':
        if(!empty($value)){
          $this->_password = $value;
        }else{
          throw new Exception("password must be a nonempty string");
        }
        break;
      case '_type':
        if($value == 'user' || $value == 'admin'){
          $this->_type = $value;
        }else{
          throw new Exception("Not a valid use type");
        }
        break;
      case '_comment':
          $this->_comment = $value;
          break;
      default:
        throw new Exception("No such Attribute");
        break;
    }
  }//*/
  /*
  function __construct(){
    # code...
  }*/


?>
