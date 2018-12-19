#include <LiquidCrystal.h>
  const int UltraSonicSensor = 8;
int C;
long duration, inches, cm;
int enablePin = 3;
int in1Pin = 12;
int in2Pin = 13;
int speed;
int floorN;
int state;
int KEY = A1;
int IRSensor = 4;
const int rs = A0,
  en = 5,
  d4 = 6,
  d5 = 9,
  d6 = 10,
  d7 = 11;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
boolean reverse;
int orders[5] = {-1,
  -1,
  -1,
  -1,
  -1
};
void setup() {
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Welcome Mr.M.H   ");
}
void loop() {
  searchForButttons();
  speed = 250;
  reverse = false;
  change();
  move();
  delay(100);
}
void setMotor(int speed, boolean reverse) {
  analogWrite(enablePin, speed);
  digitalWrite(in1Pin, !reverse);
  digitalWrite(in2Pin, reverse);
}
int getCurrentFloor() {
  if (analogRead(A2) <= 204) {
    return 0;
  } else if (analogRead(A2) > 204 && analogRead(A2) <= 2 * 204) {
    return 1;
  } else if (analogRead(A2) > 2 * 204 && analogRead(A2) <= 3 * 204) {
    return 2;
  } else if (analogRead(A2) > 3 * 204 && analogRead(A2) <= 4 * 204) {
    return 3;
  } else if (analogRead(A2) > 4 * 204 && analogRead(A2) <= 5 * 204) {
    return 4;
  }
}
void searchForButttons() {
  switch (analogRead(A1)) {
  case 568:
    addToQeue(0);
    break;
  case 731:
    addToQeue(1);
    break;
  case 853:
    addToQeue(2);
    break;
  case 984:
    addToQeue(3);
    break;
  case 1013:
    addToQeue(4);
    break;
  }
}
void addToQeue(int floorCode) {
  boolean exists = false;
  for (int nw = 0; nw < 5; nw++) {
    if (orders[nw] == floorCode) {
      exists = true;
    }
  }
  for (int n = 0; n < 5; n++) {
    if (orders[n] == -1 && exists == false) {
      orders[n] = floorCode;
      n = 5;
    }
  }
}
void move() {
  int i = 0;
//  change();
  if (orders[i] != -1) {
    if (getCurrentFloor() == orders[i]) {
      lcd.setCursor(0, 1);
      lcd.print("You are on floor");
      lcd.print("                    ");
      rearrange();
      change();
    } else if (getCurrentFloor() < orders[i]) {
      change();
      while (getCurrentFloor() < orders[i]) {
        setMotor(speed, reverse);
        searchForButttons();
        lcd.setCursor(0, 0);
        lcd.print("Going to");
        lcd.print(orders[i]);
        lcd.print("                    ");
      }
      lcd.setCursor(0, 1);
      lcd.print("Reached");
      lcd.print(orders[i]);
      lcd.print("                    ");
      rearrange();
      change();
      setMotor(0, !reverse);
      delay(100);
    } else if (getCurrentFloor() > orders[i]) {
      change();
      while (getCurrentFloor() > orders[i]) {
        setMotor(speed, !reverse);
        searchForButttons();
        lcd.setCursor(0, 0);
        lcd.print("Going to");
        lcd.print(orders[i]);
        lcd.print("                    ");
      }
      lcd.setCursor(0, 1);
      lcd.print("Reached ");
      lcd.print(orders[i]);
      lcd.print("                    ");
      rearrange();
      change();
      setMotor(0, !reverse);
      delay(100);
    }
  }
}
void rearrange() {
  for (int k = 0; k < 4; k++) {
    orders[k] = orders[k + 1];
  }
  orders[4] = -1;
}
void change () {
  int c = getCurrentFloor();
  for (int i = 0 ; i<4 ; i++){
    if(abs(orders[i]-c) >abs(orders[i+1] - c)&& orders[i]!=-1 && orders[i+1]!=-1){
    	int d1 = orders[i] ;
      	int d2 = orders[i+1];
      	orders[i+1] = d1;
    	orders[i] = d2;
    }
  }
}