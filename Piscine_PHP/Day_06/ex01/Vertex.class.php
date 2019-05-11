<?php
require_once 'Color.class.php';
class Vertex
{
    private $_x = 0.0;
    private $_y = 0.0;
    private $_z = 0.0;
    private $_w = 1.0;
    private $_color;
    public static $verbose = FALSE;
    
    public function __construct($array)
    {
        $this->_x = floatval($array["x"]);
        $this->_y = floatval($array["y"]);
        $this->_z = floatval($array["z"]);
        if (isset($array["w"]))
            $this->_w = floatval($array["w"]);
        if (isset($array["color"]))
            $this->_color = $array["color"];
        else
            $this->_color = new Color(array(
                "red" => 255,
                "green" => 255,
                "blue" => 255
            ));
        if (Self::$verbose)
            printf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, %s ) constructed" . PHP_EOL, $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
    }
    
    public function __destruct()
    {
        if (Self::$verbose)
            printf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, %s ) destructed" . PHP_EOL, $this->_x, $this->_y, $this->_z, $this->_w, $this->_color);
    }
    
    public function __toString()
    {
        if (Self::$verbose)
            return (sprintf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f, %s )", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color));
        else
            return (sprintf("Vertex( x: %0.2f, y: %0.2f, z:%0.2f, w:%0.2f )", $this->_x, $this->_y, $this->_z, $this->_w));
    }
    
    public function __get($property)
    {
        if (property_exists($this, $property))
            return ($this->$property);
    }

    public function __set($property, $value)
    {
        if (property_exists($this, $property))
            $this->$property += $value;
    }

    public static function doc()
    {
        printf(PHP_EOL);
        $file = file_get_contents('Vertex.doc.txt');
        printf($file);
    }
}
?>
