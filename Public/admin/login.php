<?php
try {
  require_once '../../includes/initialize.inc';
} catch (Exception $e) {
$message = $e->getMessage();
}
?>
<?php
if($my_session->is_logged_in()){
  $my_session->redirect_to('index.php');
}

/*check if login button is clicked
* 1. authenticate if the username and password entered is correct
* 2. set $_SESSION['is_logged_in'] to TRUE;
* 3. Redirect to index.php page
*/
if(isset($_POST['login'])){
  // trim — Strips whitespace from the beginning and end of a string
  $username = trim($_POST['username']);
  $password = $_POST['password'];

  try {
    $row = $my_session->authenticate($username, $password);
    $my_session->login($row);
    $my_session->redirect_to('index.php');
  } catch (Exception $e) {
    $message = $e->getMessage(); //copy error message to $message
  }
}

/*
* Session variables are set with the PHP global variable: $_SESSION
* eg: $_SESSION['favcolor'] = "green";
*/
$rand = rand();
$_SESSION['rand'] = $rand;
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Login Page</title>
    <link rel="stylesheet" href="../stylesheets/mystyle.css">
  </head>
  <body>
    <h1>Class of 2018 Pictures</h1>
    <hr>
    <h2>It's Good Time</h2>
    <hr>
    <div class="wrapper">
      <div class="container">
        <div class="innerItem">
          <h2>Login</h2>
          <!--form to enter username and password to login-->
          <form action="<?php echo htmlspecialchars($_SERVER['PHP_SELF'])?>" method="post" id="login_form">
            <input type="hidden" name="rand1" value="<?php echo $rand ?>">
            <input type="text" name="username" placeholder="Username" required>
            <input type="password" name="password" placeholder="Password">
            <button type="submit" name="login">Login</button>
          </form>
          <?php echo isset($message) ? $message: null; ?>

        </div>
        <div class="innerItem">
          <h2>Users</h2>
        </div>

        <div class="innerItem">
          <h2>Add Media</h2>
        </div>
      </div>

      <div class="outerItem">
        <?php echo $_SESSION['is_logged_in'] ?>
      </div>
      <div class="outerItem">
        <?php
          //better not to use hard code
          for($i=0; $i<20; $i++){
            echo "<p>We will use it later.</p>";
          }
        ?>
      </div>
    </div>
    <div class="footer">
      <p>Copyrigt @ gunturi</p>
    </div>
  </body>
</html>
