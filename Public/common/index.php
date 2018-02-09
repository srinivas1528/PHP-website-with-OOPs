<?php
try {
  require_once '../../includes/initialize.inc';
} catch (Exception $e) {
$message = $e->getMessage();
}
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
    <h2>It's a Good Time</h2>
    <hr>
    <div class="wrapper">
      <div class="container">
        <div class="innerItem">
          <h2>Logout</h2>

        </div>
        <div class="innerItem">
          <h2>Users</h2>
        </div>
        <div class="innerItem">
          <h2>Add Media</h2>
        </div>

      </div>

      <div class="outerItem">
        <?php
        include_once('..'.DS.'layouts'.DS.'photo_list.inc');
        ?>
      </div>
      <div class="outerItem">
        <?php
        // Its better not to hard code the value to 20..
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
