
String ssid="abhijeet";    // Wifi network SSID
String password ="123456789";  // Wifi network password
String value1="wow";
String value2="mom";
int stud=0;
boolean DEBUG=true;
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
int sub1=0;
char w;
int s;
int cn=0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(3,4,5,6,7,8);
int ccc=0;
int getFingerprintIDez();

// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
SoftwareSerial mySerial(9,10);


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{



  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Welcome to MIT-T");
  lcd.setCursor(0,1);

  //Serial.begin(9600);
  //Serial.println("fingertest");

  // set the data rate for the sensor serial port
  finger.begin(57600);

  if (finger.verifyPassword()) {
    //Serial.println("Found fingerprint sensor!");
  } 
  else {
    //Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
  //Serial.println("Waiting for valid finger...");
  delay(1000);
  lcd.clear();
  lcd.print("scaning.......");


  delay(2000);

  DEBUG=true;           // enable debug delete




    Serial.begin(115200);  // enable software delete
  // Your esp8266 module's speed is probably at 115200. 
  // For this reason the first time set the speed to 115200 or to your esp8266 configured speed 
  // and upload. Then change to 9600 and upload again

  Serial.println("AT+RST");         // Enable this line to reset the module;
  showResponse(1000);

  Serial.println("AT+UART_CUR=115200,8,1,0,0");    // Enable this line to set esp8266 delete speed to 9600 bps
  showResponse(1000);



  Serial.println("AT+CWMODE=1");   // set esp8266 as client
  showResponse(1000);

  Serial.println("AT+CWJAP=\""+ssid+"\",\""+password+"\"");  // set your home router SSID and password
  showResponse(5000);





  delay(100);
}

void loop()                     // run over and over again
{
  getFingerprintIDez();
  delay(50);            //don't ned to run this at full speed.


}



uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
  case FINGERPRINT_OK:
    //Serial.println("Image taken");
    break;
  case FINGERPRINT_NOFINGER:
    //Serial.println("No finger detected");
    return p;
  case FINGERPRINT_PACKETRECIEVEERR:
    //Serial.println("Communication error");
    return p;
  case FINGERPRINT_IMAGEFAIL:
    //Serial.println("Imaging error");
    return p;
  default:
    //Serial.println("Unknown error");
    return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
  case FINGERPRINT_OK:
    //Serial.println("Image converted");
    break;
  case FINGERPRINT_IMAGEMESS:
    //Serial.println("Image too messy");
    return p;
  case FINGERPRINT_PACKETRECIEVEERR:
    //Serial.println("Communication error");
    return p;
  case FINGERPRINT_FEATUREFAIL:
    //Serial.println("Could not find fingerprint features");
    return p;
  case FINGERPRINT_INVALIDIMAGE:
    //Serial.println("Could not find fingerprint features");
    return p;
  default:
    //Serial.println("Unknown error");
    return p;
  }

  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    //Serial.println("Found a print match!");
  } 
  else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    //Serial.println("Communication error");
    return p;
  } 
  else if (p == FINGERPRINT_NOTFOUND) {
    //Serial.println("Did not find a match");
    return p;
  } 
  else {
    //Serial.println("Unknown error");
    return p;
  }   

  // found a match!
  //Serial.print("Found ID #"); 
  //Serial.print(finger.fingerID); 
  //Serial.print(" with confidence of "); 
  //Serial.println(finger.confidence); 
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  //Serial.print("Found ID #"); 
  //Serial.print(finger.fingerID); 




  if(finger.fingerID==0)
  {
    sub1=1;
    cn++;
    lcd.clear();
    lcd.print("Subject1 ON");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }

  else if(finger.fingerID==1)
  {
    sub1=0;
    cn++;
    lcd.clear();
    lcd.print("Subject1 OFF");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }

  else if(finger.fingerID==2)
  {
    sub1=2;
    cn++;
    lcd.clear();
    lcd.print("Subject2 ON");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }
  else if(finger.fingerID==3)
  {
    sub1=0;
    cn++;
    lcd.clear();
    lcd.print("Subject2 OFF");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }


  else if(finger.fingerID==4)
  {
    sub1=3;
    cn++;
    lcd.clear();
    lcd.print("Subject3 ON");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }
  else if(finger.fingerID==5)
  {
    sub1=0;
    cn++;
    lcd.clear();
    lcd.print("Subject3 OFF");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }


  else if(finger.fingerID==6)
  {

    sub1=4;
    cn++;
    lcd.clear();
    lcd.print("Subject4 ON");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }
  else if(finger.fingerID==7)
  {
    sub1=0;
    cn++;
    lcd.clear();
    lcd.print("Subject4 OFF");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }


  else if(finger.fingerID==8)
  {
    sub1=5;
    cn++;
    lcd.clear();
    lcd.print("Subject5 ON");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }
  else if(finger.fingerID==9)
  {
    sub1=0;
    cn++;
    lcd.clear();
    lcd.print("Subject5 OFF");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }


  else if(finger.fingerID==10)
  {
    sub1=6;
    cn++;
    lcd.clear();
    lcd.print("Subject6 ON");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }
  else if(finger.fingerID==11)
  {
    sub1=0;
    cn++;
    lcd.clear();
    lcd.print("Subject6 OFF");
    lcd.setCursor(0, 1);
    delay(2000);
    // digitalWrite(buz,LOW);
  }



  /////000000000000000000000000000000000000000000000000000000000
  if(sub1==1)
  {
    if(finger.fingerID==12)
    {
      //sub1=0;
      stud=1;
      cn++;
      lcd.clear();
      lcd.print("Subjecti1");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name1");
      delay(2000);
      // digitalWrite(buz,LOW);
    }

    if(finger.fingerID==13)
    {
      stud=2;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti1");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name2");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==14)
    {
      //sub1=0;
      stud=3;
      cn++;
      lcd.clear();
      lcd.print("Subjecti1");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name3");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==15)
    {
      stud=4;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti1");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name4");

      // digitalWrite(buz,LOW);
    }
    thingSpeakWrite();
    delay(2000);
  }

  /////000000000000000000000000000000000000000000000000000000000
  /////000000000000000000000000000000000000000000000000000000000
  if(sub1==2)
  {
    if(finger.fingerID==12)
    {
      stud=1;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti2");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name1");
      delay(2000);
      // digitalWrite(buz,LOW);
    }

    if(finger.fingerID==13)
    {
      //sub1=0;
      stud=2;
      cn++;
      lcd.clear();
      lcd.print("Subjecti2");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name2");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==14)
    {
      //sub1=0;
      stud=3;
      cn++;
      lcd.clear();
      lcd.print("Subjecti2");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name3");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==15)
    {
      //sub1=0;
      stud=4;
      cn++;
      lcd.clear();
      lcd.print("Subjecti2");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name4");
      //delay(2000);
      // digitalWrite(buz,LOW);
    }
    thingSpeakWrite();
    delay(2000);
  }

  /////000000000000000000000000000000000000000000000000000000000
  /////000000000000000000000000000000000000000000000000000000000
  if(sub1==3)
  {
    if(finger.fingerID==12)
    {
      //sub1=0;
      stud=1;
      cn++;
      lcd.clear();
      lcd.print("Subjecti3");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name1");
      delay(2000);
      // digitalWrite(buz,LOW);
    }

    if(finger.fingerID==13)
    {
      stud=2;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti3");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name2");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==14)
    {
      stud=3;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti3");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name3");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==15)
    {
      stud=4;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti3");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name4");
      // delay(2000);
      // digitalWrite(buz,LOW);
    }
    thingSpeakWrite();
    delay(2000);
  }

  /////000000000000000000000000000000000000000000000000000000000
  /////000000000000000000000000000000000000000000000000000000000
  if(sub1==4)
  {
    if(finger.fingerID==12)
    {
      stud=1;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti4");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name1");
      delay(2000);
      // digitalWrite(buz,LOW);
    }

    if(finger.fingerID==13)
    {
      stud=2;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti4");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name2");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==14)
    {
      stud=3;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti4");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name3");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==15)
    {
      stud=4;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti4");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name4");
      //delay(2000);
      // digitalWrite(buz,LOW);
    }
    thingSpeakWrite();
    delay(2000);
  }

  /////000000000000000000000000000000000000000000000000000000000
  /////000000000000000000000000000000000000000000000000000000000
  if(sub1==5)
  {

    if(finger.fingerID==12)
    {
      stud=1;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti5");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name1");
      delay(2000);
      // digitalWrite(buz,LOW);
    }

    if(finger.fingerID==13)
    {
      stud=2;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti5");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name2");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==14)
    {
      stud=3;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti5");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name3");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==15)
    {
      stud=4;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti5");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name4");
      //delay(2000);
      // digitalWrite(buz,LOW);
    }
    thingSpeakWrite();
    delay(2000);
  }

  /////000000000000000000000000000000000000000000000000000000000
  /////000000000000000000000000000000000000000000000000000000000
  if(sub1==6)
  {

    if(finger.fingerID==12)
    {
      stud=1;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti6");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name1");
      delay(2000);
      // digitalWrite(buz,LOW);
    }

    if(finger.fingerID==13)
    {
      stud=2;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti6");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name2");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==14)
    {
      stud=3;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti6");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name3");
      delay(2000);
      // digitalWrite(buz,LOW);
    }
    if(finger.fingerID==15)
    {
      stud=4;
      //sub1=0;
      cn++;
      lcd.clear();
      lcd.print("Subjecti6");
      lcd.setCursor(0, 1);
      lcd.print("Ny Name4");
      //delay(2000);
      // digitalWrite(buz,LOW);
    }
    thingSpeakWrite();
    delay(2000);
  }

  /////000000000000000000000000000000000000000000000000000000000


    delay(2000);
  //digitalWrite(buz,LOW);


  //Serial.print(" with confidence of "); 
  //Serial.println(finger.confidence);
  return finger.fingerID; 
}






