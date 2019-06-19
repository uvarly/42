<?php

require_once 'database.php';

try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASS);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $pdo->exec('CREATE DATABASE IF NOT EXISTS camagru_db');
} catch (Exception $exc) {
    die ("Exception caught: " . $exc->getMessage());
}

try {
    $pdo->exec('CREATE TABLE IF NOT EXISTS `Users`
    (
        `ID` INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
        `Login` VARCHAR(16) NOT NULL,
        `Password` VARCHAR(32) NOT NULL,
        `Email` VARCHAR(32) NOT NULL
    )');
} catch (Exception $exc) {
    die ("Exception caught: " . $exc->getMessage());
}

try {
    $pdo->exec('INSERT INTO `Users` (`ID`, `Login`, `Password`, `Email`)
                VALUES (NULL, "admin", "qwerty", "admin@21-school.ru"),(NULL, "pepe", "kek", "pepe@21-school.ru"),(NULL, "dio", "brando", "dio@21-school.ru")
                WHERE NOT EXISTS (SELECT * FROM `Users` WHERE `ID` < 4 )');
} catch (Exception $exc) {
    die ("Exception caught: " . $exc->getMessage());
}