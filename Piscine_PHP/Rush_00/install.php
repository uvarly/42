<?php
function install_db()
{
	if (!file_exists("database"))
		mkdir("database", 0755);
	if (!file_exists("database/categories.csv"))
		file_put_contents("database/categories.csv", NULL);
	if (!file_exists("database/goods.csv"))
		file_put_contents("database/goods.csv", NULL);
	if (!file_exists("database/passwd"))
		file_put_contents("database/passwd", NULL);
}
?>
