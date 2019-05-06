<?php
session_start();
function is_moderator($user)
{
	$array = unserialize(file_get_contents("database/moderators"));
	for ($i = 0; $i < count($array); $i++)
	{
		if ($array[$i]["login"] === $user)
			return (true);
	}
}
if ($_SESSION["logged_user"] != "root" && !is_moderator($_SESSION["logged_user"]))
	header("Location: index.php");
?>
<html><body>
	<form method="GET" action="development.php">
		<input type="submit" name="action" value="ADD_USER" />
		<br />
		<input type="submit" name="action" value="REMOVE_USER" />
		<br />
		<input type="submit" name="action" value="ADD_CATEGORY" />
		<br />
		<input type="submit" name="action" value="REMOVE_CATEGORY" />
		<br />
		<input type="submit" name="action" value="ADD_ITEM" />
		<br />
		<input type="submit" name="action" value="REMOVE_ITEM" />
		<br />
<?php
if ($_SESSION["logged_user"] == "root")
{
?>
		<input type="submit" name="action" value="ADD_MODERATOR" />
		<br />
		<input type="submit" name="action" value="REMOVE_MODERATOR" />
		<br />
<?php
}
?>
	</form>
<?php
if ($_GET["action"] == "ADD_USER")
{
?>
	<form method="POST" action="create_user.php">
		User to add: <input type="text" name="login" value="" />
		<br />
		Password: <input type="text" name="passwd" value="" />
		<br />
		<input type="submit" name="submit" value="OK" />
	</form>
<?php
}
else if ($_GET["action"] == "REMOVE_USER")
{
?>
<form method="POST" action="remove_user.php">
	User to remove: <input type="text" name="login" value="" />
	<br />
	<input type="submit" name="submit" value="OK" />
</form>
<?php
} else if ($_GET["action"] == "ADD_CATEGORY")
{
?>
<form method="POST" action="categories.php">
	Category to add: <input type="text" name="category_add" value="" />
	<br />
	<input type="submit" name="submit" value="OK" />
</form>
<?php
} else if ($_GET["action"] == "REMOVE_CATEGORY")
{
?>
<form method="POST" action="categories.php">
	Category to remove: <input type="text" name="category_remove" value="" />
	<br />
	<input type="submit" name="submit" value="OK" />
</form>
<?php
} else if ($_GET["action"] == "ADD_ITEM")
{
?>
<form method="POST" action="items.php">
	Item to add: <input type="text" name="item" value="" />
	<br />
	<input type="submit" name="submit" value="OK" />
</form>
<?php
} else if ($_GET["action"] == "REMOVE_ITEM")
{
?>
<form method="POST" action="items.php">
	Item to remove: <input type="text" name="item" value="" />
	<br />
	<input type="submit" name="submit" value="OK" />
</form>
<?php
} else if ($_SESSION["logged_user"] == "root" && $_GET["action"] == "ADD_MODERATOR")
{
?>
<form method="POST" action="moderators.php">
	Moderator to add: <input type="text" name="add_moderator" value="" />
	<br />
	Password: <input type="text" name="passwd" value="" />
	<br />
	<input type="submit" name="submit" value="OK" />
</form>
<?php
} else if ($_SESSION["logged_user"] == "root" && $_GET["action"] == "REMOVE_MODERATOR")
{
?>
<form method="POST" action="moderators.php">
	Moderator to remove: <input type="text" name="remove_moderator" value="" />
	<br />
	<input type="submit" name="submit" value="OK" />
</form>
<?php
}
?>
</body></html>
