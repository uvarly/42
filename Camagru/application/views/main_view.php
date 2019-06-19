<style></style>
<header></header>
<main>
    <?php
        foreach($data as $row)
            // var_dump($row);
            echo    $row['ID'] . '<br />' .
                    $row['Login'] . '<br />' .
                    $row['Password'] . '<br />' .
                    $row['Email'] . '<br /><br />';
    ?>
</main>
<footer></footer>