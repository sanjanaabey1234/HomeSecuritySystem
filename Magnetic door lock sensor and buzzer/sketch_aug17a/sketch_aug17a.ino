const int buzzer = 3; 
const int sensor = 4;
 
int state; // 0 close - 1 open switch

void setup() {
  pinMode(sensor, INPUT_PULLUP);

}

void loop() {
  state = digitalRead(sensor);
  
  if (state == HIGH){
    tone(buzzer, 400);
  }
  else{
    noTone(buzzer);
  }
  delay(200);

}