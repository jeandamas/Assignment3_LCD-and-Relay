
// include the library code
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//variable declaraition for pins
//relay pin to arduino
int reldig=7;
//photoresistor pin on arduino 
char photoPin = A0;
void setup() {
  //setting up pin mode for photoresistor
  pinMode(photoPin, INPUT);
  Serial.begin(9600);
  
  //setting up pin mode for relay on arduino
  pinMode(reldig, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("The light intensity:");
}

void loop() {
  //print values from photoresistor in serial monitor
  Serial.println(analogRead(photoPin));
  //if it light intensity gets below 350
    if (analogRead(photoPin) < 350) {
      //turn on bulb
      digitalWrite(reldig, HIGH);
    } else {
      //else turn off bulb
      digitalWrite(reldig, LOW);
    }
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.println(analogRead(photoPin));
  delay(99);
}
 
