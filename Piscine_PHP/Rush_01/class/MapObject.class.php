<?php

require_once($_SERVER['DOCUMENT_ROOT'] . '/class/IDrawable.class.php');

abstract class MapObject implements IDrawable
{
    private $_id;
    private $_rectangle;    //	= array(  "top-left" => ["x" => ..., "y" => ...],
                            //            "bottom-right" => ["x" => ..., "y" => ...] )

    private $_size;         //  = array(  "x" => ...,
                            //            "y" => ... )

    private $_name;
    private static $_obj_count = 0;

    /**
     * @var array
     */
    private $_pos;



    public function __construct()
    {
        $this->_id = ++self::$_obj_count;
    }

    /**
     * @return int
     */
    public function getId()
    {
        return $this->_id;
    }


    /**
     * @param int $id
     */
    public function setId($id)
    {
        $this->_id = $id;
    }

    /**
     * @return array
     */
    public function getRectangle()
    {
        return $this->_rectangle;
    }

    /**
     * @param array $top_left, $bottom_right
     */
    public function setRectangle($top_left, $bottom_right)
    {
        $top_left['x'] = (int)$top_left['x'];
        $bottom_right['x'] = (int)$bottom_right['x'];
        $top_left['y'] = (int)$top_left['y'];
        $bottom_right['y'] = (int)$bottom_right['y'];

        $this->_size = [(int)($bottom_right["x"] - $top_left["x"]), (int)($bottom_right["y"] - $top_left["y"])];
        $this->_pos = [(int)($top_left["x"] + $this->_size[0] / 2), (int)($top_left["y"] + $this->_size[1] / 2)];
        $this->_rectangle = ["top-left" => $top_left,
                             "bottom-right" => $bottom_right];
    }

    /**
     * @return array
     */
    public function getSize()
    {
        return $this->_size;
    }

    /**
     * @param array $size
     */
    public function setSize($size)
    {
        $size[0] = intval($size[0]);
        $size[1] = intval($size[1]);
        $this->_rectangle = [
            'top-left' => ['x' => intval($this->_pos[0] - $size[0] / 2), 'y'=>intval($this->_pos[1] - $size[1] / 2)],
            'bottom-right' => ['x' => intval($this->_pos[0] + $size[0] / 2), 'y'=>intval($this->_pos[1] + $size[1] / 2)]
        ];
        $this->_size = $size;
    }


    /**
     * @param string $name
     */
    public function setName($name)
    {
        $this->_name = $name;
    }

    /**
     * @return string
     */
    public function getName()
    {
        return $this->_name;
    }

    abstract public function getHtml();
    abstract public function draw();

    /**
     * @return array
     */
    public function getPos()
    {
        return $this->_pos;
    }

    /**
     * @param array $pos
     */
    public function setPos($pos)
    {
        $this->_rectangle = [
            'top-left' => ['x' => intval($pos[0] - $this->_size[0] / 2), 'y'=>intval($pos[1] - $this->_size[1] / 2)],
            'bottom-right' => ['x' => intval($pos[0] + $this->_size[0] / 2), 'y'=>intval($pos[1] + $this->_size[1] / 2)]
        ];
        $this->_pos = [intval($pos[0]), intval($pos[1])];
    }

}