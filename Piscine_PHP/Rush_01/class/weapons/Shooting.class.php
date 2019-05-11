<?php
require_once ($_SERVER['DOCUMENT_ROOT'] . '/class/Ship.class.php');

trait Shooting{
    public function isInRange(Ship $enemy_ship)
    {
        $enemy_coordinates = $enemy_ship->getRectangle();	//	array( "top-left" => ["x" => ..., "y" => ...], "bottom-right" => ["x" => ..., "y" => ...] )
        if ($this->getOrientation() == "top"
                && $enemy_coordinates["top-left"]["x"]     <= $this->getCoordinates()["x"]
                && $enemy_coordinates["bottom-right"]["x"] >= $this->getCoordinates()["x"]
                && $enemy_coordinates["bottom-right"]["y"] >  $this->getCoordinates()["y"]
                && $enemy_coordinates["bottom-right"]["y"] -  $this->getCoordinates()["y"]  < $this->getLongRange()[1])
            return (TRUE);
        else if ($this->getOrientation() == "bottom"
                && $enemy_coordinates["top-left"]["x"]     <= $this->getCoordinates()["x"]
                && $enemy_coordinates["bottom-right"]["x"] >= $this->getCoordinates()["x"]
                && $enemy_coordinates["top-left"]["y"]     <  $this->getCoordinates()["y"]
                && abs($enemy_coordinates["left-top"]["y"] -  $this->getCoordinates()["y"]) < $this->getCoordinates()[1])
            return (TRUE);
        else if ($this->getOrientation() == "left"
                && $enemy_coordinates["top-left"]["y"]         >= $this->getCoordinates()["y"]
                && $enemy_coordinates["bottom-right"]["y"]     <= $this->getCoordinates()["y"]
                && $enemy_coordinates["bottom-right"]["x"]     <  $this->getCoordinates()["x"]
                && abs($enemy_coordinates["bottom-right"]["x"] -  $this->getCoordinates()["x"]) < $this->getCoordinates()[1])
            return (TRUE);
        else if ($this->getOrientation() == "right"
                && $enemy_coordinates["top-left"]["y"]     >= $this->getCoordinates()["y"]
                && $enemy_coordinates["bottom-right"]["y"] <= $this->getCoordinates()["y"]
                && $enemy_coordinates["top-left"]["x"]     >  $this->getCoordinates()["x"]
                && $enemy_coordinates["top-left"]["x"]     -  $this->getCoordinates()["x"] < $this->getLongRange()[1])
            return (TRUE);
        return (FALSE);
    }


}