<?php
require_once ($_SERVER['DOCUMENT_ROOT'] . "/class/MapObject.class.php");

class FactoryObj
{
    private $objects;
    private $min_x;
    private $max_x;
    private $min_y;
    private $max_y;


    /**
     * FactoryObj constructor.
     * @param $min_x
     * @param $max_x
     * @param $min_y
     * @param $max_y
     */
    public function __construct($min_x, $max_x, $min_y, $max_y)
    {
        $this->min_x = $min_x;
        $this->max_x = $max_x;
        $this->min_y = $min_y;
        $this->max_y = $max_y;
    }

    /**
     * @param $obj
     * @throws Exception
     */
    public function addObj($obj)
    {
        if (is_a($obj, MapObject::class))
            $this->objects[] = $obj;
        else
            throw new Exception("{$obj->getName()} is not an MapObject");
    }

    public function getById($id)
    {
        foreach ($this->objects as $object) {
            if ($object instanceof Ship) {
                if ($object->getId() == $id)
                    return ($object);
            }
        }
        return (null);
    }

    public function findInRange($weapon)
    {
        $ret = [];
        foreach ($this->objects as $object) {
            if ($object instanceof Ship)
            {
                if ($weapon instanceof Weapon)
                {
                    if ($weapon->isInRange($object))
                        $ret[] = $object;
                }
            }
        }
        return ($ret);
    }

    public function drawAll()
    {
        echo "<div class='map'>";
        include ('views/template/map.php');
        foreach ($this->objects as $object) {
            $object->draw();
        }
        echo '</div>';
    }
}