![CoverPhoto](mars.jpg)

Unit 2 project: Communication to the Moon and Mars
==================================================

Creating a communication and translation software system to communicate between the Earth, Moon and Mars.


Contents
-----
  1. [Planning](#planning)
  1. [Design](#design)
  1. [Development](#development)
  1. [Evalution](#evaluation)
  1. [Improvements](#improvements)


Planning
----------
### Definition of the problem
There are 3 different stations, each being on a different planet/moon in the solar system. One is on Earth, one is on the Moon and the last one is on Mars. The station on Earth can only communicate using Morse code, the station in the Moon can only communicate in Binary code. Communication with the station in Mars must be provided. This will be tested here on campus, between 3 different houses.

Any station can only communicate in their "language". For example, the station on Mars must communicate back to the Moon through binary. Also, its important that the station on Earth **can't** communicate with the station on Mars, it had to go through the Moon.

Another challenge is that none of the people at the stations know morse or binary by heart, meaning everything has to be translated to and from English, and be received as English as well.

The last requirement of the system is that the input method of English characters to create the message only uses **2** push buttons. 

Success Criteria
1. The system has an easy to use user interface on all parts
1. The messages are translated flawslessly between the languages
1. The messages are transmitted flawlessly between the source and receiver


Design
----------

A diagram of the flow of information looks like this:
![PlanetDiagram](planetDiagram.png)








Development
----------

The most important part of the development is the translations in between English, morse and binary. People will have to understand both morse and binary communication in order to complete this project.


### Communication with binary
Binary is a number expressed in the base-2 numeral system or binary numeral system, which uses only two symbols: typically "0" (zero) and "1" (one).

Each digit is referred as a bit
* Using 1 bit, you can display 2 numbers (0-1).
* Using 2 bits, you can display 4 numbers (0-3)
* Using 3 bits, you can display 8 numbers (0-7)
* Using 4 bits, you can display 16 numbers (0-15)
etc...

**Converting a number from binary to decimal**
1. Write down the binary number
1. Multiply the LSB (Least significant bit - furthest to the right) with 2 to the power of the position number (meaning first bit = 2^1, second bit = 2^2, third bit 2^3 etc.)
1. Continue doing step 2 until reaching the MSB (most significant bit - furthest to the left)
1. Add all the numbers together to find the decimal output


**To convert a number from decimal to binary, the flowchart below must be used:**
![flowchartDecToBin](decimalToBinaryFlowchart.jpg)


#### Counting to 31, with decimal input to binary output
The code below shows how one could code from 0 to 31 with binary. The output (binary) is represented as lights either being on or off.
```.c
// Ports for the different LEDs
// Led nr. counted from the right -> left
int led5 = 13;
int led4 = 12;
int led3 = 11;
int led2 = 10;
int led1 = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

int i = 1;

void loop()
{
  for (i=1; i<=31; i++) {
    Serial.print("Num: ");
    Serial.println(i);
    
    // Condition for the first led
    if (i % 2 != 0) {
      digitalWrite(led1, HIGH);
    }
    // Condition for the second led
    if (i % 4 > 1) {
      digitalWrite(led2, HIGH);
    }
    // Condition for the third led
    if (i % 8 > 3) {
      digitalWrite(led3, HIGH);
    }
    // Condition for the fourth led
    if (i % 16 > 7) {
      digitalWrite(led4, HIGH);
    }
    // Condition for the fifth led
    if (i % 32 > 15) {
      digitalWrite(led5, HIGH);
    }
    
    // Resets everything
    delay(1000);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    delay(300);
    
  }
  // Delay 3 sec before next counting
  delay(3000);
}
```
The wiring for this problem is:
![WiringBinaryCounter](wiringBinaryCounter.png)


Evaluation
----------





Improvements
----------
