#include <LiquidCrystal.h>

// LCD pin connections
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buzzerPin = 8; // declaring the pin for the buzzer
const int focusTime = 60; // the amount of time the focus timer 
const int button = 7; // declaring the pin for the button
const int countdown= 5; // before the focus buzzer timer


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
  noTone(buzzerPin)
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
    lcd.print("Focus starts");
    lcd.setCursor(0, 1);
    lcd.print(i)
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







  

  // First LCD message
  lcd.setCursor(0, 0);
  lcd.print("Focus Mode");

  lcd.setCursor(0, 1);
  lcd.print("Stay Focused");

  // Small startup beep
  tone(buzzerPin, 1000);
  delay(300);
  noTone(buzzerPin);
}

void loop() {

  // Current time
  unsigned long currentTime = millis();

  // Check if focus interval passed
  if (currentTime - previousTime >= focusInterval) {

    // Save current time
    previousTime = currentTime;

    // LCD reminder message
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Take a Breath");

    lcd.setCursor(0, 1);
    lcd.print("Refocus!");

    // Buzzer sound
    tone(buzzerPin, 1500);

    delay(1000);

    noTone(buzzerPin);

    // Return to normal screen
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Focus Mode");

    lcd.setCursor(0, 1);
    lcd.print("Stay Focused");
  }
}