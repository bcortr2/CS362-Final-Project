/*Brad Cortright 
  Final Project Code Pt 1
  This code is for the Uno that receives input from the 
  Duemilanove and controls the rest of the game
*/
#include <LiquidCrystal.h>
#include <stdio.h>
#include <stdlib.h>
#include <Time.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
//5 LEDs, where led2 is the first in the row of LEDs; these were named for their pins as that 
//seemed like it would be safer in terms of any pin issues in the future; sorry if that's confusing
//to read but it made sense to me
int led2 = 2, led3 = 3, led4 = 4, led5 = 5, led6 = 6;
//i is for all loops within levels; k is counter for input from buttons; startMsg is boolean 
//to determine whether to show start of program message; correctPat is boolean check for 
//correct input
int level = 1, sublevel = 0, randPin = 0, health = 2, i = 0, k = 0, correctPat = 0, startMsg = 1;
//pins keeps track of what leds were selected to light up, answer keeps track of input from buttons
//bonusLvlUsed is boolean to track whether user has had once-only bonus stage attempt
//correct is boolean stating whether input was found to be correct
int pins[20], answer[20], bonusLvlUsed = 0, correct = 0;
char *levelNum = "Level ", *healthStr = "Lives: ", *levelString = "" ;
char *startStr = "Welcome to the Pattern Matching Game!        ";
char *resultStr = "Let's see how you did....        ";
char *patternStartingStr = "Pay attention! Pattern beginning       ";
char *getReadyStr = "Get ready to enter your answer        ";
char *bonusStr = "Congratulations! You earned 1 life       ";
char *playAgainStr = "Would you like to play again?        ";
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  lcd.begin(16, 2);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  //zero out both arrays
  memset(pins, 0, sizeof(pins));
  memset(answer, 0, sizeof(answer));
}

/*
  All levels have a minimum number of LEDs that will be lit (the number of loops performed) and 
  a variable time to display each lit LED in the sequence (base for delay is alwasy 1000 across all levels
  All levels take the sublevel (determines base levels), milliMod (a float value-- from 0.0 to 0.99--used to modify the delay),
  and numLoops (the number--variable & arbitrary--to add to the base number of loops). The number added to 
  numLoops is the base number of loops to perform = base number of LEDs to light.
*/


 //In this level, the base number of loops (= LEDs) increases by 1 per sublevel
void level1 (int sublevel, float milliMod, int numLoops){
  switch (sublevel){
   case 0:
       for (i = 0; i<(numLoops + 4); ++i){
         pins[i] = random(2, 7);  
         Serial.print(pins[i]);
         digitalWrite(pins[i], HIGH);
         delay((int)1000*milliMod);
         digitalWrite(pins[i], LOW);
         delay((int)1000*milliMod);
       }
       break;
    case 1:
        for (i = 0; i < (numLoops + 5); ++i){
          pins[i] = random(2, 7);
          Serial.print(pins[i]);
          digitalWrite(pins[i], HIGH);
          delay((int)1000*milliMod);
          digitalWrite(pins[i], LOW);
          delay((int)1000*milliMod);
        }
       break;
     case 2:
         for (i = 0; i < (numLoops + 6); ++i){
          pins[i] = random(2, 7);
          Serial.print(pins[i]);
          digitalWrite(pins[i], HIGH);
          delay((int)1000*milliMod);
          digitalWrite(pins[i], LOW);
          delay((int)1000*milliMod);
        }
        break;
    default: break;
  }
}
//In this level, the base number of loops (= LEDs) increases  by 2 per sublevel
void level2 (int sublevel, float milliMod, int numLoops){
  switch (sublevel){
   case 0:
       for (i = 0; i<(numLoops + 6); ++i){
         pins[i] = random(2, 7);  
         Serial.print(pins[i]);
         digitalWrite(pins[i], HIGH);
         delay((int)1000*milliMod);
         digitalWrite(pins[i], LOW);
         delay((int)1000*milliMod);
       }
       break;
    case 1:
        for (i = 0; i < (numLoops + 8); ++i){
           pins[i] = random(2, 7);
           Serial.print(pins[i]);
           digitalWrite(pins[i], HIGH);
           delay((int)1000*milliMod);
           digitalWrite(pins[i], LOW);
           delay((int)1000*milliMod);
        }
        break;
     case 2:
         for (i = 0; i < (numLoops + 10); ++i){
           pins[i] = random(2, 7);
           Serial.print(pins[i]);
           digitalWrite(pins[i], HIGH);
           delay((int)1000*milliMod);
           digitalWrite(pins[i], LOW);
           delay((int)1000*milliMod);
        }
        break;
    default: break;
  }
}

