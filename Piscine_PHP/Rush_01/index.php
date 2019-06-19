<?php
require_once ($_SERVER['DOCUMENT_ROOT'] . '/class/FactoryObj.class.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/class/Ship.class.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/class/Player.class.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/class/weapons/BasicRailgun.class.php');
require_once ($_SERVER['DOCUMENT_ROOT'] . '/class/Obstacle.class.php');

include ('views/template/header.php');
if (isset($_SESSION["login"])){
	if ($_POST['game'] == 'new' || (!$_SESSION['game'])) {
		$map = new FactoryObj(0, 0, 150, 100);
		$ship1 = new Ship('ship1', ['x' => 0, 'y' => 0], ['x' => 2, 'y' => 1], [
			'speed' => 1,
			'hull_points' => 10,
			'PP' => 3,
			'handling' => 1,
			'shield' => 1,
			'weapns' => []
		]);
		$ship2 = new Ship('ship2', ['x' => 10, 'y' => 10], ['x' => 13, 'y' => 15], [
			'speed' => 1,
			'hull_points' => 10,
			'PP' => 3,
			'handling' => 1,
			'shield' => 1,
			'weapns' => []
		]);
		$player1 = new Player(array('state' => 'active', 'name' => $_SESSION["login"], 'icon' => '/images/Players/p1.png'));
		$ship1->setWeapons([new BasicRailgun(5, $ship1)]);
		$player1->addShip($ship1);
		$ship2->setWeapons([new BasicRailgun(5, $ship2)]);
		$player2 = new Player(array('state' => 'wait', 'name' => 'player1', 'icon' => '/images/Players/p1.png'));
		$player2->addShip($ship2);

		$obst1 = new Obstacle('obs1', ['x' => 4, 'y' => 10], ['x' => 12, 'y' => 12]);
		$obst2 = new Obstacle('obs1', ['x' => 40, 'y' => 50], ['x' => 44, 'y' => 52]);

		$map->addObj($ship1);
		$map->addObj($ship2);
		$map->addObj($obst1);
		$map->addObj($obst2);

		$_SESSION['map'] = serialize($map);
		$_SESSION['player'] = serialize($player1);
		$_SESSION['game'] = true;
		$_SESSION['other'] = serialize($player2);
	}
	else
	{
		if (is_string($_SESSION['map']))
			$map = unserialize($_SESSION['map']);
		if (is_string($_SESSION['player']))
			$player1 = unserialize($_SESSION['player']);
		if (is_string($_SESSION['other']))
			$player2 = unserialize($_SESSION['other']);
	}
	if (isset($map))
		$map->drawAll();
	?><form method='post' action='index.php'>
	<input type='submit' name='game' value='new'/>
	</form>
	<? if ($player1 instanceof Player) {?>
		<form method='post' action='/actions/player.php'>
		<? $ship = $player1->getShips()[0];
		if ($ship instanceof Ship) {?>
			<input type='hidden' name='ship_id' value='<?$ship->getId()?>' />
			<input type='hidden' name='move_points' value='1' />
			<input type='hidden' name='attack_points' value='1' />
			<input type='hidden' name='repair_points' value='1' />
		<?
			switch ($player1->getState()) {
				case "active":?>
					<input type='submit' name='action' value='move'/>
					<? break;
				case "move":?>
					<input type='submit' name='action' value='finish'/>
					<? break;
				case "finish": ?>
					<input type='submit' name='action' value='active'/>
					<? break;
			}
		}?>
		</form>
	<?}
	$player1->draw();
}
include ('views/template/footer.php');
?>
