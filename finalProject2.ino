/*Brad Cortright 
  Final Project Code Pt 2
  This code is for the Duemilanova that takes input from the 
  buttons and sends that data to the Uno
*/

//5 buttons; 10 initial state variables to use for debounce (2 per button); 
//5 button state variables
int button1 = 10, button2 = 9, button3 = 8, button4 = 7, button5 = 6;
int valBut1a, valBut2a, valBut3a, valBut4a, valBut5a;
int valBut1b, valBut2b, valBut3b, valBut4b, valBut5b;
int buttonState1, buttonState2, buttonState3, buttonState4, buttonState5;

void setup() {
  Serial.begin(9600);
  //setup buttons for input
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);

  //read initial button states
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  buttonState4 = digitalRead(button4);
  buttonState5 = digitalRead(button5);
}


void loop() {
  //get two button state readings for each button
  //to compare and avoid debounce 
  //button1 vals
  valBut1a = digitalRead(button1);
  delay(10);
  valBut1b = digitalRead(button1);
  //button 2 vals
  valBut2a = digitalRead(button2);
  delay(10);
  valBut2b = digitalRead(button2);
  //button 3 vals
  valBut3a = digitalRead(button3);
  delay(10);
  valBut3b = digitalRead(button3);
  //button 4 vals
  valBut4a = digitalRead(button4);
  delay(10);
  valBut4b = digitalRead(button4);
  //button 5 vals
  valBut5a = digitalRead(button5);
  delay(10);
  valBut5b = digitalRead(button5);
  
  //compare button states recorded above, if same: check if button state has 
  //changed, if so check if button was pressed. If all this is true then send 
  //value of LED "linked" to the button (button 1 and 1st LED in row are "linked")
  //do so for all buttons pushed
  //NOTE: see the comments in Uno code for explanation
  if(valBut1a == valBut1b){
     if( valBut1a != buttonState1){
       if (valBut1a == LOW)
    Serial.println(2);
     } 
  }
  
   if(valBut2a == valBut2b){
     if( valBut2a != buttonState2){
       if (valBut2a == LOW)
    Serial.println(3);
     } 
  }
  
  if(valBut3a == valBut3b){
     if( valBut3a != buttonState3){
       if (valBut3a == LOW)
    Serial.println(4);
     } 
  }
  
  if(valBut4a == valBut4b){
     if( valBut4a != buttonState4){
       if (valBut4a == LOW)
    Serial.println(5);
     } 
  }
  
  if(valBut5a == valBut5b){
     if( valBut5a != buttonState5){
       if (valBut5a == LOW)
    Serial.println(6);
     } 
  }

   delay(75);
     buttonState1= valBut1a;
     buttonState2= valBut2a;
     buttonState3= valBut3a;
     buttonState4= valBut4a;
     buttonState5= valBut5a;
}
