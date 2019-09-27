<?php
$album=$_GET["album"];
	$servername="localhost";
	$username="root";
	$passwod="";
	$bd="lilpeep";

	$conn=mysqli_connect($servername, $username, $passwod, $bd);

if(!$conn) {
    die("Connection failed: ".mysqli_connect_error());
  }

  mysqli_set_charset($conn, "utf8");
	$result = mysqli_query($conn, "SELECT * FROM album WHERE nazva='$album'");
	$row_album = mysqli_fetch_array($result, MYSQLI_BOTH);
	$album_id = $row_album["id"];
  	$result2 = mysqli_query($conn, "SELECT * FROM songs WHERE no_album=$album_id");
?>

<!DOCTYPE html>
<html lang="en">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no, maximum-scale=1">
	<title>Альбом</title>
	<link href="https://fonts.googleapis.com/css?family=Open+Sans:300,300i,400,400i,600,600i,700,700i" rel="stylesheet">
	<link href="https://fonts.googleapis.com/css?family=Montserrat:400,400i,700,700i" rel="stylesheet">
	<link href="https://fonts.googleapis.com/css?family=Lato:400,400i,700,700i" rel="stylesheet">
	<link rel="stylesheet" type="text/css" href="css/normalize.css" />
	<link rel="stylesheet" type="text/css" href="css/icomoon.css">
	<link rel="stylesheet" type="text/css" href="css/font-awesome.min.css">
	<link rel="stylesheet" type="text/css" href="css/style.css" />
	<style type="text/css"> 
		
		.album_name{
			display: inline-block;
			width: 45%;
		}
	
		.pxp{
			display: block;
			margin: 50px;
		}

		.logo{
			display: inline-block;
			width: 45%;

		}

		.album_info {
			display: inline-block;
			float: left;

		}

		img {
			border-radius: 5px;
			width: 300px;
			height: 300px;
			display: inline;

		}

		.table-pisni {
			margin-left: 50px;
			display: inline-block;
			float: left;

		}
		
		</style>
</head>
<body style="background-color: black">
			
<section class="pxp">
	<div class="logo"><a href="index.html">Peep</a></div>
		<?php

				echo "<div class='album_name'> <h1>$album</h1></div>";
				echo "<div class='album_info'>
					<img src='img/".$row_album["kartinka"].".png'> </img>
					<h5>Дата виходу альбому: ".$row_album["data_vuhody"]."</h5>
					
				</div>";
				echo "<div class='table-pisni'> <h3>Пісні:</h3> <table cellpadding='20'>";
					for($i = 1; $i <= mysqli_num_rows($result2); $i++){
    				$row = mysqli_fetch_array($result2, MYSQLI_BOTH);
    					echo "<tr>";
    					echo "<td>".$row["nazva_pisni"]."</td>";
    					echo "<td> | ".$row["truvalist"]."</td>";
    					echo "</tr>";
					}
				echo "</table> </div>";
			?>
		</section>

</body>
</html>