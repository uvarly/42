<?php
	date_default_timezone_set('europe/moscow');
	if ($_POST["submit"] == "Register")
	{
		$log = strtolower($_POST["login"]);
		$mysqli = new mysqli("localhost:3306", "root", "133113", "rush01");
		$sql = "select id from game_users where login=\"".$log."\";";
		if ($mysqli->query($sql)->num_rows != 0){
			$mysqli->close();
			$_SESSION['message'] = "Пользователь с таким именем уже существует! :(";
			header("Location: http://localhost:8100/index.php");
			exit();
		}
		$sql = "INSERT INTO game_users (`login`, `passwd`, `faction`, `creation_date`) VALUES (\"";
		$sql .= $log . "\", \"";
		$sql .= hash('sha512', $_POST["passwd"]) . "\", \"";
		$sql .= $_POST["faction"] . "\", \"";
		$sql .= date("Y-m-d H:i:s");
		$sql .= "\");";
		if ($mysqli->query($sql) === TRUE){
			$mysqli->close();
			$_SESSION['message'] = "Акаунт успешно создан!";
			header("Location: http://localhost:8100/index.php");
		}
		else {
			echo "Error: ". $mysqli->error;
			$mysqli->close();
		}
		exit();
	}
	else {
		$_SESSION['message'] = "Неправильное имя пользователя или пароль! :(";
		header("Location: http://localhost:8100/index.php");
		exit();
	}
?>
