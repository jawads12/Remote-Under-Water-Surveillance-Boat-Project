
#include <OneWire.h>
#include <DallasTemperature.h>
#include<SFE_BMP180.h>
#include<Wire.h>

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 4
SFE_BMP180 Barometer;
#define Sensor 7

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);


void setup() {
  sensors.begin();
  pinMode(Sensor,INPUT);
  if(Barometer.begin()==0)
  {
    Serial.println("Reboot Failed.");
    
  }


Serial.begin(9600);
}

void loop() {




//temp

 sensors.requestTemperatures(); 

  //print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print((char)176);//shows degrees character
  Serial.print("C  |  ");
  
  //print the temperature in Fahrenheit
  Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
  Serial.print((char)176);//shows degrees character
  Serial.println("F");
//turbitity
  int sen = map(analogRead(A2),0,1100,0,200);
  Serial.println(sen);
  delay(100);
  if(sen>130) Serial.println("clear water");
  if(sen<120) Serial.println("Dirty");

  //microwave
  bool Detection = digitalRead(Sensor);

if(Detection == HIGH)
Serial.println("Motion detected !!");
if(Detection == LOW)
Serial.println("No Motion");


//barometer
   double Temperature, Pressure, Altitude;

  if(Barometer.startTemperature())
  {
    delay(1200);
    if(Barometer.getTemperature(Temperature))
    {
      Serial.print("Temperature: ");
      Serial.print(Temperature,4);
      Serial.println(" deg Celsius");

      if(Barometer.startPressure(5))
      {
        delay(1200);
        if(Barometer.getPressure(Pressure,Temperature))
        {
          Serial.print("Absolute pressure: ");
          Serial.print(Pressure,4);
          Serial.println(" mb. ");

          double Altitude = Barometer.altitude(Pressure,1013.25);
          Serial.print("Measured altitude (from sea level): ");
          Serial.print(Altitude,4);
          Serial.println(" meters. ");

          Serial.println("-----------------------------------------------------");
        }
        else Serial.println("Error while measuring Pressure.");
      }
      else Serial.println("Error while starting Pressure calculation.");
    }
    else Serial.println("Error while measuring Temperature.");
  }
  else
  Serial.println("Error while starting temperature calculation.");


  
  delay(500);





}
