<?php
/**
 * A wrapper of PDO for the desired interfaces
 */
class MyPDO extends PDO{
  //constructor of MyPDO class
  function __construct($my_dsn, $my_admin, $my_password){

    // refers to the constructor of PDO class
    parent::__construct($my_dsn, $my_admin, $my_password);
  }

  //Member function to check if Query is successful
  public function exec($sql){
    file_put_contents("mylog.txt", $sql);
    $m = parent::exec($sql);
    if ($m) {
      return $m;
    }else{
      throw new Exception("Query was not successful.");
    }

  }

  //Member function to check if Query is successful
  public function query($sql){
      file_put_contents("mylog.txt", $sql);
    $m = parent::query($sql);

    if($m->rowCount()){
      return $m;
    }else{
      throw new Exception("Query was not successful: ".$m->errorCode() );
    }
  }

  // query1 uses the same interface as PDO function
  public function query1($sql){
    return parent::query($sql);
  }
}

//Create data source name(DSN) string with MySql address, Database name and port number
$dsn = 'mysql:host=127.0.0.1;dbname=classuni';
//creating object of MyPDO class
$db = new MyPDO($dsn, 'vivek', '123');
?>
