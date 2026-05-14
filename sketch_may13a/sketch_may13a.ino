#include <LiquidCrystal.h>

// LCD pin connections
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buzzerPin = 8;  
const int focusTime = 60; 
const int buttonPin = 7; 
const int countdownStart = 5;  

void setup() {
 // Defining outputs and inputs
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Press button");
  lcd.setCursor(0, 1);
  lcd.print("to start");
}
//  Buzzer Melody at the end of the Focus time

void endMelody() {

  tone(buzzerPin, 1200);
  delay(300);
  noTone(buzzerPin);
  delay(100);

  tone(buzzerPin, 1500);
  delay(300);
  noTone(buzzerPin);

  delay(100);

  tone(buzzerPin, 1800);
  delay(500);
  noTone(buzzerPin);
}
// Countdown before the focus buzzer starts

void countdown() {
for (int i = countdownStart; i > 0; i--) {

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Focus starts in");
    lcd.setCursor(0, 1);
    lcd.print(i);
     tone(buzzerPin, 800);

    delay(200);

    noTone(buzzerPin);

    delay(800);
  }
}

//  Focus Timer started
void focusMode() {
unsigned long startTime = millis();

while (millis() - startTime < (unsigned long)focusTime * 1000) {

    lcd.setCursor(0, 0);
    lcd.print("FOCUS MODE   ");

    lcd.setCursor(0, 1);
    lcd.print("Stay Working ");

    delay(200);
  }
}
//  The end of the Focus buzzer

void finish() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TIME IS UP!");
  lcd.setCursor(0, 1);
  lcd.print("Good job");
  endMelody();
  delay(3000);
}
// Main loop

void loop() {


  if (digitalRead(buttonPin) == LOW) {

    delay(200);

    countdown();
    focusMode();
    finish();

 // Show start screen again
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Press button");
    lcd.setCursor(0, 1);
    lcd.print("to start");
    
  }
}





  
