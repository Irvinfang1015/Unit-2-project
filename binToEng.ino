// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 9, 8);
int but1 = 3;
int but2 = 2;


String letter = "";

String msg = "";



void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  
  attachInterrupt(0, add0, RISING);
  attachInterrupt(1, add1, RISING);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  lcd.print("M: " + msg);
  
  lcd.setCursor(0, 1);
  lcd.print("Input: " + letter);
  
  delay(100);
  
  if (letter.length() == 6) {

    storeChar(letter);
    letter = "";
    clearDisplay();
    
  }
}


// FUNCTIONS -----------------------------

void clearDisplay() {
  lcd.clear();
}

void add0() {
  letter += "0";
}


void add1() {
  letter += "1";
}

void storeChar(String character) {
  
  if (character == "000000") {
    msg += "0";
  } else if (character == "000001") {
    msg += "1";
  } else if (character == "000010") {
    msg += "2";
  } else if (character == "000011") {
    msg += "3";
  } else if (character == "000100") {
    msg += "4";
  } else if (character == "000101") {
    msg += "5";
  } else if (character == "000110") {
    msg += "6";
  } else if (character == "000111") {
    msg += "7";
  } else if (character == "001000") {
    msg += "8";
  } else if (character == "001001") {
    msg += "9";
  } else if (character == "001010") {
    msg += "A";
  } else if (character == "001011") {
    msg += "B";
  } else if (character == "001100") {
    msg += "C";
  } else if (character == "001101") {
    msg += "D";
  } else if (character == "001110") {
    msg += "E";
  } else if (character == "001111") {
    msg += "F";
  } else if (character == "010000") {
    msg += "G";
  } else if (character == "010001") {
    msg += "H";
  } else if (character == "010010") {
    msg += "I";
  } else if (character == "010011") {
    msg += "J";
  } else if (character == "010100") {
    msg += "K";
  } else if (character == "010101") {
    msg += "L";
  } else if (character == "010110") {
    msg += "M";
  } else if (character == "010111") {
    msg += "N";
  } else if (character == "011000") {
    msg += "O";
  } else if (character == "011001") {
    msg += "P";
  } else if (character == "011010") {
    msg += "Q";
  } else if (character == "011011") {
    msg += "R";
  } else if (character == "011100") {
    msg += "S";
  } else if (character == "011101") {
    msg += "T";
  } else if (character == "011110") {
    msg += "U";
  } else if (character == "011111") {
    msg += "V";
  } else if (character == "100000") {
    msg += "W";
  } else if (character == "100001") {
    msg += "X";
  } else if (character == "100010") {
    msg += "Y";
  } else if (character == "100011") {
    msg += "Z";
  } else if (character == "100100") {
    msg += " ";
  } else if (character == "111111") {
    clearDisplay();
    lcd.print("Clearing");
    lcd.setCursor(0, 1);
    lcd.print("Message");
    delay(3000);
    msg = "";
    clearDisplay();
  } else {
    clearDisplay();
    lcd.print("Error.");
    lcd.setCursor(0, 1);
    lcd.print("Wrong input.");
    delay(3000);
    clearDisplay();
  }
}
 