//In this level, the base number of loops (= LEDs) stays static accross sublevels
void level3 (int sublevel, float milliMod, int numLoops){
  switch (sublevel){
   case 0:
       for (i = 0; i<(numLoops + 5); ++i){
         pins[i] = random(2, 7);  
         Serial.print(pins[i]);
         digitalWrite(pins[i], HIGH);
         delay((int)1000*milliMod);
         digitalWrite(pins[i], LOW);
         delay((int)1000*milliMod);
       }
       break;
    case 1:
        for (i = 0; i < (numLoops + 5); ++i){
           pins[i] = random(2, 7);
           Serial.print(pins[i]);
           digitalWrite(pins[i], HIGH);
           delay((int)1000*milliMod);
           digitalWrite(pins[i], LOW);
           delay((int)1000*milliMod);
        }
        break;
     case 2:
         for (i = 0; i < (numLoops + 5); ++i){
           pins[i] = random(2, 7);
           Serial.print(pins[i]);
           digitalWrite(pins[i], HIGH);
           delay((int)1000*milliMod);
           digitalWrite(pins[i], LOW);
           delay((int)1000*milliMod);
        }
        break;
    default: break;
  }
}

//In this level, the base number of loops (= LEDs) increases by 2 per sublevel
void level4 (int sublevel, float milliMod, int numLoops){
  switch (sublevel){
   case 0:
       for (i = 0; i<(numLoops + 6); ++i){
         pins[i] = random(2, 7);  
         Serial.print(pins[i]);
         digitalWrite(pins[i], HIGH);
         delay((int)1000*milliMod);
         digitalWrite(pins[i], LOW);
         delay((int)1000*milliMod);
       }
       break;
    case 1:
        for (i = 0; i < (numLoops + 8); ++i){
           pins[i] = random(2, 7);
           Serial.print(pins[i]);
           digitalWrite(pins[i], HIGH);
           delay((int)1000*milliMod);
           digitalWrite(pins[i], LOW);
           delay((int)1000*milliMod);
        }
        break;
     case 2:
         for (i = 0; i < (numLoops + 10); ++i){
           pins[i] = random(2, 7);
           Serial.print(pins[i]);
           digitalWrite(pins[i], HIGH);
           delay((int)1000*milliMod);
           digitalWrite(pins[i], LOW);
           delay((int)1000*milliMod);
        }
        break;
    default: break;
  }
}

//print the level, sublevel, and health info to LCD screen, with lables
void printToLCD(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(levelNum);
  lcd.setCursor(6,0);
  lcd.print(level);
  lcd.setCursor(7,0);
  lcd.print(":");
  lcd.setCursor(8,0);
  lcd.print(sublevel);
  lcd.setCursor(0,1);
  lcd.print(healthStr);
  lcd.setCursor(7,1);
  lcd.print(health);
}

//display countdown timer while user enters pattern
void countDown(){
    k = 0;
   for (int sec = 10; sec > -1; --sec){  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Time Left:");
    lcd.setCursor(11,0);
    lcd.print(sec);
        delay(1000);
   }
    while(Serial.available()){
       answer[k] = Serial.parseInt();
       ++k;
    }
   lcd.clear();
   lcd.print("Time's up!"); 
   delay(3000);
 }

//display a given message (str) by scrolling it along the LCD screen
void scrollingMessage(char *str, int len){
  int strBegin = 0, strEnd = 0, windowCursor = 16;
  lcd.clear();
  for(int j = 0; j < len; ++j){
  lcd.setCursor(0,0);
  lcd.setCursor(windowCursor, 1);
  //print all characters in array in between strBegin and strEnd
  for (int i = strBegin;i<strEnd;i++)
    lcd.print(str[i]);
  
  delay(200);
  lcd.clear();
  
  //display more of the char array, so move left on screen (as long as not already
  //at far left
  if(strBegin == 0 && windowCursor != 0){
    strEnd++;
    windowCursor--;
  }
  //reached end of string and at far left of display,
  //change starting position of display loop
   else if (strEnd == len && windowCursor == 0)
    strBegin++;
  
  //neither above is true, move both start and end positions of
  //print loop for char array
  else{
    strBegin++;
    strEnd++;
  }
  }
  delay(100);
}

//User won; display congratulatory message to user 
void winningMessage(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Congratualtions!");
  lcd.setCursor(0,1);
  lcd.print("You won!");
  while(1)
 ; 
}

