<?php
//if logout button is pressed and user is logged in, close session and goto login.php
if(isset($_POST['logout']) || !$my_session->is_logged_in()){
  $my_session->logout();
  $my_session->redirect_to('login.php');
}

//if submit button of user form is clicked
if(isset($_POST['user_management']) && $_POST['rand'] == $_SESSION['rand']){
  try {
    $my_user = new User(  $_POST['first_name'],
                          $_POST['last_name'],
                          $_POST['username'],
                          $_POST['password'],
                          $_POST['type']);
    $message = $my_user->db_functions($_POST['query_type']);//run_query();
  } catch (Exception $e) {
    $message = $e->getMessage();
  }
}

// if upload photo button is clicked in Media form
if(isset($_POST['photo_upload']) && $_POST['rand'] == $_SESSION['rand']){
  try {
    $my_photo = new Photo(
                            $_POST['photo_name'],
                            $_POST['photo_caption'],
                            $_FILES['uploaded_file']['name'],
                            $_FILES['uploaded_file']['size'],
                            $_FILES['uploaded_file']['type'],
                            17);
//if there is no error in uploading file, save the uploaded file in target path
    if(!$_FILES['uploaded_file']['error']){
      $file_message = $my_photo->save($_FILES['uploaded_file']['tmp_name']);
    }else{
      $file_message = $my_photo->upload_error[$_FILES['uploaded_file']['error']];
    }

  } catch (Exception $e) {
    $file_message = $e->getMessage();
  }

}

/*
* Session variables are set with the PHP global variable: $_SESSION
* eg: $_SESSION['favcolor'] = "green";
*/
$rand = rand();
$_SESSION['rand'] = $rand;
?>
