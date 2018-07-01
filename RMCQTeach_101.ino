/*  This sketch is designed to teach Arduino basics. It incorporates      - An Arduino device (in my case Pro Mini),      - A breadboard, some jumper wires,      - A sensor (momentary button),      - An LED,      - A feedback switch (micro switch),      - Some resistors (470R), and      - A servo.        This is the full program in its end state. During the class, the components are built up to show the differing     aspects as the components are added to the circuit and the program written.        Stage 1 - Light an LED using the blink program    - Add the LED to the positive rail of the breadboard,    - Add a resistor from the other LED lead to the output Arduino pin D10,    - Write S1 code to make the LED blink, upload and test.        Stage 2 - Add a pushbutton and lite the LED when the button is pressed    - Retain the LED cct as is,    - Add a push button to the cct with one side grounded and the other side connected to Arduino pin D9    - Write S2 code to make the LED on when the button is pressed        Stage 3 - Add a servo that toggle position with a button press    - Retain the LED and push button cct as is,    - add a SG90 servo, make the following connection:      - +5V to power wire of the Servo,      - GND to Common wire of the servo (usualiy the centre one), and      - Arduino Pin D11 to the Control wire of the servo.    - Write the S3 code to make the servo move        Stage 4 - Add a slow movement of the servo to the program    - Retain the LED, push button and the servo cct as is,    - Write the S4 code to add slow motion to the servo when it changes        Stage 5 - Add the servo position feedback to control the LED     - Retain the LED, push button and the servo cct as is,     - Add the micro switch on the servo mount assembly to the cct by:      - NC (norm closed) leg to +5 rail,      - NO (norm open) leg to GND, and      - Common to Arduino Pin D8.    Write the S5 code to the switch feedback and control the LED*///Includes//S3#include <Servo.h>Servo myServo;  // create servo object to control a servo//Setup constants here//S1#define LEDpin 10     //Defines the pin the LED is attached to//S2#define buttonPin 9   //Defines the pin the push button is attached to//S3#define servoPin 11   //Defines the pin the servo is attached to//S4const int rateOfChange = 10; //Defines the delay for each of the servo movementsconst int servoHigh = 110; //Defines the position of the servo in the high positionconst int servoLow = 50;   //Defines the position of the servo in the low position//S5#define switchPin 8   //Define the pin for the feedback micro switch//Variables//S2boolean buttonState = HIGH;   //Variable to hold the push button state//S3boolean servoState = HIGH;    //Variable to hold the servo statusboolean toggle = HIGH;        //Variable to hold the command for the servo to movevoid setup() {  //S1  pinMode(LEDpin, OUTPUT);  //Setup the pin connected to the LED as an output  //S2  pinMode(buttonPin, INPUT_PULLUP); //Setup the pin connected to the push button as an input  //S3  myServo.attach(servoPin);  // attaches the servo on pin 11 to the servo object  //S4  myServo.write(servoHigh);   //Set the servo in the high position as a starting point  //S5  pinMode(switchPin, INPUT); //Setup the pin connected to the feedback switch as an input}void loop() {  //S1  digitalWrite(LEDpin, LOW);  //Turn the LED on  delay(1000);  //Tell the program to wait for 1s  digitalWrite(LEDpin, HIGH); //Turn the LED off  delay(1000);  //Tell the program to wait for 1s    //S2 - remove all of the S1 code  //Read the pushbutton state and change the state of the LED to match. With no button press the LED will be off  buttonState = digitalRead(buttonPin); //Update the buttonState variable with the push button state. When pressed the pin will be LOW    if(!buttonState || buttonState == LOW){ //Change the state of the LED in response to a button press    digitalWrite(LEDpin, LOW);            //Turn the LED on    toggle = LOW;                         //S3 - Tell the servo to move  } else {    digitalWrite(LEDpin, HIGH);           //Turn the LED off  }    //S3 - Retain all of the S2 code for now  //Read the read the push button state and each time it is pressed I want to toggle the servo back and forth  if(toggle == LOW && servoState == LOW){   //Change the position of the servo when the button is pressed    myServo.write(140);                     //make the servo move to the HIGH position      servoState = HIGH;                      //update the servoState variable to indicate the servo position    toggle = HIGH;                          //Update the toggle variable to indicate the position commanded by the button has occured  }   else   if(toggle == LOW && servoState == HIGH) { //Change the position of the servo when the button is pressed    myServo.write(20);                      //make the servo move to the LOW position    servoState = LOW;                       //update the servoState variable to indicate the servo position    toggle = HIGH;                          //Update the toggle variable to indicate the position commanded by the button has occured  }    //S4 - add rate of change to servo movements (replace the S3 code)  //Read the read the toggle state and each time which incidicates a press of the pubtton, move the servo back and forth  if(toggle == LOW && servoState == LOW){       //Change the position of the servo when the button is pressed from the low position to the high position    for(int x = servoLow; x >= servoHigh; ++x){ //Set a for loop to update the position of the servo in incremental steps      myServo.write(x);                         //Update the servo in incremental steps       delay(rateOfChange);    }    servoState = HIGH;                      //update the servoState variable to indicate the servo position    toggle = HIGH;                          //Update the toggle variable to indicate the position commanded by the button has occured  }   else   if(toggle == LOW && servoState == HIGH) {       //Change the position of the servo when the button is pressed from the high position to the low position    for(int x = servoHigh; x <= servoLow; --x){   //Set a for loop to update the position of the servo in incremental steps      myServo.write(x);                           //Update the servo in incremental steps    }    servoState = LOW;                       //update the servoState variable to indicate the servo position    toggle = HIGH;                          //Update the toggle variable to indicate the position commanded by the button has occured  }    //S5 - add feedback switch input to the program  //make the following changes to this part of the code  if(!buttonState || buttonState == LOW){ //Change the state of the LED in response to a button press    toggle = LOW;                         //S3 - Tell the servo to move  } else {                                          //Do nothing  }  //Add the code to control the LED based on the feedback switch  if(digitalRead(switchPin)){     //Change the state of the LED in response to a feedback switch    digitalWrite(LEDpin, LOW);    //Turn the LED on  } else {    digitalWrite(LEDpin, HIGH);   //Turn the LED off  }} 