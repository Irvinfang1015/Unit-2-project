// This program serves as an input method for the english language, using only 2 buttons. 
// When button A is pressed, the selection in focus is changed, through a rotation in a list. 
// If button B is pressed, the character or action is selected, and catenated to the final word. 
// “SEND” and “DEL” are actions. 
#include <LiquidCrystal.h>

String text = "";
int index = 0; 
// add all the letters and digits to the keyboard
String keyboard[] = {"SEND", "E", "T", "A", "O", "I", "N", "S", "R", "H", "L", "D", "C", "U", "M", "F", "P", "G", "W", "Y", "B", "V", "K", "X", "J", "Q", "Z", "SPACE", "DEL", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int letter;
int numOptions = 39; 
int Aled = 10;


LiquidCrystal lcd(13, 12, 7, 6, 5, 4);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  attachInterrupt(0, changeLetter, RISING);//button A in port 2
  attachInterrupt(1, selected, RISING);//button B in port 3
  pinMode(Aled, OUTPUT);
  lcd.setCursor(0, 1);
  lcd.print("Starting");
  delay(1000);
  lcd.clear();
  
  
}

void loop()
{
  
  lcd.setCursor(0, 0);
  lcd.print(keyboard[index]);
  
  lcd.setCursor(0, 1);
  lcd.print(text);
  delay(100);
  lcd.clear();
  
}



void changeLetter(){
  index++;
  // The if condition is checking if the user has gone through the whole list
  // If yes, the character selection is reset to the first index (0).
  if (index>numOptions){
  	index=0; 
  } 
}


void selected(){
  String key = keyboard[index];
  // If DEL key is selected, remove last appended char to text
  if (key == "DEL") {
    int len = text.length();
    text.remove(len-1);
  }
  // If SEND is selected, reset the text variable to ""
  else if (key == "SEND") {
    Serial.println("Message sent");
    lcd.clear();
    lcd.print("Message sent");
    
    
    for (int i=0; i<text.length(); i++){
      letter = text[i];
      Serial.print(letter);
      switch (letter) {
    	case 'A':
        	dot();
      		dash( );
        	delay(300000);
            break;
    	case 'B':
     		dash();
        	dot();
        	dot();
        	dot();
        	delay(300000);
            break;
    	case 'C':
      		dash();
         	dot();
      		dash();
         	dot();
        	delay(300000);
            break;
    	case 'D':
       		dash();
          	dot();
          	dot();
        	delay(300000);
            break;
    	case 'E':
         	dot();
        	delay(300000);
            break;
    	case 'F':
        	dot();
        	dot();
     		dash();
        	dot();
        	delay(300000);
            break;
    	case 'G':
     		dash();
     		dash();
       		dot();
        	delay(300000);
            break;
    	case 'H':
       		dot();
       		dot();
       		dot();
       		dot();
        	delay(300000);
            break;
    	case 'I':
       		dot();
       		dot();
        	delay(300000);
            break;
    	case 'J':
        	dot();
     		dash();
     		dash();
     		dash();
        	delay(300000);
            break;
    	case 'K':
     		dash();
        	dot();
     		dash();
        	delay(300000);
            break;
    	case 'L':
        	dot();
     		dash();
       		dot();
       		dot();
        	delay(300000);
            break;
    	case 'M':
     		dash();
     		dash();
        	delay(300000);
            break;
    	case 'N':
     		dash();
        	dot();
        	delay(300000);
            break;
    	case 'O':
     		dash();
     		dash();
     		dash();
        	delay(300000);
            break;
    	case 'P':
       		dot();
     		dash();
     		dash();
       		dot();
        	delay(300000);
            break;
    	case 'Q':
     		dash();
     		dash();
        	dot();
     		dash();
        	delay(300000);
            break;
    	case 'R':
        	dot();
     		dash();
      		dot();
        	delay(300000);
            break;
    	case 'S':
      		dot();
      		dot();
      		dot();
        	delay(300000);
            break;
    	case 'T':
     		dash();
        	delay(300000);
            break;
    	case 'U':
      		dot();
      		dot();
     		dash();
        	delay(300000);
            break;
    	case 'V':
      		dot();
      		dot();
      		dot();
     		dash();
        	delay(300000);
            break;
    	case 'W':
      		dot();
     		dash();
     		dash();
        	delay(300000);
            break;
    	case 'X':
     		dash();
      		dot();
      		dot();
     		dash();
        	delay(300000);
            break;
    	case 'Y':
     		dash();
      		dot();
     		dash();
     		dash();
        	delay(300000);
            break;
    	case 'Z':
     		dash();
     		dash();
      		dot();
      		dot();
        	delay(300000);
            break;
    	case '0':
     		dash();
     		dash();
     		dash();
     		dash();
     		dash();
        	delay(300000);
            break;
    	case '1':
      		dot();
     		dash();
     		dash();
     		dash();
     		dash();
        	delay(300000);
            break;
    	case '2':
      		dot();
      		dot();
     		dash();
     		dash();
     		dash();
        	delay(300000);
            break;
    	case '3':
      		dot();
      		dot();
      		dot();
     		dash();
     		dash();
        	delay(300000);
            break;
    	case '4':
      		dot();
      		dot();
      		dot();
      		dot();
     		dash();
        	delay(300000);
            break;
    	case '5':
      		dot();
      		dot();
      		dot();
      		dot();
      		dot();
        	delay(300000);
            break;
    	case '6':
     		dash();
      		dot();
      		dot();
      		dot();
      		dot();
        	delay(300000);
            break;
    	case '7':
     		dash();
     		dash();
      		dot();
      		dot();
      		dot();
        	delay(300000);
            break;
    	case '8':
     		dash();
     		dash();
     		dash();
      		dot();
      		dot();
        	delay(300000);
            break;
    	case '9':
        	dash();
         	dash();
         	dash();
         	dash();
         	dot();
        	delay(300000);
            break;
      }
    }
    text  = "";
  }else if (key == "SPACE") {
   text+= " ";
  }
  else {
    text += key; // Append char to message
  }
  // Always reset index of array after selection
  index = 0;
}
    
void dot(){
  //in this function blink the light for one second
  Serial.print("I am at dot function");
  digitalWrite(Aled, HIGH);
  delay(100000);
  digitalWrite(Aled, LOW);
  delay(100000);
}
    
void dash(){
  //in this function blink the light for three second
    Serial.print("I am at dash function");

  digitalWrite(Aled, HIGH);
  delay(300000);
  digitalWrite(Aled, LOW);
  delay(100000);  
}

