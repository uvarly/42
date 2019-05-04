<?php
if ($_SERVER["PHP_AUTH_USER"] == "zaz" && $_SERVER["PHP_AUTH_PW"] == "jaimelespetitsponeys")
{
    echo "<html><body>\n";
    echo "Hello Zaz<br />\n";
    $img = base64_encode(file_get_contents("../img/42.png"));
    echo "<img src='data:image/png;base64,$img'>\n";
    echo "</body></html>\n";
}
else
{
    header("HTTP/1.0 401 Unauthorized");
    header("WWW-Authenticate: Basic realm=''Member area''");
    echo "<html><body>That area is accessible for members only</body></html>\n";
}
?>
