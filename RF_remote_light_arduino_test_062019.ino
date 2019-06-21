// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

int lastButton = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(12,INPUT);

  //Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
//read the button
 // read the state of the switch into a local variable:
  int reading = digitalRead(12);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:
    buttonState = reading;
  }
  

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;

//



if(buttonState && !lastButton){
  //Serial.println("on");
  


  for (int i = 2; i < 7; i++) {

    for (int j = 0; j < 3; j++) {
      digitalWrite(i, HIGH);
      delay(50);
      digitalWrite(i, LOW);
      delay(50);
    }
    delay(300);

    
  for (int i = 2; i < 7; i++) {

    for (int j = 0; j < 3; j++) {
      digitalWrite(i, HIGH);
      delay(50);
      digitalWrite(i, LOW);
      delay(50);
    }
    delay(300);


  }
}

else if(!buttonState && lastButton){

  //Serial.println("off");
   for (int i = 7; i < 12; i++) {

    for (int j = 0; j < 3; j++) {
      digitalWrite(i, HIGH);
      delay(50);
      digitalWrite(i, LOW);
      delay(50);
    }
    delay(300);


   for (int i = 7; i < 12; i++) {

    for (int j = 0; j < 3; j++) {
      digitalWrite(i, HIGH);
      delay(50);
      digitalWrite(i, LOW);
      delay(50);
    }
    delay(300);


  }
} 



lastButton = buttonState;

}
