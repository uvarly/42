<?php
session_start();
require_once ($_SERVER['DOCUMENT_ROOT'] . '/class/Ship.class.php');
$action = $_POST['action'];
$ship_id = $_POST['id'];
$player = unserialize($_SESSION['player']);
$factory = unserialize($_SESSION['map']);
if ($player->getState()) {
    switch ($action) {
        case "fire":
            $ship = $factory->getById($ship_id);
            if ($ship instanceof Ship)
                $ship->attack($factory, intval($_POST['num']));
            break;
        case "move":
            $ship = $factory->getById($ship_id);
            $ship->move(intval($_POST['num']));
            break;
        case "repair":
            $ship = $factory->getById($ship_id);
            $ship->repair(intval($_POST['num']));
            break;
    }
}