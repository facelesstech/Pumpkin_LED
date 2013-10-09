
const int button1 = 12;
//const int buttonm = A1;

// Variables will change:
int buttonPushCounterm = 0;
int buttonStatem = 0;
int lastButtonStatem = 0;
int redPin1 = 3;
int redPin2 = 9;
int yellowPin3 = 6;
int yellowPin4 = 10;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by


void setup() {
  // initialize the button pin as a input:
  pinMode(button1, INPUT);
  pinMode(redPin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(yellowPin3, OUTPUT);
  pinMode(yellowPin4, OUTPUT);
  
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  // read the pushbutton input pin:
 buttonStatem = digitalRead(button1); 
  // compare the buttonState to its previous state
  if (buttonStatem != lastButtonStatem) {
    // if the state has changed, increment the counter
    if (buttonStatem == HIGH) {
      // if the current state is HIGH then the button
      // went from off to on:
      buttonPushCounterm++;
      if (buttonPushCounterm == 8) {
        buttonPushCounterm = 1;}
      Serial.println("on");
      Serial.print("number of button pushes:  ");
      Serial.println(buttonPushCounterm, DEC);
    } 
    else {
      // if the current state is LOW then the button
      // went from on to off:
      Serial.println("off"); 
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonStatem = buttonStatem;

  if (buttonPushCounterm == 1) {
    // Candle mode
     analogWrite(redPin1, random(10)+255);
     analogWrite(redPin2, random(10)+255);
     analogWrite(yellowPin3, random(10)+255);
     analogWrite(yellowPin4, random(10)+255);
   }
  
  if (buttonPushCounterm == 2) {
    // Pulse mode
    analogWrite(redPin1, brightness);
    analogWrite(redPin2, brightness);
    analogWrite(yellowPin3, brightness);
    analogWrite(yellowPin4, brightness);
    brightness = brightness + fadeAmount;
    if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(50);            
  }
  
  if (buttonPushCounterm == 3) {
    // Police flashing mode
    digitalWrite(redPin2, LOW);
    digitalWrite(yellowPin4, LOW);
    digitalWrite(redPin1, HIGH);
    digitalWrite(yellowPin3, HIGH);
    delay(200);
    digitalWrite(redPin2, HIGH);
    digitalWrite(yellowPin4, HIGH);
    digitalWrite(redPin1, LOW);
    digitalWrite(yellowPin3, LOW);
    delay(200);
  }
  
  if (buttonPushCounterm == 4) {
    // Chase mode
    digitalWrite(redPin2, LOW);
    digitalWrite(redPin1, LOW);
    digitalWrite(yellowPin4, LOW);
    digitalWrite(yellowPin3, HIGH);
    delay(200);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(yellowPin4, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(redPin1, HIGH);
    delay(200);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(redPin1, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(yellowPin4, HIGH);
    delay(200);
    digitalWrite(redPin1, LOW);
    digitalWrite(yellowPin4, LOW);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(redPin2, HIGH);
    delay(200);
  }
  
  if (buttonPushCounterm == 5) {
    // Strobe mode
    digitalWrite(redPin1, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(yellowPin4, LOW);
    delay(50);
    digitalWrite(redPin1, HIGH);
    digitalWrite(redPin2, HIGH);
    digitalWrite(yellowPin3, HIGH);
    digitalWrite(yellowPin4, HIGH);
    delay(50);
  }
  
  if (buttonPushCounterm == 6) {
    
    digitalWrite(yellowPin4, LOW);
    digitalWrite(redPin1, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(yellowPin3, HIGH);
    delay(200);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(yellowPin4, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(redPin1, HIGH);
    delay(200);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(redPin1, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(yellowPin4, HIGH);
    delay(200);
    digitalWrite(redPin1, LOW);
    digitalWrite(yellowPin4, LOW);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(redPin2, HIGH);
    delay(200);
    digitalWrite(redPin2, LOW);
    digitalWrite(redPin1, LOW);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(yellowPin4, HIGH);
    delay(200);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(yellowPin4, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(redPin1, HIGH);
    delay(200);
  }
  
  if (buttonPushCounterm == 7) {
    // Off mode
    digitalWrite(redPin1, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(yellowPin4, LOW);
  }
}
