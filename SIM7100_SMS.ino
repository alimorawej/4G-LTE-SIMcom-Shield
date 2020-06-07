 /* ======================================================================
  Project: 4G LTE SIMCOM Shield
  Function: SMS
  GPIO: None
  Description: This example sketch allows your device to send SMS without any library,  
               you can change AT command for your own test.

  Software:     Developed by Arduino 1.8.9 software
  Hardware:     ESP8266-12E, SIM7100
  Last Updated: 10/15/2019
  Author:       Ali Morawej
  Github: https://github.com/alimorawej/4G-LTE-SIMcom-Shield
  License: Free    

  Comments: 
  ====================================================================== */

int State = HIGH;

void setup(){

  Serial.begin(115200); // Setting the baud rate of Serial Monitor
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }

// Serial.println(F("welcome goes here!"));

}

void loop()
{
Serial.println(F("AT"));

  delay(5000);

  if(State == HIGH)
    {
      sendsms();
      delay(10000);
    }
}

void sendsms()
{
  Serial.println("AT\r");
  waitForResponse();
  Serial.println("AT+CMGF=1\r");
  waitForResponse();
  Serial.println("AT+CPMS=\"ME\",\"ME\",\"ME\"\r");
  waitForResponse();
  Serial.println("AT+CNMI=2,1\r");
  waitForResponse();
  Serial.println("AT+CMGS=\"+1604xxxxxx\"\r");
  waitForResponse();
  Serial.println("Hello for SIM7100");
  waitForResponse();
  Serial.println((char)26); // ASCII code of CTRL+Z
  delay(100);
 
}

void waitForResponse() {
    delay(3000);
    while (Serial.available()) {
      Serial.read();
    }
    Serial.write("\n");
}
