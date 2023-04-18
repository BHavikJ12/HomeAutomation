#define BLYNK_USE_DIRECT_CONNECT
#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1); // RX, TX

#define BLYNK_PRINT BT
#include <BlynkSimpleSerialBLE.h>

const int IN = 6;// Input for channel 1(Light)
int light;

// You should get Auth Token in the Blynk App
char auth[] = "YourAuthToken"; //Place the authentication token you got from the e-mail.

void setup()
{
  BT.begin(38400); //For HC-05 default speed is 38400
  pinMode(IN, OUTPUT);
  
  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(38400);
  Blynk.begin(Serial, auth);

  digitalWrite(IN, LOW);
}

BLYNK_WRITE(V0){
  light = param.asInt();
}

void loop()
{
  Blynk.run();
  //Control relay channel 1 based on value of variable 'Light'
  if(light == 1){
    digitalWrite(IN1, HIGH);  
  }else{
    digitalWrite(IN1, LOW);  
  }

}
