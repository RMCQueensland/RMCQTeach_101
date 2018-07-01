/*  This sketch is designed to teach Arduino basics. It incorporates      - An Arduino device (in my case Pro Mini),      - A breadboard, some jumper wires,      - A sensor (momentary button),      - An LED,      - A feedback switch (micro switch),      - Some resistors (470R), and      - A servo.        This is the full program in its end state. During the class, the components are built up to show the differing     aspects as the components are added to the circuit and the program written.        Stage 1 - Light an LED using the blink program    - Add the LED to the positive rail of the breadboard,    - Add a resistor from the other LED lead to the output Arduino pin D10,    - Write S1 code to make the LED blink, upload and test.        Stage 2 - Add a pushbutton and lite the LED when the button is pressed    - Retain the LED cct as is,    - Add a push button to the cct with one side grounded and the other side connected to Arduino pin D9    - Write S2 code to make the LED on when the button is pressed    *///Setup constants here//S1#define LEDpin 10     //Defines the pin the LED is attached to//S2#define buttonPin 9   //Defines the pin the push button is attached to//Variables//S2boolean buttonState = HIGH;   //Variable to hold the push button statevoid setup() {  //S1  pinMode(LEDpin, OUTPUT);  //Setup the pin connected to the LED as an output  //S2  pinMode(buttonPin, INPUT_PULLUP); //Setup the pin connected to the push button as an input  }void loop() {  //S2  //Read the pushbutton state and change the state of the LED to match. With no button press the LED will be off  buttonState = digitalRead(buttonPin); //Update the buttonState variable with the push button state. When pressed the pin will be LOW    if(!buttonState || buttonState == LOW){ //Change the state of the LED in response to a button press    digitalWrite(LEDpin, LOW);            //Turn the LED on  } else {    digitalWrite(LEDpin, HIGH);           //Turn the LED off  }  } 