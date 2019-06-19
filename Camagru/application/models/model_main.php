<?php

class Model_Main extends Model
{
    // public $data;

    public function __construct()
    {
    }

    public function get_data()
    {
        $pdo = new PDO('mysql:host=172.17.0.3;dbname=camagru_db', 'root', 'root');
        $data = $pdo->query('SELECT * FROM `Users`');
        return ($data);
    }
}