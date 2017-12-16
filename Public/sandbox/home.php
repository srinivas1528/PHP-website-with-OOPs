<?php
try {
  require_once '../../includes/initialize.inc';
} catch (Exception $e) {
$message = $e->getMessage(); //copy error message to $message
}
?>

<?php
//$_POST is one of the superglobals in php
if(isset($_POST['user_management'])){ //Check if submit button from 'user_form' is clicked
  try {
    //Here we are creating an object of class User and running query
    //The query
    $my_user = new User(  $_POST['first_name'],
                          $_POST['last_name'],
                          $_POST['username'],
                          $_POST['password'],
                          $_POST['type']);
    $message = $my_user->db_functions($_POST['query_type']);//run_query();
  } catch (Exception $e) {
    $message = $e->getMessage(); //copy error message to $message
  }
}

?>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Home Page</title>
    <!--link is used to connect CSS file to html -->
    <link rel="stylesheet" href="../stylesheets/mystyle.css">
  </head>
  <body>
    <h1>Class of 2018 Pictures</h1>
    <hr>
    <h2>It's Good Time</h2>
    <hr>
    <div class="wrapper">
      <!--We have created three sections. the first division contains three sub-sections-->
      <div class="container">
        <div class="innerItem">
          <h2>Login</h2>
        </div>
        <div class="innerItem">
          <h2>Users</h2>
          <form action="<?php echo htmlspecialchars($_SERVER['PHP_SELF'])?>" method="post" id="user_form"> <!--Creating form to get user information -->
            <input type="text" name="first_name" placeholder="First Name"> <!--Placeholder attribute specifies the expected value in the input field-->
            <input type="text" name="last_name" placeholder="Last Name">
            <br>
            <input type="text" name="username" placeholder="Username">
            <input type="password" name="password">
            <br>

            <!-- name = "type" represents that the elements belong to same radio group-->
            User<input type="radio" name="type" value="user" checked>  <!--Creating a radio button -->
            Admin<input type="radio" name="type" value="admin">  <!--Creating a radio button -->

            <select name="query_type" form="user_form"> <!--create a dropdown -->
              <option value="add">Add User</option>
              <option value="find" selected>Find User</option>
              <option value="delete">Delete User</option>
            </select>
            <br>
            <button type="submit" name="user_management">Submit</button> <!--Create a submit button with name "user_management" -->
          </form>
          <?php echo isset($message) ? $message: null; ?> <!--check if message is set. if set then display it. -->
        </div>
        <div class="innerItem">
          <h2>Add Media</h2>
        </div>

      </div>

      <div class="outerItem">
        <p>We will use it later.</p>
      </div>
      <div class="outerItem">
        <?php
          for($i=0; $i<20; $i++){
            echo "<p>We will use it later.</p>";
          }
        ?>
      </div>
    </div>
    <div class="footer">
      <hr>
      <p>Copyrigt @ gunturi</p>
    </div>
  </body>
</html>
