<?php

require_once ('class/IDrawable.class.php');

class Page implements IDrawable
{
    private $css_files = [];
    private $js_files = [];

    public function add_js($filename)
    {
        if (!in_array($filename, $this->js_files))
            $this->js_files[] = $filename;
    }

    public function add_css($filename)
    {
        if (!in_array($filename, $this->css_files))
            $this->css_files[] = $filename;
    }


    public function draw()
    {
        echo $this->getHtml();
    }

    public function getHtml()
    {
        return '';
    }

    public function getCss()
    {
        $css = '';
        foreach ($this->css_files as $css_file) {
            $css .= "<link rel='stylesheet' href='$css_file' />\n";
        }
        return $css;
    }

    public function getJs()
    {
        $js = '';
        foreach ($this->js_files as $js_file) {
            $js .= "<script src='$js_file' type='application/javascript'></script>";
        }
        return $js;
    }
}