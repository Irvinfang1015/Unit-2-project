#include <LiquidCrystal.h>
int index = 0; 
// add all the letters and digits to the keyboard
String keyboard[]={"SEND","A", "B","C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "SEND", "DEL", "SPACE"};
String text = "";
int numOptions = 40;
int ledPort=8;
int ledPort2=9;
char letters;



// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

void setup() {
  // set up the LCD's number of columns and rows:
  Serial.begin(9600);
  lcd.begin(16,2);
  // Print a message to the LCD.
  attachInterrupt(0, changeLetter, RISING);//button A in port 2
  attachInterrupt(1, selected, RISING);//button B in port 3
  pinMode(ledPort, OUTPUT);
  pinMode(ledPort2, OUTPUT);
  
   
 
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(keyboard[index]);
  lcd.setCursor(0, 1);
  lcd.print(text);
  delay(100);
  digitalWrite(13, HIGH);
}

//This function changes the letter in the keyboard
void changeLetter(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200)
  {
  
    last_interrupt_time = interrupt_time;// If interrupts come faster than 200ms, assum
    index++;
      //check for the max row number
    if(index==numOptions){
      index=0; //loop back to first row
    } 
 }
}

//this function adds the letter to the text or send the msg
void selected(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200)
  {
  
    last_interrupt_time = interrupt_time;// If interrupts come faster than 200ms, assum
    
    String key = keyboard[index];
    if (key == "DEL")
    {
      int len = text.length();
      text.remove(len-1);
    }
    else if(key == "SEND")
    {
      convertbin();
      text="";
    }
    else if(key == "SPACE")
    {
     text += " ";
    }else{
      text += key;
    }
    index = 0; //restart the index
  }
  
}

void convertbin(){

// if 2 lights ON = 1, if 1 light ON = 0
// if 2 lights OFF break
// if 1 light ON 1s  = 0, if 1 lights ON 2s = 00…
//  if 2 light ON 1s  = 1, if 1 lights ON 2s = 11…
  
  String code; 
  for(int i=0; i<text.length();i++){
    letters = text[i];
    Serial.print(letters);
      switch (letters) {

         case 'A':
           //code  = "001010";

         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         
         break;
      
       case 'B':
         //code = "001011"; 
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
         
       case 'C':
         //code = "001100";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
         
       case 'D': 
         //code = "001101";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
         
       case 'E': 
         //code = "001110";
          digitalWrite(ledPort, LOW);
          digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'F': 
         //code = "001111";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
       case 'G': 
         //code = "010000";
          digitalWrite(ledPort, LOW);
          digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'H': 
         //code = "010001";
          digitalWrite(ledPort, LOW);
          digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
     
       case 'I': 
         //code = "010010";
          digitalWrite(ledPort, LOW);
          digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'J': 
         //code = "010011";
          digitalWrite(ledPort, LOW);
          digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'K': 
         //code = "010100";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'L': 
         //code = "010101";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'M': 
         //code = "010110";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'N':
         //code = "010111"; 
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'O':
         //code = "011000";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'P':
         //code = "011001";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'Q':
         //code = "011010";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'R':
         //code = "011011";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'S':
        //code = "011100";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'T':
        //code = "011101";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
    
       case 'U':
         //code = "011110";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'V':
         //code= "011111";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'W':
         //code = "100000";
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'X':
         //code = "100001";
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'Y':
         //code = "100010";
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case 'Z':
         //code = "100011"; 
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
       
       case '0': 
         //code = "000000";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
        
       case '1': 
         //code = "000001"; 
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case '2': 
         //code = "000010";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case '3': 
         //code = "000011";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case '4': 
         //code = "000100";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);        
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case '5': 
       //code = "000101";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case '6': 
         //code = "000110";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case '7': 
         //code = "000111";
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, LOW);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000); 
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
      
       case '8': 
        //code = "001000";
        digitalWrite(ledPort, LOW);
        digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;
                      
       case '9': 
        //code = "001001";  
      digitalWrite(ledPort, LOW);
      digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
       digitalWrite(ledPort, HIGH);
       digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, HIGH);
         digitalWrite(ledPort2, HIGH);
         delay(200000);
         digitalWrite(ledPort, LOW);
         digitalWrite(ledPort2, LOW);
         delay(200000);
         break;

         case 'space':
           //code = 000000
           digitalWrite(ledPort2, LOW);
           digitalWrite(ledPort2, LOW);
           delay(500000);



      }
  }
}

