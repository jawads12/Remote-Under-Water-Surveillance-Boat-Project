#define m_Sensor 2

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 4

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);


void setup() {
  sensors.begin();

pinMode(m_Sensor,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sen = map(analogRead(A5),0,1100,0,200);
  //Serial.println(sen);
  delay(100);
  if(sen>130) Serial.println("clear water");
 // Serial.println(sen);
  else if(sen<100) Serial.println("Dirty water");
  else  Serial.println("No Water Detected");




bool Detection = digitalRead(m_Sensor);

if(Detection == HIGH)
Serial.println("Motion detected !!");
if(Detection == LOW)
Serial.println("No motion");



//temp

 sensors.requestTemperatures(); 

  //print the temperature in Celsius
//  Serial.print("Temperature: ");
//  Serial.print(sensors.getTempCByIndex(0));
//  Serial.print((char)176);//shows degrees character
//  Serial.print("C  |  ");
//  
//  //print the temperature in Fahrenheit
//  Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
//  Serial.print((char)176);//shows degrees character
//  Serial.println("F");


Serial.println("//////////////////////");
  
  delay(500);





}
