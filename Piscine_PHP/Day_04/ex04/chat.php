<?php
date_default_timezone_set("Europe/Moscow");
session_start();
if ($_SESSION["loggued_on_user"] == NULL)
{
    header("Location: index.html");
    echo "ERROR\n";
}
if (file_exists('../private/chat'))
{
	$chat = unserialize(file_get_contents('../private/chat'));
	foreach ($chat as $elem)
		echo "[" . date('H:i', $elem["time"]) . "] <b>" . $elem["login"] . "</b>: " . $elem["msg"] . "<br />\n";
}
?>
