<?php
	if ($_POST["submit"] == "Modify" || $_POST["submit"] == "Delete")
	{
		$olog = strtolower($_POST["login"]);
		$nlog = strtolower($_POST["nlogin"]);
		if (file_exists('./private/passwd'))
		{
			$path1 = './private/passwd';
			$path2 = './private/passwd2';
			$file1 = fopen($path1, 'r');
			$file3 = fopen($path2, "w");
			while (($data = fgetcsv($file1, ',')) !== FALSE)
			{
				if ($data[0] == $olog && $_POST["submit"] == "Modify")
				{
					if ($data[1] == hash('sha512', $_POST["opasswd"]) || $_POST["admin"] == "TRUE")
					{
						if (isset($_POST["nlogin"]) && $_POST["nlogin"] != "")
						{
							$file2 = fopen($path1, 'r');
							while (($dat = fgetcsv($file2, ',')) !== FALSE)
							{
								if ($dat[0] == $nlog)
								{
									fclose($file1);
									fclose($file2);
									header("Location: http://localhost:8100/index.php?reg=EXIST");
									exit();
								}
							}
							fclose($file2);
						}
						$account[] = (isset($_POST["nlogin"]) && $_POST["nlogin"] != "") ? $nlog : $data[0];
						$account[] = (isset($_POST["npasswd"]) && $_POST["npasswd"] != "") ? hash('sha512', $_POST["npasswd"]) : $data[1];
						$account[] = $data[2];
						$account[] = (isset($_POST["name"]) && $_POST["name"] != "") ? $_POST["name"] : $data[3];
						$account[] = (isset($_POST["adr"]) && $_POST["nlogin"] != "") ? $_POST["adr"] : $data[4];
						$account[] = (isset($_POST["adr"]) && $_POST["adr"] != "") ? $_POST["adr"] : $data[5];
						$account[] = (isset($_POST["email"]) && $_POST["email"] != "") ? $_POST["email"] : $data[6];
						fputcsv($file3, $account);
					}
					else
					{
						fclose($file);
						header("Location: http://localhost:8100/index.php?log=WINPUT");
						exit();
					}
				}
				else if ($data[0] == $olog && $_POST["submit"] == "Delete" && $_POST["admin"] == "TRUE" && $data[2] != "admin")
				{}
				else
					fputcsv($file3, $data);
			}
		fclose($file1);
		fclose($file3);
		rename($path2, $path1);
		header("Location: http://localhost:8100/index.php?reg=SUCCES");
		exit();
		}
	}
?>
