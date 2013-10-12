
const int button1 = 12;

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

// long delays section
long waitUntilpulse1 = 0;
long waitUntilpulse2 = 20;

long waitUntilpolice1 = 0;
long waitUntilpolice2 = 200;

long waitUntilchase1 = 0;
long waitUntilchase2 = 100;
long waitUntilchase3 = 200;
long waitUntilchase4 = 300;

long waitUntilstrobe1 = 0;
long waitUntilstrobe2 = 20;

long waitUntilnight1 = 0;
long waitUntilnight2 = 100;
long waitUntilnight3 = 200;
long waitUntilnight4 = 300;
long waitUntilnight5 = 400;
long waitUntilnight6 = 500;


void setup() {
  // initialize the button pin as a input:
  pinMode(button1, INPUT);
  // initialize the LED pin as a output:
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
    if (millis() >= waitUntilpulse1) {
      analogWrite(redPin1, brightness);
      analogWrite(redPin2, brightness);
      analogWrite(yellowPin3, brightness);
      analogWrite(yellowPin4, brightness);
      brightness = brightness + fadeAmount;
      waitUntilpulse1 += 40;
    }
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ; 
    }
    if (millis() >= waitUntilpulse2) {
      analogWrite(redPin1, brightness);
      analogWrite(redPin2, brightness);
      analogWrite(yellowPin3, brightness);
      analogWrite(yellowPin4, brightness);
      brightness = brightness + fadeAmount;
      waitUntilpulse2 += 40;
    }
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ; 
    }   
  }
  
  if (buttonPushCounterm == 3) {
    // Police flashing mode
    if (millis() >= waitUntilpolice1) {
      digitalWrite(redPin2, LOW);
      digitalWrite(yellowPin4, LOW);
      digitalWrite(redPin1, HIGH);
      digitalWrite(yellowPin3, HIGH);
      waitUntilpolice1 += 400;
    }
    if (millis() >= waitUntilpolice2) {
      digitalWrite(redPin2, HIGH);
      digitalWrite(yellowPin4, HIGH);
      digitalWrite(redPin1, LOW);
      digitalWrite(yellowPin3, LOW);
      waitUntilpolice2 += 400;
    }
  }
  
  if (buttonPushCounterm == 4) {
    // Chase mode
    if (millis() >= waitUntilchase1) {
      digitalWrite(redPin2, LOW);
      digitalWrite(redPin1, LOW);
      digitalWrite(yellowPin4, LOW);
      digitalWrite(yellowPin3, HIGH);
      waitUntilchase1 += 400;  
      }
    if (millis() >= waitUntilchase2) {
      digitalWrite(yellowPin3, LOW);
      digitalWrite(yellowPin4, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(redPin1, HIGH);
      waitUntilchase2 += 400;
     }
    if (millis() >= waitUntilchase3) {
      digitalWrite(yellowPin3, LOW);
      digitalWrite(redPin1, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(yellowPin4, HIGH);
      waitUntilchase3 += 400;
     }
    if (millis() >= waitUntilchase4) {
      digitalWrite(redPin1, LOW);
      digitalWrite(yellowPin4, LOW);
      digitalWrite(yellowPin3, LOW);
      digitalWrite(redPin2, HIGH);
      waitUntilchase4 += 400;
    }
  }
  
  if (buttonPushCounterm == 5) {
    // Strobe mode
    if (millis() >= waitUntilstrobe1) {
      digitalWrite(redPin1, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(yellowPin3, LOW);
      digitalWrite(yellowPin4, LOW);
      waitUntilstrobe1 += 40;
    }
    if (millis() >= waitUntilstrobe2) {
      digitalWrite(redPin1, HIGH);
      digitalWrite(redPin2, HIGH);
      digitalWrite(yellowPin3, HIGH);
      digitalWrite(yellowPin4, HIGH);
      waitUntilstrobe2 += 40;
    }
  }
  
  if (buttonPushCounterm == 6) {
    // Night rider mode
    if (millis() >= waitUntilnight1) {
      digitalWrite(yellowPin4, LOW);
      digitalWrite(redPin1, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(yellowPin3, HIGH);
      waitUntilnight1 += 600;
    }
    if (millis() >= waitUntilnight2) {
      digitalWrite(yellowPin3, LOW);
      digitalWrite(yellowPin4, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(redPin1, HIGH);
      waitUntilnight2 += 600;
    }
    if (millis() >= waitUntilnight3) {
      digitalWrite(yellowPin3, LOW);
      digitalWrite(redPin1, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(yellowPin4, HIGH);
      waitUntilnight3 += 600;
    }
    if (millis() >= waitUntilnight4) {
      digitalWrite(redPin1, LOW);
      digitalWrite(yellowPin4, LOW);
      digitalWrite(yellowPin3, LOW);
      digitalWrite(redPin2, HIGH);
      waitUntilnight4 += 600;
    }
    if (millis() >= waitUntilnight5) {
      digitalWrite(redPin2, LOW);
      digitalWrite(redPin1, LOW);
      digitalWrite(yellowPin3, LOW);
      digitalWrite(yellowPin4, HIGH);
      waitUntilnight5 += 600;
    }
    if (millis() >= waitUntilnight6) {
      digitalWrite(yellowPin3, LOW);
      digitalWrite(yellowPin4, LOW);
      digitalWrite(redPin2, LOW);
      digitalWrite(redPin1, HIGH);
      waitUntilnight6 += 600;
    }
  }
  
  if (buttonPushCounterm == 7) {
    // Off mode
    digitalWrite(redPin1, LOW);
    digitalWrite(redPin2, LOW);
    digitalWrite(yellowPin3, LOW);
    digitalWrite(yellowPin4, LOW);
  }
}
