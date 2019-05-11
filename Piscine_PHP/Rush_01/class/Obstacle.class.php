<?php
require_once ('class/MapObject.class.php');

class Obstacle extends MapObject
{

    public function __construct($name, $top_left, $bottom_right)
    {
        parent::__construct();
        $this->setRectangle($top_left,  $bottom_right);
        $this->setName($name . $this->getId());

    }

    public function getHtml()
    {
        $top = $this->getRectangle()["top-left"]['y'];
        $left = $this->getRectangle()["top-left"]['x'];
        $width = $this->getSize()[0];
        $height = $this->getSize()[1];
        return <<<EOF
<div class="map-object obstacle" id="obj-{$this->getName()}" style="top: {$left}0px; left: {$top}0px; width: {$width}0px; height: {$height}0px;">
<img src="/images/obstackles/obs.jpg" style="top: {$left}0px; left: {$top}0px; width: {$width}0px; height: {$height}0px;"> </div>
EOF;

    }

    public function draw()
    {
        echo $this->getHtml();
    }
    public function getCss()
    {
        // TODO: Implement getCss() method.
    }
    public function getJs()
    {
        // TODO: Implement getJs() method.
    }
}