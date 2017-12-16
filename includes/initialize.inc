<?php
//in Initialize.inc we define all the paths and files to be included
// DS is defined as DIRECTORY_SEPARATOR
defined('DS') ? null : define('DS', DIRECTORY_SEPARATOR);

//defining project root
defined('P_ROOT') ? null :
define('P_ROOT', dirname(dirname(__FILE__)));
//__FILE__ is the current file, and dirname() gives its path
//I have replaced the following line by the one in line 8
//define('P_ROOT', DS.'Users'.DS.'muhammadaurangzeb'.DS.'Sites'.DS.'classfall2017project');

//defining LIB_PATH
defined('LIB_PATH') ? null :
define('LIB_PATH', P_ROOT.DS.'includes');

//defining Image Path
defined('IMG_PATH') ? null :
define('IMG_PATH', P_ROOT.DS.'Public'.DS.'images');

//defining Admin Path
defined('ADMIN_PATH') ? null :
define('ADMIN_PATH', P_ROOT.DS.'Public'.DS.'admin'.DS.'index.php');

//session_start();//it turns the session on I will shift this line into clas.session.onc file
//requesting files to be included
require_once LIB_PATH.DS.'pdo_connection.inc';
require_once LIB_PATH.DS.'functions.inc';
require_once LIB_PATH.DS.'class.session.inc';
require_once LIB_PATH.DS.'class.user.inc';
require_once LIB_PATH.DS.'class.photo.inc';
?>
