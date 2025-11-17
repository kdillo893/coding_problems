<?php

if ($_SERVER['REQUEST_METHOD'] == "POST") {
  echo "testing post...";

  $age = filter_input(INPUT_POST, 'age', FILTER_VALIDATE_INT);
  $ding = $_POST["name"];

  echo $age;
} else {
  echo "NOT POST!";
}

?>

hi
