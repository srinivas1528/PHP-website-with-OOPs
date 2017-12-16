<?php
try {
  require_once '../../includes/initialize.inc';
} catch (Exception $e) {
$message = $e->getMessage();
}
?>

<?php
include_once('..'.DS.'layouts'.DS.'admin_header.inc');
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Index Page</title>

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
          <h2>Logout</h2>
          <form action="<?php echo htmlspecialchars($_SERVER['PHP_SELF'])?>" method="post" id="logout_form">
            <input type="hidden" name="rand1" value="<?php echo $rand ?>">
            <button type="submit" name="logout">Logout</button>
          </form>
        </div>
        <div class="innerItem">
          <h2>Users</h2>
          <?php
          // user form is added to user_form.inc present in layouts directory
          include_once('..'.DS.'layouts'.DS.'user_form.inc');
          echo isset($message) ? $message: null; ?>
        </div>
        <div class="innerItem">
          <h2>Add Media</h2>
          <?php
          // media form is added to media_form.inc present in layouts directory
          include_once('..'.DS.'layouts'.DS.'media_form.inc');
          echo isset($file_message) ? $file_message : null; ?>
        </div>
      </div>
      <div class="outerItem">
        <?php
        //if delete_message is set then delete the session variable
        echo isset($_SESSION['delete_message']) ? $_SESSION['delete_message'] : null;

        // program to display all photos is added to photo_list.inc present in layouts directory
        include_once('..'.DS.'layouts'.DS.'photo_list.inc');
        ?>
      </div>
      <div class="outerItem">
        <?php
        foreach ($_SERVER as $key => $value) {
          echo $key.': '.$value.'<br>';
          }
        ?>
      </div>
    </div>
    <div class="footer">
      <p>Copyrigt @ gunturi</p>
    </div>
  </body>
</html>
