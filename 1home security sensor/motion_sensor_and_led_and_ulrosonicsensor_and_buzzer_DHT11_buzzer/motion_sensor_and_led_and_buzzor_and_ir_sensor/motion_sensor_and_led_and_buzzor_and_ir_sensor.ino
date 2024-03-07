int led = 13;
int pin = 2;

int value = 0;
int pirState = LOW;

int irSensor=12;     // pin 3 is the buzzer output
int buzzer=7; // pin 4 is the pushbutton input

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer2 = 8;
const int ledPin = 8;


// defines variables
long duration;
int distance;
int safetyDistance;

// defines pins numbers
const int trigPin3 = 6;
const int echoPin3 = 5;
const int buzzer3 = 12;
const int ledPin3 = 8;
                            //  Project by - Be innovative with Prasad
                                    //   title - ultrasonic sensor project with buzzer and Arduino 
// defines variables
long duration1;
int distance1;
int safetyDistance1;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(pin, INPUT);
  pinMode(irSensor,INPUT);    //configure pin 4 as OUTPUT
  pinMode(buzzer,OUTPUT); //configure pin 4 as INPUT
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer2, OUTPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer3, OUTPUT);
  pinMode(ledPin3, OUTPUT);
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
  
  if(value2==0)
  {
    digitalWrite(buzzer,HIGH);

  }
  else
  {
    digitalWrite(buzzer,LOW);
  }
  delay(50);


  // Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
 
// Calculating the distance
distance= duration*0.034/2;
 
safetyDistance = distance;
if (safetyDistance <= 20)   // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
  digitalWrite(buzzer2, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer2, LOW);
  digitalWrite(ledPin, LOW);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);



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
if (safetyDistance1 <= 20)   // You can change safe distance from here changing value Ex. 20 , 40 , 60 , 80 , 100, all in cm
{
  digitalWrite(buzzer3, HIGH);
  digitalWrite(ledPin3, HIGH);
}
else{
  digitalWrite(buzzer3, LOW);
  digitalWrite(ledPin3, LOW);
}
 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance1);

}