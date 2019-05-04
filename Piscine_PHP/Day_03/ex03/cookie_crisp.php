<?php
switch($_GET["action"])
{
	case("set"):
		setcookie($_GET["name"], $_GET["value"], time() + (86400 * 365));
		break;
	case("get"):
		echo $_COOKIE[$_GET["name"]] . "\n";
		break;
	case("del"):
		setcookie($_GET["name"], NULL, -1);
		break;
}
?>