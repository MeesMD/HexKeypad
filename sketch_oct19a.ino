#define greenLED 11 //define the LED pins
#define redLED 12
#define yellowLED 13
#include <Keypad.h>

char* password ="1234"; 
bool locked = true;
int position = 0;
bool correct = false;

const byte ROWS = 4; 
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = { 9, 8, 7, 6, };
byte colPins[COLS] = { 5, 4, 3, 2, }; 

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);  
}

void loop(){
  
  if (position <4)
  {
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  }
  
  char whichKey = kpd.getKey();
  if(whichKey)  // Check for a valid key.
  {
    if(whichKey == password[position])
    {
      position ++;
      correct = true;
    }
    else if(whichKey != password[position])
    {
      position ++;  
      correct = false;
    }
    
    
    
    if (position == 4)
    {
      LockedPosition(false);
    }
    Serial.println(whichKey);
  }
}
    
    void LockedPosition(int locked)
    {
    if(correct == false)
    {
      digitalWrite(redLED, HIGH);
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      Serial.println("---------------LOCKED------------------");
      delay(2000);
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      locked = true;
      position = 0;
    }
    else
    {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
      digitalWrite(yellowLED, LOW);
      Serial.println("---------------UNLOCKED------------------");
      delay(2000);
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      locked = true;
      position = 0;
    }
  }
  


