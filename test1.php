<!doctype html>
<html>
<head>
<!--<meta http-equiv="refresh" content="1">-->
<meta charset="utf-8">
<title>Welcome To IOT Based attendance  System</title>

<link rel="stylesheet" href="css/style.css">
    <link href="css/bootstrap.min.css" rel="stylesheet">
 <link href="css/style.css" rel="stylesheet">
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <link rel="icon" type="image/png" href="images/logo.jpg">
    <link rel="stylesheet" href="css/font-awesome.css">
    <link href="https://fonts.googleapis.com/css?family=Oswald" rel="stylesheet">
    <link rel="stylesheet" href="css/animated.css">

<style>
	center
	{
             text-transform: capitalize;
            font-weight: bold;
        
	}
   td,th
   {
    text-align: center;
   }
</style>
</head>




<nav class="navbar navbar-inverse navbar-fixed-top">
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="#">IOTomatic</a>
    </div>
    <ul class="nav navbar-nav navbar-right">
      <li class="active"><a href="#"> <span class="glyphicon glyphicon-home"></span> &nbsp;Home</a></li>
      <li><a href="#"><span class="glyphicon glyphicon-user"></span> &nbsp;About</a></li>
      <li><a href="#"> <span class="glyphicon glyphicon-envelope"></span> &nbsp;Contact Us</a></li>
     
    </ul>
  </div>
</nav>

<br><br>

<body style="background:linear-gradient(100deg,#ffd86f,#fc6262);">
<span align="center">
<h1 style="font-family: 'Oswald', sans-serif;"> IOTomatic  Attendance  System</h1>
<br>
<center>
<h3><strong>Maharashtra Institute of technology, aurangabad</strong></h3>
<h5><strong>mechanical engineering department</strong> </h5>
<h5><strong>B.Tech-C</strong> </h5>
</center>
</span>
<?php

$_GET["sub"]="gopal";
$_GET["rn"]="safDS";
$_GET["name"]="FJSDKJ";
date_default_timezone_set('asia/kolkata');
	error_reporting(0);
	echo "<table  class='table table-bordered' id='testTable' border=\"1\" align=\"center\">
			<tr>
				<td width='20%'><b>Subject name</b></td>
				<td width='15%' ><b>Roll no</b></td>
				<td width='40%'><b>Name</b></td>
				<td width='15%'><b>Date</b></td>
				<td width='15%'><b>Time</b></td>
			</tr>";
	if(isset($_GET["sub"]) || $_GET["rn"] || $_GET["name"]){
		$data = "<tr><td>jdbvsib</td>"."<td>".$_GET["rn"]."</td>"."<td>".$_GET["name"]."</td>"."<td>".date("d/m/Y")."</td><td>".date("h:i:sa")."</td></tr>";
		$file = fopen("data19215.txt","a");
		fwrite($file,$data);
		fclose($file);
		echo "done";
	} else {
		$file = fopen("data19215.txt","r");
		while(!feof($file)){
			echo fgets($file);
		}
	}
	echo "</table>";
?>

<p>Click the button to print the current page.</p>

<button onclick="myFunction()" class="btn btn-success">Print</button>
<input type="button" onclick="tablesToExcel(['testTable'], ['un'], 'myfile.xls')" value="Export to Excel">
<script>
function myFunction() {
    window.print();
}
</script>



<script type="text/javascript">
	   var tablesToExcel = (function () {
    var uri = 'data:application/vnd.ms-excel;base64,'
    , template = '<html xmlns:o="urn:schemas-microsoft-com:office:office" xmlns:x="urn:schemas-microsoft-com:office:excel" xmlns="http://www.w3.org/TR/REC-html40"><head><!--[if gte mso 9]><xml><x:ExcelWorkbook><x:ExcelWorksheets>'
    , templateend = '</x:ExcelWorksheets></x:ExcelWorkbook></xml><![endif]--></head>'
    , body = '<body>'
    , tablevar = '<table>{table'
    , tablevarend = '}</table>'
    , bodyend = '</body></html>'
    , worksheet = '<x:ExcelWorksheet><x:Name>'
    , worksheetend = '</x:Name><x:WorksheetOptions><x:DisplayGridlines/></x:WorksheetOptions></x:ExcelWorksheet>'
    , worksheetvar = '{worksheet'
    , worksheetvarend = '}'
    , base64 = function (s) { return window.btoa(unescape(encodeURIComponent(s))) }
    , format = function (s, c) { return s.replace(/{(\w+)}/g, function (m, p) { return c[p]; }) }
    , wstemplate = ''
    , tabletemplate = '';

    return function (table, name, filename) {
        var tables = table;

        for (var i = 0; i < tables.length; ++i) {
            wstemplate += worksheet + worksheetvar + i + worksheetvarend + worksheetend;
            tabletemplate += tablevar + i + tablevarend;
        }

        var allTemplate = template + wstemplate + templateend;
        var allWorksheet = body + tabletemplate + bodyend;
        var allOfIt = allTemplate + allWorksheet;

        var ctx = {};
        for (var j = 0; j < tables.length; ++j) {
            ctx['worksheet' + j] = name[j];
        }

        for (var k = 0; k < tables.length; ++k) {
            var exceltable;
            if (!tables[k].nodeType) exceltable = document.getElementById(tables[k]);
            ctx['table' + k] = exceltable.innerHTML;
        }


        window.location.href = uri + base64(format(allOfIt, ctx));

    }
})();
</script>


 <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="js/bootstrap.min.js"></script>
</body>
</html>