#include <LiquidCrystal.h>

const int UltraSonicSensor = 8;
int C;
long duration, inches, cm;
int enablePin = 3;
int in1Pin = 12;
int in2Pin = 13;
int BTN1 = 2;
int BTN2 = 4;
int BTN3 = 7;
int speed;
int floorN;
int state ;
const int rs = A0, en = 5, d4 = 6, d5 = 9, d6 = 10, d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
boolean reverse;

void setup()
{
 pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(BTN1 , INPUT);
  pinMode(BTN2 , INPUT);
  pinMode(BTN3 , INPUT);

    lcd.begin(16, 2);
  lcd.print("Welcome Mr.M.H   ");



}

void loop()
{
  pinMode(UltraSonicSensor, OUTPUT);
  digitalWrite(UltraSonicSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(UltraSonicSensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(UltraSonicSensor, LOW);
   pinMode(UltraSonicSensor, INPUT);
  duration = pulseIn(UltraSonicSensor, HIGH);
  C =  digitalRead(duration);


  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  speed = 255 - cm/1.6;
 
  

  reverse = false ;
  
  
  if(cm <=20){
  floorN = 1;
   state = digitalRead(BTN1) ; 
    if( state == 1){
        lcd.setCursor(0, 1);
      lcd.print("you are on floor 1 !     ");

    }
       state = digitalRead(BTN2) ; 

     if( state == 1){
         lcd.setCursor(0, 1);

      lcd.print("Going Up To 2 !     ");
       boolean reached = false ;
       while(reached == false){
           pinMode(UltraSonicSensor, OUTPUT);
  digitalWrite(UltraSonicSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(UltraSonicSensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(UltraSonicSensor, LOW);
   pinMode(UltraSonicSensor, INPUT);
  duration = pulseIn(UltraSonicSensor, HIGH);
  C =  digitalRead(duration);


  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  speed = 255 - cm/1.6;
 
  

  reverse = false ;
                    setMotor(speed, reverse);

         if (cm >= 95 && cm <= 105){
         reached = true;
           setMotor(0 , reverse);
              lcd.setCursor(0, 1);

      lcd.print("REACHED !           ");
         }
  
  

       }
       

    }
       state = digitalRead(BTN3) ; 

     if( state == 1){
         lcd.setCursor(0, 1);

      lcd.print("Going Up TO 3 !     ");
  boolean reached = false ;
       while(reached == false){
           pinMode(UltraSonicSensor, OUTPUT);
  digitalWrite(UltraSonicSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(UltraSonicSensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(UltraSonicSensor, LOW);
   pinMode(UltraSonicSensor, INPUT);
  duration = pulseIn(UltraSonicSensor, HIGH);
  C =  digitalRead(duration);


  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  speed = 255 - cm/1.6;
 
  

  reverse = false ;
                    setMotor(speed, reverse);

         if (cm >= 195 && cm <= 205){
         reached = true;
           setMotor(0 , reverse);
              lcd.setCursor(0, 1);

      lcd.print("REACHED !        ");
         }
  
  

       }
    }
    
    
  }else if (cm <=120 && cm>= 100){
  floorN = 2;
       state = digitalRead(BTN2) ; 
      if( state == 1){
          lcd.setCursor(0, 1);

      lcd.print("you are on floor 2 !      ");

    }
    
           state = digitalRead(BTN3) ; 

     if( state == 1){
         lcd.setCursor(0, 1);

      lcd.print("Going Up TO 3 !      ");
  boolean reached = false ;
       while(reached == false){
           pinMode(UltraSonicSensor, OUTPUT);
  digitalWrite(UltraSonicSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(UltraSonicSensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(UltraSonicSensor, LOW);
   pinMode(UltraSonicSensor, INPUT);
  duration = pulseIn(UltraSonicSensor, HIGH);
  C =  digitalRead(duration);


  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  speed = 255 - cm/1.6;
 
  

  reverse = false ;
                    setMotor(speed, reverse);

         if (cm >= 195 && cm <= 205){
         reached = true;
           setMotor(0 , reverse);
              lcd.setCursor(0, 1);

      lcd.print("REACHED !          ");
         }
  
  

       }
    }
    
    
    
    
           state = digitalRead(BTN1) ; 

     if( state == 1){
         lcd.setCursor(0, 1);

      lcd.print("Going DOWN TO 1 !       ");
  boolean reached = false ;
       while(reached == false){
           pinMode(UltraSonicSensor, OUTPUT);
  digitalWrite(UltraSonicSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(UltraSonicSensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(UltraSonicSensor, LOW);
   pinMode(UltraSonicSensor, INPUT);
  duration = pulseIn(UltraSonicSensor, HIGH);
  C =  digitalRead(duration);


  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  speed = 255 - cm/1.6;
 
  

  reverse = true ;
                    setMotor(speed, reverse);

         if( cm <= 20){
         reached = true;
           setMotor(0 , reverse);
              lcd.setCursor(0, 1);

      lcd.print("REACHED !            ");
         }
  
  

       }
    }
    
    
    
  
  }else if (cm <= 220 && cm<= 200){
  floorN = 3;
       state = digitalRead(BTN3) ; 
     if( state == 1){
         lcd.setCursor(0, 1);

      lcd.print("you are on floor 3 !       ");

    }
    
        
    
    
           state = digitalRead(BTN1) ; 

     if( state == 1){
         lcd.setCursor(0, 1);

      lcd.print("Going DOWN TO 1 !        ");
  boolean reached = false ;
       while(reached == false){
           pinMode(UltraSonicSensor, OUTPUT);
  digitalWrite(UltraSonicSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(UltraSonicSensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(UltraSonicSensor, LOW);
   pinMode(UltraSonicSensor, INPUT);
  duration = pulseIn(UltraSonicSensor, HIGH);
  C =  digitalRead(duration);


  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  speed = 255 - cm/1.6;
 
  

  reverse = true ;
                    setMotor(speed, reverse);

         if (cm <= 20 ){
         reached = true;
           setMotor(0 , reverse);
              lcd.setCursor(0, 1);

      lcd.print("REACHED !           ");
         }
  
  

       }
    }
    
    
    
    
    
        
    
    
           state = digitalRead(BTN2) ; 

     if( state == 1){
         lcd.setCursor(0, 1);

      lcd.print("Going DOWN TO 2 !        ");
  boolean reached = false ;
       while(reached == false){
           pinMode(UltraSonicSensor, OUTPUT);
  digitalWrite(UltraSonicSensor, LOW);
  delayMicroseconds(2);
  digitalWrite(UltraSonicSensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(UltraSonicSensor, LOW);
   pinMode(UltraSonicSensor, INPUT);
  duration = pulseIn(UltraSonicSensor, HIGH);
  C =  digitalRead(duration);


  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  speed = 255 - cm/1.6;
 
  

  reverse = true ;
                    setMotor(speed, reverse);

         if (cm >= 95 && cm <= 105){
         reached = true;
           setMotor(0 , reverse);
            lcd.setCursor(0, 1);

      lcd.print("REACHED !                  ");
         }
  
  

       }
    }
    
    
    
    
    
  }

  
  
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
void setMotor(int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, ! reverse);
  digitalWrite(in2Pin, reverse);
}