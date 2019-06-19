<?php
//Проверям есть ли переменные на добавление
if(isset($_POST['mess']) && $_POST['mess']!="" && $_POST['mess']!=" ")
{
  //Стартуем сессию для записи логина пользователя
  session_start();
  //Принимаем переменную сообщения
  $mess=$_POST['mess'];
  //Переменная с логином пользователя
  $login=$_SESSION['login'];
  //Подключаемся к базе
  $mysqli = new mysqli("localhost:3306", "root", "133113", "rush01");
  //Добавляем все в таблицу
  $res = $mysqli->query("INSERT INTO `messages` (`login`,`message`) VALUES ('$login','$mess') ");
}
?>
