<!DOCTYPE html>
<?php

//error reporting; can do specific errors with different builtin options
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

$title = "MyTitle";

include("./includes/header.php");

?>
<h1><?php echo $title; ?></h1>
<div>

  <?php

  $crafts = ["something", "else", "cool"];

  //array that has keys, so dictionary-like
  $mapThing = [
    'name' => 'Kevin',
    'age' => '32',
    'country' => 'USA',
  ];

  for ($i = 1; $i <= 10; $i++) {
    echo "<p>PARAGRAPH $i!</p>";
  }

  foreach ($crafts as $craft) {
    echo "<i>$craft</i> ";
  }

  foreach ($mapThing as $key => $value) {
    echo "<p><i>$key=$value</i></p>\n ";
  }

  //functions and "global passing"
  $secret = 123;
  function addWithSecret($val1, $val2) {
    global $secret;

    return $val1 + $val2 + $secret;
  }

  print addWithSecret(19, 20) . "<br/>";

  //php pointers done with &
  $val1 = 4;
  $val2 =& $val1;

  $val2 = 5;

  echo $val1;

  //unset variables to remove an existint vslot
  unset($val1);

  echo $val2. "<br/>";
  //error:  echo $val1;
  


  //class stuff:
  class Point {
    //property declarations, default values
    //need to declare their visibility
    public int $x = 0;
    public int $y = 0;

    //constructor:
    public function __construct(int $x, int $y) {
      //note: reference to attributes do not need the $, as they're already
      //being used to refer to a variable
      $this->x = $x;
      $this->y = $y;
    }

  }

  //constructor and referencing
  $p1 = new Point(1,2);

  echo $p1->x. ",". $p1->y. "<br/>";

  //copy member-deep for arrays? seems to be deprecated...
  $arr1 = array(10, 'B' => new Point(21, 53));
  $arr2 = $arr1;
  //not working:
  //$arr2 =* $arr1;

  echo '<br/>';
  var_dump($arr2);
  echo '<br/>';

  //cloning objects
  $p2 = clone $p1;
  $p2->x = 9;
  $p1->x = 89;

  var_dump($p1);
  var_dump($p2);
  echo '<br/>';


  //idea test: function to global to unset to use function
  $dummy = 'dumborghini';
  function dummyTest() {
    $dummy = 'uh oh?';

    echo "local dummy $dummy".'<br/>';
    global $dummy;

    echo "global dummy $dummy".'<br/>';

    unset($dummy);
    $dummy = 123;

    echo "unset reassign dummy $dummy".'<br/>';
  }

  dummyTest();

  echo "did it kill global dummy? no: $dummy".'<br/>';

  //checking some constants that define how php operates:
  echo "int size in bytes:". PHP_INT_SIZE. '<br/>';
  echo "int max:". PHP_INT_MAX. '<br/>';
  echo "PHP float things?:". PHP_FLOAT_DIG. '<br/>';
  echo "PI?:". M_PI. '<br/>';
  echo "error things all:". E_ALL. ', deprecated:' . E_DEPRECATED. '<br/>';
  echo "default path for file include:". DEFAULT_INCLUDE_PATH . '<br/>';

  //constants
  const MAX_BUFFER = 1024;
  define('OTHER_CONSTANT', 1);
  define('silly_name_constant', 1);

  //causes fatal error...
  //echo NON_EXISTING_CONSTANT;
  echo MAX_BUFFER;
  echo OTHER_CONSTANT;
  echo silly_name_constant;

  //does php have try? yes
  try {
    echo NOT_A_CONSTANT;
  } catch (Error $er) {
    $val = $er->getCode();
    echo "oops! $er<br/> $val";
  }

  //what's in globals? every global-context variable, including built-in
  //var_dump($GLOBALS);

  ?>




<?php include("./includes/footer.php"); ?>
