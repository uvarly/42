<?php
session_start();
require_once ('class/Page.class.php');
$page = new Page();
$page->add_css('/css/all_style.css');
$page->add_css('/css/ship_style.css');
$page->add_css('/css/map_style.css');
$page->add_css('/css/player_style.css');
$page->add_js("https://code.jquery.com/jquery-3.4.1.min.js");
?>
<html>
<head>
    <title>Warhammer 40000 - Awesome Battleships Battles</title>
    <?= $page->getCss();?>
    <?= $page->getJs();?>
</head>
<body>
<div class="content">