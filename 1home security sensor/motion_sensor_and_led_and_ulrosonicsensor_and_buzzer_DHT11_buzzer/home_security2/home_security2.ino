int led = 13;
int pin = 2;

int value = 0;
int pirState = LOW;

int irSensor=2;     // pin 3 is the buzzer output


// defines pins numbers
const int trigPin3 = 6;
const int echoPin3 = 5;
const int buzzer3 = 12;

                            //  Project by - Be innovative with Prasad
                                    //   title - ultrasonic sensor project with buzzer and Arduino 
// defines variables
long duration1;
int distance1;
int safetyDistance1;


const int buzzer4 = 11;

#include <dht.h>        // Include library
#define outPin 7       // Defines pin number to which the sensor is connected

dht DHT;                // Creates a DHT object

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pin, INPUT);
  pinMode(irSensor,INPUT);    //configure pin 4 as OUTPUT
  


  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer3, OUTPUT);


  pinMode(buzzer4, OUTPUT);

  Serial.begin(9600);

}

void loop() {
 value = digitalRead(pin);

  if (value == HIGH) {
    digitalWrite(led, HIGH);

    if (pirState == LOW) {
      Serial.println("Motion Detected!");
      pirState = HIGH;
    }
  }else{
    digitalWrite(led, LOW);

    if(pirState == HIGH){
      Serial.println("Motion Ended!");
      pirState = LOW;
      }
    }


  int value2=digitalRead(irSensor); 
  Serial.println("");
  Serial.print("sensor value = ");
  Serial.print(value2);
  
  delay(50);





digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin3, HIGH);
 
// Calculating the distance
distance1= duration1*0.034/2;
 
safetyDistance1 = distance1;
if (safetyDistance1 <= 5)   // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
  digitalWrite(buzzer3, HIGH);

}
else{
  digitalWrite(buzzer3, LOW);

}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance1);



int readData = DHT.read11(outPin);

	float t = DHT.temperature;        // Read temperature
	float h = DHT.humidity;           // Read humidity

	Serial.print("Temperature = ");
	Serial.print(t);
	Serial.print("°C | ");
	Serial.print((t*9.0)/5.0+32.0);        // Convert celsius to fahrenheit
	Serial.println("°F ");
	Serial.print("Humidity = ");
	Serial.print(h);
	Serial.println("% ");
	Serial.println("");
  delay(2000); // wait two seconds
  if(t>=31.00)
  {
      digitalWrite(buzzer4, HIGH);
  }
 // wait two seconds
  else
  {
      digitalWrite(buzzer4, LOW);
  }

}
