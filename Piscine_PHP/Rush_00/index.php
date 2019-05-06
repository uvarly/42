<?php
include("sources/auth.php");
session_start();
if ($_POST["login"] != NULL
		&& $_POST["passwd"] != NULL
		&& $_POST["submit"] == "Login"
		&& auth($_POST["login"], $_POST["passwd"]))
	$_SESSION["logged_user"] = $_POST["login"];
?>
<!DOCTYPE html>
<html lang="ru">
<head>
	<title>Meme Shop</title>
	<link href="styles.css" type="text/css" rel="stylesheet">
</head>
<body>
	<header>
		<div class="logo">
			<h1>Meme Store</h1>
			<p>Beautifull shop with beautifull memes</p>
		</div>
		<?php
		if ($_SESSION["logged_user"] == NULL)
		{
		?>
		<form class="form" method="POST" action=".">
			Username: <input type="text" name="login" />
			<br/>
			Password: <input type="password" name="passwd" />
			<br/>
			<input style="float: right; margin: 10px; " type="submit" name="submit" value="Login">
			<a href="signup.php">Create account</a>
			<br />
		</form>
		<?php
		}
		else
		{
			echo "Hello, " . $_SESSION["logged_user"] . "\n";
			echo "<a href=\"sources/logout.php\">Logout</a>\n";
			if ($_SESSION["logged_user"] == "root")
				echo "<a href=\"development.php\">Development</a>\n";
		}
		?>
	</header>
	<br/>
	<div class="category">
		<form action="." method="get">
		<?php
			// $fd = fopen("categories.csv", "r"); 				(!!!)
			// $file = array();
			// while (!feof($fd))
			// 	$file[] = trim(fgets($fd));
			// foreach ($file as $f)
			// {
			// 	echo "<input type='submit' name='category' value='$f'><br />";
			// }
		?>
		</form>
	</div>
	<div class="content">
		<!-- <table class="element">
			<tr>
				<td rowspan="2"><img class="good-img" src="https://upload.wikimedia.org/wikipedia/en/6/63/Feels_good_man.jpg"></td>
				<th>Pepe</th>
			</tr>
			<tr>
				<th>Новый смешной мем про лягушонка Pepe! Рассмеши своих друзей!</th>
			</tr>
		</table> -->
		<div class="element">
			<img class="good-img" src="https://upload.wikimedia.org/wikipedia/en/6/63/Feels_good_man.jpg">
			<div class="name-description">
				<p style="margin-top: -200px">blasdasd</p>
			</div>
		</div>
	</div>
	<footer><a href="development.html"></a></footer>
</body>
</html>
