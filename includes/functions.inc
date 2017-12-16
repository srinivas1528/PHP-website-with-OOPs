<?php
function run_query(){
  global $db;
  $message = null;

  /*Switch has three cases
  * 1. case add: adding user to database
  * 2. case find: Finding a user in database
  * 3. case delete: delete user in database
  */

  switch ($_POST['query_type']) {
    case 'add':
      //$_POST['first_name']  = $db->quote($_POST['first_name']);
      //$_POST['last_name']   = $db->quote($_POST['last_name']);
      //$_POST['username']    = $db->quote($_POST['username']);

      //save password and user_type
      $user_type = ($_POST['user_type'] == "user") ? 'u' : 'a';
      $password = password_hash($_POST['password'], PASSWORD_DEFAULT);

      $message = 'User added';

      //query to insert element to database
      $sql  = "INSERT INTO users (";
      $sql .= "first_name, last_name, username, password, type";
      $sql .= ") VALUES ( '";
      $sql .= $_POST['first_name'] ."', '". $_POST['last_name'] ."', '". $_POST['username']."', '". $password ."', '". $user_type."'";
      $sql .= ")";
      try {
        //execute $sql using the $db object
        $db->exec($sql);
        $message = "Query Successful.";
      } catch (Exception $e) {
        $message = $e->getMessage();  //copy error message to $message
      }
      break;

      case 'find':
      //query to find user in database
        $sql  = "SELECT first_name FROM users WHERE username = '".$_POST['username']."'";
        try {
          $find = $db->Query($sql)->fetchColumn();
          //if user is found then set $message to user information
          //if user is not found then set $message to 'user not found'
          $message = $find ? 'User found - ' . $find : 'User not found';
        } catch (Exception $e) {
          $message = $e->getMessage(); //copy error message to $message
        }
        break;

      case 'delete':
      //query to delete user from database
            $sql = "DELETE FROM users WHERE username = '".$_POST['username']."'";
            try{
              $db->exec($sql);
              $message = 'user deleted';
            } catch(Exception $e){
              $message = $e->getMessage(); //copy error message to $message
            }
            break;
    }
    return $message; // returns $message to
  }
  ?>
