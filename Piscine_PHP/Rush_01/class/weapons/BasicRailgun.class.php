<?php
require_once ($_SERVER['DOCUMENT_ROOT'] . '/class/Weapon.class.php');
include("Shooting.class.php");
class BasicRailgun extends Weapon	//	название временное и подлежит изменению в будущем
{
    public function __construct($charges, $host_ship)
    {
        $this->setCharges($charges);
        $this->setCoordinates($host_ship);
        $this->setOrientation($host_ship->getDirection());
        $this->setShortRange([1, 30]);
        $this->setMiddleRange([31, 60]);
        $this->setLongRange([61, 90]);
        $this->setEffectZone("srtaight_line");
    }
    use Shooting;
    public function setCoordinates(Ship $host_ship)
    {
        $rectangle = $host_ship->getRectangle();
        $size = $host_ship->getSize();
        if ($this->getOrientation() == "top")
            $this->coordinates = ["x" => $rectangle["top-left"]["x"] + $size["x"] / 2,
                "y" => $rectangle["top-left"]["y"]];
        else if ($this->getOrientation() == "bottom")
            $this->coordinates = ["x" => $rectangle["bottom-right"]["x"] - $size["x"] / 2,
                "y" => $rectangle["bottom-right"]["y"]];
        else if ($this->getOrientation() == "left")
            $this->coordinates = ["x" => $rectangle["top-left"]["x"],
                "y" => $rectangle["bottom-right"]["y"] + $size["y"] / 2];
        else if ($this->getOrientation() == "right")
            $this->coordinates = ["x" => $rectangle["bottom-right"]["x"],
                "y" => $rectangle["top-left"]["y"] - $size["y"] / 2];
    }
}