//User lost; display concialtory message to user
void losingMessage(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Oh no!");
  lcd.setCursor(0,1);
  lcd.print("You lost!");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  scrollingMessage(playAgainStr, strlen(playAgainStr));
  while(!Serial.Available())
  ;
  int anotherGame = 0;
  anotherGame = Serial.parseInt();
  if (anotherGame){
   level = 1;
   sublevel = 0;
   randPin = 0;
   health = 2;
   i = 0;
   k = 0;
   correctPat = 0;
   startMsg = 1;
   bonusLvlUsed = 0;
   correct = 0;
  }
    
  //while(1)
 //; 
}

//This level is meant to give the user the chance to get 1 health back if the 
//user has run out. This level will light up 4 of the 5 LEDs and the user must
//input the LEDs that were NOT lit in sequence. Meant to be offered to Player 
//only once (first time they lose all health
void bonusLevel(float milliMod, int numLoops){
    for (i = 0; i<(numLoops + 4); ++i){
         pins[i] = random(2, 7);  
         Serial.print(pins[i]);
         digitalWrite(led2, HIGH);
         digitalWrite(led3, HIGH);
         digitalWrite(led4, HIGH);
         digitalWrite(led5, HIGH);
         digitalWrite(led6, HIGH);
         digitalWrite(pins[i], LOW);
         delay((int)1000*milliMod);
         digitalWrite(led2, LOW);
         digitalWrite(led3, LOW);
         digitalWrite(led4, LOW);
         digitalWrite(led5, LOW);
         digitalWrite(led6, LOW);
         delay((int)1000*milliMod);
       }
}

//verify that the pattern input by the user is the correct sequence
//return 1 (true) for correct pattern, 0 (false) for incorrect. Display 
//on LCD whether correct or incorrect
int checkPattern(){
    if (k == 0 || k-1 != i){
      testPrint();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Incorrect");
      delay(1000);
      return 0;
  }
  else{
    correctPat = 1;
    for(int j = 0; j < k-1; ++j){
      if(answer[j] != pins[j])
        correctPat = 0;
    }
    if (correctPat){
      testPrint();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Correct!");
      delay(1000);
      return 1;
    }
    else if (!correctPat || k == 0 || k-1 != i){      
      testPrint();
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Incorrect");
      delay(1000);
      return 0;
    }
  }
}

//debugging, for my use
void testPrint(){
  Serial.print("Answer array: ");
    for (int j = 0; j < k-1; ++j)
    Serial.print(answer[j]);
}

void loop() {
  //reset correct pattern variable check
  correct = 0;
  //if user out of health & it's their first time out of health
  //let them try the bonus game; if they have already played it & they are out of health, skip to game over
  if(health < 0){
    if (!bonusLvlUsed){
      bonusLevel(((float)random(6,9)/10), random(0,2));
      countDown();
      correct = checkPattern();
      if (correct){
        ++health;  
        bonusLvlUsed = 1;
        scrollingMessage(bonusStr, strlen(bonusStr));
      }
      else
        losingMessage();
    }
    else
      losingMessage();
  }
  
  //if this is a new game
  if (startMsg){
   scrollingMessage(startStr, strlen(startStr));
   startMsg = 0;
  }
  
  printToLCD();
  delay(3000);
  scrollingMessage(patternStartingStr, strlen(patternStartingStr));
  
  //check value of level, produce appropriate difficulty level (call appropriate level's function)
  switch(level){
    case 1:
      level1(sublevel, ((float)random(7,11)/10), random(0,2));
      break;
    case 2:
      level2(sublevel, ((float)random(4,7)/10), random(0,4));
      break;
    case 3: 
      level3(sublevel, ((float)random(2,5)/10), random(0, 5));
      break;
    case 4: 
      level4(sublevel, .175, random(0, 4));
      break;
    default:
      break;
  }
   
 // scrollingMessage(getReadyStr, strlen(getReadyStr));
 //get rid of everything that came over serial before timer began
  while(Serial.available())
    Serial.read();
  countDown();

  scrollingMessage(resultStr, strlen(resultStr));
  
  //Serial.println();
  correct = checkPattern();
  
  //if user input correct pattern, increment sublevel (max value = 2); if sublevel
  //is at max (2) increment level (max val = 4); if Player input incorrect pattern
  //decrement health (0 = last life; -1 = dead) and reset sublevel to 0. 
  if (correct) 
    ++sublevel;
  else{
    --health;
    sublevel = 0;
  }
  //if sublevel is greater than 2, reset to 0 and advance to next level
  if (sublevel > 2){
    ++level;
    sublevel = 0;
  }
  
  //if level = 5, user has won NOTE TO SELF: if (level == 5) is all that's necessary
  if(level == 1 && sublevel > 2)
    winningMessage();
    
  delay(1000);
}
