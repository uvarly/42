<?php
session_start();
require_once ('class/Page.class.php');
$page = new Page();
$page->add_css('/css/all_style.css');
$page->add_css('/css/ship_style.css');
$page->add_css('/css/map_style.css');
$page->add_css('/css/player_style.css');
$page->add_css('/css/style.css');
$page->add_js("https://code.jquery.com/jquery-3.4.1.min.js");
?>
<html>
	<head>
		<title>Warhammer 40000 - Awesome Battleships Battles</title>
		<?= $page->getCss();?>
		<?= $page->getJs();?>
	</head>
		<? if(isset($_SESSION['message'])){ ?>
			<body onload="alert('<?php echo($_SESSION['message']);?>')" ><?php unset($_SESSION['message']);  ?>
		<? }else{?>
			<body>
		<?}?>
				<header class="box" style="background-color: #4CAF50">
					<div class="dropdown">
						<form style="display: block; margin: 0 0;" action="index.php" method="get">
							<input class="dropbtn" style="background-color: inherit;" type="submit" name="" value="Home"/>
						</form>
					</div>
					<p style="color: white; float: right"> <?php echo$_GET["cat"];?></p>
					<div style="align-self: flex-end;">
						<?php if(!isset($_SESSION["login"])){ ?>
						<div class="dropdown">
							<button class="dropbtn" style="margin: 0 0;">Login</button>
							<div class="dropdown-content">
								<form action="actions/login.php" method="get" style="margin: 0.5em 1em; min-width: 12.25em;">
									Username:<input name="login" value="" required/><br />
									Password: <input type="password" name="passwd" value="" required/><br />
									<input type="submit" name="submit" value="Login"/>
								</form>
							</div>
						</div>
						<div class="dropdown">
							<button class="dropbtn" style="margin: 0 0;">Register</button>
							<div style="right: 0;" class="dropdown-content" >
								<form action="actions/create.php" method="post" style="margin: 0.5em 1em; min-width: 12.25em;">
									Username:<input name="login" value="" required/>
									Password: <input type="password" name="passwd" value="" required/>
									Faction:<br />
									<select name="faction">
										<option value="Empire">Empire</option>
										<option value="Rebel">Rebel</option>
										<option value="Jedi">Jedi</option>
										<option value="Sith">Sith</option>
									</select>
									<input type="submit" name="submit" value="Register"/>
								</form>
							</div>
						</div>
					<?php }else{ ?>
						<div class="dropdown">
							<form style="display: block; margin: 0 0;" action="actions/login.php" method="get">
								<input class="dropbtn" style="background-color: inherit;" type="submit" name="submit" value="Logout"/>
							</form>
						</div>
						<div class="dropdown">
							<button class="dropbtn" style="margin: 0 0;">Acc info</button>
							<div style="right: 0;" class="dropdown-content" >
								<form action="modif.php" method="post" style="margin: 0.5em 1em; min-width: 12.25em;">
									Login:<input name="login" value="<?php echo$_SESSION["login"] ?>"/><br />
									Faction:<br />
									<select name="faction">
										<option <?php if ($_SESSION["faction"] == "Empire"){?> selected <?}?> value="Empire">Empire</option>
										<option <?php if ($_SESSION["faction"] == "Rebel"){?> selected <?}?> value="Rebel">Rebel</option>
										<option <?php if ($_SESSION["faction"] == "Jedi"){?> selected <?}?> value="Jedi">Jedi</option>
										<option <?php if ($_SESSION["faction"] == "Sith"){?> selected <?}?> value="Sith">Sith</option>
									</select><br />
									New pass: <input type="password" name="npasswd" value=""/><br />
									Old pass: <input type="password" name="opasswd" placeholder="Required" required/><br />
									<input type="submit" name="submit" value="Change"/>
								</form>
							</div>
						</div>
					<?php } ?>
					</div>
				</header>
				<div class="goodsbox">
					<div class="content">
