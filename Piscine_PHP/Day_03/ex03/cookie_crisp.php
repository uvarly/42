<?php
switch($_GET["action"])
{
	case("set"):
		setcookie($_GET["name"], $_GET["value"], time() + (86400 * 365));
		break;
	case("get"):
		if ($_COOKIE[$_GET["name"]])
			echo $_COOKIE[$_GET["name"]] . "\n";
		break;
	case("del"):
		setcookie($_GET["name"], NULL, time());
		break;
}
?>
