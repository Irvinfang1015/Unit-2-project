// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 7, 6);
String text = " ";
int butA = 3;
int butB = 2;
int counter = 0;
String letter = " ";

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Enter morse msg");
  pinMode(butA, INPUT);
  pinMode(butB, INPUT);
  attachInterrupt(1, dot, RISING);
  attachInterrupt(0, dash, RISING);
}

void loop() {
  delay(100);
  counter++;
  if(counter == 20){
    translate();
  }
  else if(counter == 50){
    send();
  }
}
 
void dot()
{
  lcd.clear();
  letter += ".";
  lcd.print(letter);
  counter = 0;
}

void dash()
{
  lcd.clear();
  letter += "-";
  lcd.print(letter);
  counter = 0;
}
  
// IRVIN DO THIS PART
void translate()
{
  //A
  if (letter == " .-"){
    text += "a";
  }
  
  //B
  if (letter == " -..."){
    text += "b";
  }
  
  //C
  if (letter == " -.-."){
    text += "c";
  }
  
  //D
  if (letter == " -.."){
    text += "d";
  }
  
  //E
  if (letter == " ."){
    text += "e";
  }
  
  //F
  if (letter == " ..-."){
    text += "f";
  }
  
  //G
  if (letter == " --."){
    text += "g";
  }
  
  //H
  if (letter == " ...."){
    text += "h";
  }
  
  //I
  if (letter == " .."){
    text += "i";
  }
  
  //J
  if (letter == " .---"){
    text += "j";
  }
  
  //K
  if (letter == " -.-"){
    text += "k";
  }
  
  //L
  if (letter == " .-.."){
    text += "l";
  }
  
  //M
  if (letter == " --"){
    text += "m";
  }
  
  //N
  if (letter == " -."){
    text += "n";
  }
  
  //O
  if (letter == " ---"){
    text += "o";
  }
  
  //P
  if (letter == " .--."){
    text += "p";
  }
  
  //Q
  if (letter == " --.-"){
    text += "q";
  }
  
  //R
  if (letter == " .-."){
    text += "r";
  }
  
  //S
  if (letter == " ..."){
    text += "s";
  }
  
  //T
  if (letter == " -"){
    text += "t";
  }
  
  //U
  if (letter == " ..-"){
    text += "u";
  }
  
  //V
  if (letter == " ...-"){
    text += "v";
  }
  
  //W
  if (letter == " .--"){
    text += "w";
  }
  
  //X
  if (letter == " -..-"){
    text += "x";
  }
  
  //y
  if (letter == " -.--"){
    text += "y";
  }
  
  //Z
  if (letter == " --.."){
    text += "z";
  }
  
  //1
  if (letter == " .----"){
    text += "1";
  }
  
  //2
  if (letter == " ..---"){
    text += "2";
  }
  
  //3
  if (letter == " ...--"){
    text += "3";
  }
  
  //4
  if (letter == " ....-"){
    text += "4";
  }
  
  //5
  if (letter == " ....."){
    text += "5";
  }
  
  //6
  if (letter == " -...."){
    text += "6";
  }
  
  //7
  if (letter == " --..."){
    text += "7";
  }
  
  //8
  if (letter == " ---.."){
    text += "8";
  }
  
  //9
  if (letter == " ----."){
    text += "9";
  }
  
  //0
  if (letter == " -----"){
    text += "";
  }
  
  //.
  if (letter == " .-.-.-"){
    text += ".";
  }
  
  //,
  if (letter == " --..--"){
    text += ",";
  }
  
  //?
  if (letter == " ..--.."){
    text += "?";
  }
  lcd.setCursor(0,1);
  lcd.print(text);
  letter = " ";
}

void send()
{
  lcd.clear();
  lcd.print(text);
  text = " ";
  letter = " ";
}

