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
   <link href="https://fonts.googleapis.com/css?family=PT+Mono|Patrick+Hand" rel="stylesheet">

<style>
	center
	{
             text-transform: capitalize;
            font-weight: bold;
            color: black;
           
        
	}
   td,th
   {
    text-align: center;

    font-family: 'PT Mono', monospace;
   }

   
  


</style>
</head>


<body>

<nav class="navbar navbar-inverse navbar-fixed-top" >
  <div class="container-fluid">
    <div class="navbar-header">
      <a class="navbar-brand" href="index19215.php">IOTomatic</a>

    </div>
    <ul class="nav navbar-nav navbar-right">
      <li class="active"><a href="index19215.php"> <span class="glyphicon glyphicon-home"></span> &nbsp;Home</a></li>
      <li><a href="about.html"><span class="glyphicon glyphicon-user"></span> &nbsp;About</a></li>
      <li><a href="contact.html"> <span class="glyphicon glyphicon-envelope"></span> &nbsp;Contact Us</a></li>

      <li><a href="team.html"> <span class="glyphicon glyphicon-certificate"></span> &nbsp;Team</a></li>
     
    </ul>
  </div>
</nav>

<br><br>


<span align="center">
<h1 style="font-family: 'Oswald', sans-serif;"> IOTomatic  Attendance  System</h1>
<br>
<center>
	<img src="images/logo.jpg" width="100px">
<h3><strong>Maharashtra Institute of technology, aurangabad</strong></h3>
<h5><strong>mechanical engineering department</strong> </h5>
<h5><strong>B.Tech-C</strong> </h5>
</center>
</span>
<div style="margin: 60px">
<?php
date_default_timezone_set('asia/kolkata');
	error_reporting(0);
	echo "<table  class='table table-hover table-dark' id='testTable' border=\"1\" align=\"center\">
			<tr style='background-color:#4285f4; color:white;'>
				<td width='20%'><b>Subject name</b></td>
				<td width='15%' ><b>Present Roll no</b></td>
				<td width='40%'><b>Name</b></td>
				<td width='15%'><b>Date</b></td>
				<td width='15%'><b>Time</b></td>
			</tr>";
	if(isset($_GET["sub"]) || $_GET["rn"] || $_GET["name"]){
		$data = "<tr><td>".$_GET["sub"]."</td>"."<td>".$_GET["rn"]."</td>"."<td>".$_GET["name"]."</td>"."<td>".date("d/m/Y")."</td><td>".date("h:i:sa")."</td></tr>";
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



<button onclick="myFunction()" class="btn btn-success">Click To Print </button>
<button  class="btn btn-success" onclick="tablesToExcel(['testTable'], ['un'], 'myfile.xls')" value="Export to Excel">Export to Excel  </button>
<script>
function myFunction() {
    window.print();
}
</script>
</div>


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

<br><br><br>

    <footer class="page-footer center-on-small-only stylish-color-dark pt-0" style="background: black; color: white;">

        <div style="background-color: #4285f4;">
            <div class="container">
                <!--Grid row-->
                <div class="row py-4 d-flex align-items-center">

                    <!--Grid column-->
                    <div class="col-md-6 col-lg-5 text-center text-md-left mb-4 mb-md-0">
                        <h6 class="mb-0 white-text">Get connected with us on social networks...!!!</h6>
                    </div>
                    <!--Grid column-->

                    <!--Grid column-->
                    <div class="col-md-6 col-lg-7 text-center text-md-right" style="color: white;">
                        <!--Facebook-->
                        <a class="icons-sm fb-ic ml-0"><i class="fa fa-facebook white-text col-md-1"style="color: white; padding: 15px;" > </i></a>
                        <!--Twitter-->
                        <a class="icons-sm tw-ic"><i  style="color: white; padding: 15px;"class="fa fa-twitter white-text col-md-1"> </i></a>
                        <!--Google +-->
                        <a class="icons-sm gplus-ic"><i style="color: white; padding: 15px;" class="fa fa-google-plus white-text col-md-1"> </i></a>
                        <!--Linkedin-->
                        <a class="icons-sm li-ic"><i style="color: white; padding: 15px;" class="fa fa-linkedin white-text col-md-1"> </i></a>
                        <!--Instagram-->
                        <a class="icons-sm ins-ic"><i style="color: white; padding: 15px;" class="fa fa-instagram white-text col-md-1"> </i></a>
                    </div>
                    <!--Grid column-->

                </div>
                <!--Grid row-->

            </div>
        </div>

        <!--Footer Links-->
        <div class="container mt-5 mb-4 text-center text-md-left">
            <div class="row mt-3">

                <!--First column-->
                <div class="col-md-3 col-lg-4 col-xl-3 mb-r">
                    <h6 class="title font-bold"><strong>IOTomatic</strong></h6>
                    <hr class="white mb-4 mt-0 d-inline-block mx-auto" style="width: 60px;">
                  <p>+++++++++++++++</p>
                  <p>***************</p>
                </div>
                <!--/.First column-->

                <!--Second column-->
                <div class="col-md-2 col-lg-2 col-xl-2 mx-auto mb-r">
                    <h6 class="title font-bold"><strong>Info</strong></h6>
                    <hr class="white mb-4 mt-0 d-inline-block mx-auto" style="width: 60px;">
                    <p><a href="about.html">About</a></p>
                    <p><a href="team.html">Team</a></p>
                    <p><a href="contact.html">Contact US</a></p>
                    
                </div>
                <!--/.Second column-->

                <!--Third column-->
                
                <!--/.Third column-->

                <!--Fourth column-->
                <div class="col-md-4 col-lg-3 col-xl-3">
                    <h6 class="title font-bold"><strong>Contact</strong></h6>
                    <hr class="white mb-4 mt-0 d-inline-block mx-auto" style="width: 60px;">
                    <p><i class="fa fa-home mr-3"></i> Aurangabad (M.S)</p>
                    <p><i class="fa fa-envelope mr-3"></i> info@example.com</p>
                    <p><i class="fa fa-phone mr-3"></i>+91 9923269587</p>
                    <p><i class="fa fa-print mr-3"></i>+91 9657298429</p>
                </div>
                <!--/.Fourth column-->

            </div>
        </div>
        <!--/.Footer Links-->

        <!-- Copyright-->
        <div class="footer-copyright">

            <div class="container" style="text-align: center;">
                © 2018 Copyright: <a href="https://www.mdbootstrap.com/"><strong> www.iotsystem.in</strong></a>
            </div>
        </div>
</body>
</html>