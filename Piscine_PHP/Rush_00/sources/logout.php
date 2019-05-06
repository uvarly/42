<?php
session_start();
$_SESSION["logged_user"] = NULL;
header("Location: ../index.php");
?>
