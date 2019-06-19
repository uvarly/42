<?php
//Подключаемся к БД
$mysqli = new mysqli("localhost:3306", "root", "133113", "rush01");
//Выбираем все сообщения
if ($res = $mysqli->query("SELECT * FROM `messages` ORDER BY `id` ")){
	//Выводим все сообщения на экран
	while ($d = $res->fetch_array())
	{
		echo "<b><font color='orange'>".$d['login'].": </font></b>".$d['message']."<br>";
	}
}
?>
