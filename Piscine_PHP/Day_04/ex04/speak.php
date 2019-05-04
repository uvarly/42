<?php
session_start();
if ($_SESSION["loggued_on_user"] == NULL)
	echo "ERROR\n";
else
{
	if ($_POST["msg"])
	{
		if (file_exists("../private/chat"))
		{
			$chat = unserialize(file_get_contents("../private/chat"));
			$flow = fopen('../private/chat', "w");
			flock($flow, LOCK_EX);
		}
		$message["time"] = time();
		$message["login"] = $_SESSION["loggued_on_user"];
		$message["msg"] = $_POST["msg"];
		$chat[] = $message;
		file_put_contents('../private/chat', serialize($chat));
		if ($flow != NULL)
		fclose($flow);
	}
	?>
	<html>
	<head>
		<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
	</head>
	<body>
		<form action="speak.php" method="POST">
		<input type="text" name="msg" value=""/><input type="submit" name="submit" value="Send"/>
		</form>
	</body>
<?php
}
?>