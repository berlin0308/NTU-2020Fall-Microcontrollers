const int onecentimeter = 24;
const int onedegree = 10 ; 

void turnright();
void movemove(int spd);
void stopstop();

void setup() 
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT); //5,6 for motor A, left wheel
  pinMode(10, OUTPUT);
  pinMode(11 ,OUTPUT); //7,8 for motor B, right wheel


}

void loop() 
{
  stopstop();
  delay(2000);
  movemove(135);
  delay(1000);
  turnright();
  movemove(100);
  delay(1000);
  turnright();
  movemove(135);
  delay(1000);
  turnright();
  movemove(100);
  delay(1000);
  turnright();
}

void turnright()
{
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(10, 0);
  analogWrite(11, 70);
  delay(90*onedegree); // 向右轉90度
}

void movemove(int spd)
{
  analogWrite(5, 145);
  analogWrite(6, 0);
  analogWrite(10, 0);
  analogWrite(11, 60 );
  delay(spd*onecentimeter);
}

void stopstop()
{
  analogWrite(5, 0);
  analogWrite(6, 0);
  analogWrite(10, 0);
  analogWrite(11, 0);
}
