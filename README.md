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
int bitA = 13;
int bitB = 12;
int bitC = 11;
int bitD = 10;
int bitE = 9;

void setup()
{
  Serial.begin(9600);
  pinMode(bitA, OUTPUT);
  pinMode(bitB, OUTPUT);
  pinMode(bitC, OUTPUT);
  pinMode(bitD, OUTPUT);
  pinMode(bitE, OUTPUT);
  
  for (int n = 0; n <= 31; n++) {
  	//bit E
    if (n % 2 == 1) {
    	digitalWrite(bitE, HIGH);
  	}else
    {
      digitalWrite(bitE, LOW);
    }
    //bit D 
    if (n % 4 > 1) {
      digitalWrite(bitD, HIGH);
     }else
    {
      digitalWrite(bitD, LOW);
    }
     //bit C
    if (n % 8 > 3) {
      digitalWrite(bitC, HIGH);
    }else
    {
      digitalWrite(bitC, LOW);
    }
     //bit B
    if (n % 16 > 7) {
      digitalWrite(bitB, HIGH);
    }else
    {
      digitalWrite(bitB, LOW);
    }
     //bit A
    if (n % 32 > 15) {
      digitalWrite(bitA, HIGH);
    }else
    {
      digitalWrite(bitA, LOW);
    }
    delay(2000);
  }
}


void loop()
{
  
}
```
The wiring for this problem is:
![WiringBinaryCounter](wiringBinaryCounter.png)

### What is usability?
Usability according to [1] is part of the users experience. Process of designing a product with the user
Evaluation
----------





Improvements
----------
