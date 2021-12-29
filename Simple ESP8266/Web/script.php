<?php

if (isset($_GET['lightstatus']))
{
	$myfile = fopen("lightstatus.txt","w");
	
	if ($_GET['lightstatus'] == 'lampon')
	{
		fwrite($myfile,'2');
		header ("Location: onlight.html");
	}
	
	else if ($_GET['lightstatus'] == 'lampoff')
	{
		fwrite($myfile,'1');
		header ("Location: offlight.html");
	}
	fclose($handle);
}

?>	