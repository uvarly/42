<?php
	session_start();
	if ($_GET["submit"] == "Login") {
		$log = strtolower($_GET["login"]);
		$mysqli = new mysqli("localhost:3306", "root", "133113", "rush01");
		$sql = "select * from game_users where login=\"".$log."\";";
		if ($row = $mysqli->query($sql)){
			$userinfo = $row->fetch_assoc();
			if ($userinfo["passwd"] == hash('sha512', $_GET["passwd"])) {
				$_SESSION["login"] = $_GET["login"];
				$_SESSION["passwd"] = $userinfo["passwd"];
				$_SESSION["faction"] = $userinfo["faction"];
				unset($_GET["submit"]);
				unset($_GET["login"]);
				unset($_GET["passwd"]);
				$mysqli->close();
				$_SESSION['message'] = "Приветствуем, ". $_SESSION["login"] . "!)";
				header("Location: http://localhost:8100/index.php");
				exit ;
			}
		}
		$mysqli->close();
		$_SESSION['message'] = "Неправильное имя пользователя или пароль! :(";
		header("Location: http://localhost:8100/index.php");
		exit ;
	}
	else if ($_GET["submit"] == "Logout") {
		session_destroy();
		header("Location: http://localhost:8100/index.php");
		exit ;
	}
?>