//======================================================================== showResponce
void showResponse(int waitTime){
  long t=millis();
  char c;
  while (t+waitTime>millis()){
    if (Serial.available()){
      c=Serial.read();

    }
  }

}

//========================================================================
boolean thingSpeakWrite(){
  String cmd = "AT+CIPSTART=\"TCP\",\"";                  // TCP connection
  cmd += "166.62.11.102";                               // api.thingspeak.com
  cmd += "\",80";
  Serial.println(cmd);

  if(Serial.find("Error")){

    return false;
  }


  String getStr = "GET /index19215.php?";   // prepare GET string


  getStr +="sub=";

  if(sub1==1)
  {
    getStr +="subject1";
  }
  else if(sub1==2)
  {
    getStr +="subject2";
  }
  else if(sub1==3)
  {
    getStr +="subject3";
  }
  else if(sub1==4)
  {
    getStr +="subject4";
  }
  else if(sub1==5)
  {
    getStr +="subject5";
  }
  else if(sub1==6)
  {
    getStr +="subject6";
  }
  else
  {
    getStr +="NOTT";
  }

  //getStr +="EMB";
  getStr +="&rn=";

  if(stud==1)
  {
    getStr +="Student1rn";
  }
  else if(stud==2)
  {
    getStr +="Student2rn";
  }
  else if(stud==3)
  {
    getStr +="Student3rn";
  }
  else if(stud==4)
  {
    getStr +="Student4rn";
  }
  else
  {
    getStr +="NOTT";
  }

  //getStr +="111";
  getStr +="&name=";

  if(stud==1)
  {
    getStr +="Student1";
  }
  else if(stud==2)
  {
    getStr +="Student2";
  }
  else if(stud==3)
  {
    getStr +="Student3";
  }
  else if(stud==4)
  {
    getStr +="Student4";
  }
  else
  {
    getStr +="NOTT";
  }
  //getStr +="test";





  // getStr +="&field3=";
  // getStr += String(value3);
  // ...
  getStr += "\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  Serial.println(cmd);


  delay(100);
  stud=0;
  if(Serial.find(">")){
    Serial.print(getStr);

  }
  else{
    Serial.println("AT+CIPCLOSE");
    // alert user

    return false;
  }
  return true;
}
//================================================================================ setup






















