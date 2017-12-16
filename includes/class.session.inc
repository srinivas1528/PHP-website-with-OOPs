<?php
/**
 *The Session class is resposible for fuctions like login
 *logout
 */
 class Session {
   private $_is_logged_in = false;
   private $_id;

   function __construct(){
     session_start();
     self::_check_login();//set the attributes at the time of construction
   }

//Function to redirect to file in $url
   public function redirect_to($url=null){
     if(isset($url)){
       ob_start();
       header('Location: '.$url);
       ob_end_flush();
     }
   }
// returns the value of _is_logged_in. This is type Boolean.
   public function is_logged_in(){
     return $this->_is_logged_in;
   }

//checks the usernqme and password in db
//returns the result row in success else trows an exception.
   public function authenticate($username, $password){
     global $db;//$db is a globa variable created in pdo_connection.inc
     $username = $db->quote($username);

     /* $sql contains the query to get user details
      *  We fetch the user details using the username provided
	    *  We also check if password entered in login.php is the same in database
	    */
     $sql = "SELECT * FROM users WHERE username = ".$username." LIMIT 1";

     try {
       $result = $db->query($sql);
       $row = $result->fetch();
       if(password_verify($password, $row['password'])){
         return $row;
       }else{
         //new exception if password does not match
         throw new Exception("Password Incorrect");
       }
     } catch (Exception $e) {
       throw $e;//relay the exception from MyPDO class
     }
   }

   public function login($user_row){
     $_SESSION['is_logged_in'] = true;
   }

   public function logout(){
     unset($_SESSION['is_logged_in']);
   }

   /*
    * _check_login checks if session is active.
    *  if session is active, it sets _is_logged_in to TRUE.
    */

   private function _check_login(){
     if(isset($_SESSION['is_logged_in'])){
       $this->_is_logged_in = $_SESSION['is_logged_in'];
     }else{
       $this->_is_logged_in = false;
     }
   }
 }

$my_session = new Session();
?>
