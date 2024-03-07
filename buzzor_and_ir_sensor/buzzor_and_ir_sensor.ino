int irSensor=12;     // pin 3 is the buzzer output
int buzzer=7; // pin 4 is the pushbutton input

void setup()
{
  Serial.begin(9600);
  pinMode(irSensor,INPUT);    //configure pin 4 as OUTPUT
  pinMode(buzzer,OUTPUT); //configure pin 4 as INPUT
}
void loop()
{
  int value=digitalRead(irSensor); 
  Serial.println("");
  Serial.print("sensor value = ");
  Serial.print(value);
  
  if(value==0)
  {
    digitalWrite(buzzer,HIGH);

  }
  else
  {
    digitalWrite(buzzer,LOW);
  }
  delay(50);
}