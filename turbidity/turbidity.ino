
// #include <OneWire.h>
// #include <DallasTemperature.h>

// // Data wire is plugged into digital pin 2 on the Arduino
// #define ONE_WIRE_BUS 2

// // Setup a oneWire instance to communicate with any OneWire device
// OneWire oneWire(ONE_WIRE_BUS);	

// // Pass oneWire reference to DallasTemperature library
// DallasTemperature sensors(&oneWire);

void setup() {
 // sensors.begin();

//pinMode(m_Sensor,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sen = map(analogRead(A5),0,1100,0,200);
  //Serial.println(sen);
  delay(100);
  if(sen>130) Serial.println("clear water");
  if(sen<120) Serial.println("Dirty");




// bool Detection = digitalRead(m_Sensor); 

// if(Detection == HIGH)
// Serial.println("Motion detected !!");
// if(Detection == LOW)
// Serial.println("Clear");



// //temp

//  sensors.requestTemperatures(); 

//   //print the temperature in Celsius
//   Serial.print("Temperature: ");
//   Serial.print(sensors.getTempCByIndex(0));
//   Serial.print((char)176);//shows degrees character
//   Serial.print("C  |  ");
  
//   //print the temperature in Fahrenheit
//   Serial.print((sensors.getTempCByIndex(0) * 9.0) / 5.0 + 32.0);
//   Serial.print((char)176);//shows degrees character
//   Serial.println("F");
  
//   delay(500);





}


