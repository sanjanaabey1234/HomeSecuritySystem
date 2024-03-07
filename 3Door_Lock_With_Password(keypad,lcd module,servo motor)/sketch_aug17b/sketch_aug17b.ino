#include<LiquidCrystal.h>
#include<Keypad.h>
#include<Servo.h>
 
 Servo doorServo;
 
#define redLED 12
#define greenLED 11
 
char* password="1122";
int pozisyon=0;
 
const byte rows=4;
const byte cols=4;


 
char keyMap[rows] [cols] = {
 
{'1','2','3','A'},
 
{'4','5','6','B'},
 
{'7','8','9','C'},
{'*','0','#','D'}


 
};
 
byte rowPins[rows] ={1,2,3,4};
byte colPins[cols] ={5,6,7,8};
 
Keypad myKeypad = Keypad(makeKeymap(keyMap), rowPins,colPins, rows, cols);
LiquidCrystal lcd (A0, A1, A2, A3, A4, A5);

void setup() {
  lcd.begin(16, 2);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  setLocked (true);
 
 doorServo.attach(9); // Attach servo to pin 9

}

void loop() {
  char whichKey = myKeypad.getKey();


 
  lcd.setCursor(0, 0);
  lcd.print("  Welcome  ");  
   lcd.setCursor(0, 1);
  lcd.print("Enter Password"); 
 
  if(whichKey == '#')
  {
    
    pozisyon=0;
    setLocked (true);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print( "Door Locked!");
    delay(1000);
    lcd.clear();
 
   
  
   
   
 
  }
 
  if(whichKey == 'A' || whichKey == 'B' ||whichKey == 'C' || whichKey == 'D')
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print( " Invalid Key!");
    delay(1000);
    lcd.clear();
  }
  if(whichKey == password [pozisyon])
  {
    pozisyon ++;
  }
 
  if(pozisyon == 4)
  {
    
    setLocked (false);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print( "  ***Verified!***");
   delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print( " Welcome "); 
    lcd.setCursor(0, 1);
    lcd.print( " Home "); 
     
    delay(1000);
     
    lcd.clear();
    
  }

}
 
void setLocked(bool locked)
{
  
    if(locked ) //check door locked
    {
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW); 
    
    closeAndLockDoor();
  delay(1000); // Wait for 1 seconds
        
  
    }
    else
    {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
       unlockAndOpenDoor();
     delay(1000); // Wait for 1  seconds
 
      
 
      
    }
 
   
}
 
void unlockAndOpenDoor() {
  doorServo.write(0);  // Unlock the door
  delay(1000);        // Wait for 1 second
  doorServo.write(90); // Open the door to 90 degrees
}
 
 
 
void closeAndLockDoor() {
  doorServo.write(0);  // Close the door
  //delay(1000);        // Wait for 1 second
  //doorServo.write(90); // Lock the door
}