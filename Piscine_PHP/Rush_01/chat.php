<!-- Стили для блока с сообщениями!-->
<style>
#messages
{
	width:300px;
	height:150px;
	overflow:auto;
	border:1px solid silver;
}
</style>
<!--Подключаем Jquery!-->
<script type="text/javascript" src="http://www.google.com/jsapi"></script>
<script type="text/javascript">
	//Загружаем библиотеку JQuery
	google.load("jquery", "1.3.2");
	google.load("jqueryui", "1.7.2");
	//Функция отправки сообщения
	function send()
	{
	//Считываем сообщение из поля ввода с id mess_to_add
	var mess=$("#mess_to_send").val();
	// Отсылаем паметры
		$.ajax({
				type: "POST",
				url: "add_mess.php",
				data:"mess="+mess,
				// Выводим то что вернул PHP
				success: function(html)
		{
		  //Если все успешно, загружаем сообщения
		  load_messes();
		  //Очищаем форму ввода сообщения
		  $("#mess_to_send").val('');
				}
		});
  }
  //Функция загрузки сообщений
  function load_messes()
  {
	$.ajax({
				type: "POST",
				url:  "load_messes.php",
				data: "req=ok",
				// Выводим то что вернул PHP
				success: function(html)
		{
		  //Очищаем форму ввода
		  $("#messages").empty();
		  //Выводим что вернул нам php
		  $("#messages").append(html);
		  //Прокручиваем блок вниз(если сообщений много)
		  $("#messages").scrollTop(90000);
				}
		});
  }
</script>
<table>
<tr>
<td>
<div id="messages">
</div>
</td>
</tr>
<tr>
<td>
<form action="javascript:send();">
<input type="text" id="mess_to_send">
<input type="button" value="Отправить">
</form>
</td>
</tr>
</table>
<script>
//При загрузке страницы подгружаем сообщения
load_messes();
//Ставим цикл на каждые три секунды
setInterval(load_messes,3000);
</script>
