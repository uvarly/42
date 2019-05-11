<?php
class Color
{
    public $red;
    public $green;
    public $blue;
    public static $verbose = False;
    
    public function __construct(array $color)
    {
        if (isset($color["red"], $color["green"], $color["blue"]))
        {
            $this->red   = intval($color["red"]);
            $this->green = intval($color["green"]);
            $this->blue  = intval($color["blue"]);
        }
        else if (isset($color["rgb"]))
        {
            $this->red   = (intval($color["rgb"]) >> 16) & 0xFF;
            $this->green = (intval($color["rgb"]) >> 8) & 0xFF;
            $this->blue  = intval($color["rgb"]) & 0xFF;
        }
        if (Self::$verbose)
            printf("Color( red: %3d, green: %3d, blue: %3d ) constructed." . PHP_EOL, $this->red, $this->green, $this->blue);
    }
    
    public function __destruct()
    {
        if (Self::$verbose)
            printf("Color( red: %3d, green: %3d, blue: %3d ) destructed." . PHP_EOL, $this->red, $this->green, $this->blue);
    }
    
    public function add($color)
    {
        return (new Color(array(
            "red" => $this->red + $color->red,
            "green" => $this->green + $color->green,
            "blue" => $this->blue + $color->blue
        )));
    }
    
    public function sub($color)
    {
        return (new Color(array(
            "red" => $this->red - $color->red,
            "green" => $this->green - $color->green,
            "blue" => $this->blue - $color->blue
        )));
    }
    
    public function mult($multiplier)
    {
        return (new Color(array(
            "red" => $this->red * $multiplier,
            "green" => $this->green * $multiplier,
            "blue" => $this->blue * $multiplier
        )));
    }
    
    public function __toString()
    {
        return (sprintf("Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green, $this->blue));
    }
    
    public static function doc()
    {
        printf(PHP_EOL);
        $file = file_get_contents("Color.doc.txt");
        printf($file);
    }
}
?>
