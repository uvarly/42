<?php
	$mysqli = new mysqli("localhost:3306", "root", "133113");
	if (!$mysqli) {
		die("Connection failed: " . $mysqli->connect_error);
	}
	$sql = "CREATE DATABASE `rush01`;";
	if ($mysqli->query($sql) === TRUE){
		echo "Database successfully created";
	}
	else {
		echo 'Error: '. $mysqli->error;
	}
	$mysqli->select_db("rush01");
	$sql = "CREATE TABLE game_users (";
	$sql .= " `id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,";
	$sql .= " `login` VARCHAR(20) NOT NULL,";
	$sql .= " `passwd` VARCHAR(128) NOT NULL,";
	$sql .= " `faction` VARCHAR(20) NOT NULL,";
	$sql .= " `creation_date` DATETIME NOT NULL,";
	$sql .= " `gameinfo` VARCHAR(20000) NOT NULL);";
	if ($mysqli->query($sql) === TRUE){?>
		<p>"Login table successfully created";</p>
	<?}
	else {?>
		<p> <?echo "Error: ". $mysqli->error; ?></p>
	<?}
	$sql = "CREATE TABLE  `rooms` (";
	$sql .= " `id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,";
	$sql .= " `login1` VARCHAR(20) NOT NULL,";
	$sql .= " `login2` VARCHAR(20) NOT NULL,";
	$sql .= " `login3` VARCHAR(20) NOT NULL,";
	$sql .= " `login4` VARCHAR(20) NOT NULL);";
	if ($mysqli->query($sql) === TRUE){?>
		<p>"Rooms table successfully created";</p>
	<?}
	else {?>
		<p> <?echo "Error: ". $mysqli->error; ?></p>
	<?}
	$sql = "CREATE TABLE  `chat` (";
	$sql .= " `id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY,";
	$sql .= " `login` VARCHAR(20) NOT NULL,";
	$sql .= "`message` VARCHAR( 1000 ) NOT NULL);";
	if ($mysqli->query($sql) === TRUE){?>
		<p>  "Chat table successfully created";?></p>
	<?}
	else {?>
		<p> <?echo "Error: ". $mysqli->error; ?></p>
	<?}
	$mysqli->close();
