int oneunit = 120;
double onedegree = 6;

void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 bits per second
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT); //5,6 for motor A, left wheel
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT); //10,11 for motor B, right wheel
}

void loop() {

  int sensorValue1 = analogRead(A1); // read the input on analog pin 0
  int sensorValue2 = analogRead(A2);
  int sensorValue3 = analogRead(A3);
  int frontsensor  = analogRead(A0);
  
  analogWrite(5, 60);
  analogWrite(6, 0);
  analogWrite(10, 0);
  analogWrite(11, 40);

if (frontsensor >= 450)
  {
    analogWrite(5, 0); 
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    delay(100);
    
    analogWrite(5, 0);    //左轉
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 100);
    delay(90*onedegree);

    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(9, 0);
    analogWrite(10, 0);
    delay(100);

    analogWrite(5, 60);   //直走
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 40);
    delay(12*oneunit);
    
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    delay(100);
  
    analogWrite(5, 100);   //右轉
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    delay(120*onedegree);

    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    delay(100);

    analogWrite(5, 60);   //直走
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 45);
    delay(16*oneunit);
    
    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    delay(100);

    analogWrite(5, 100);   //右轉
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    delay(105*onedegree);

    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    delay(100);

    analogWrite(5, 60);
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 40);
    delay(15*oneunit);

    analogWrite(5, 0);     //左轉
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 100);
    delay(90*onedegree);

    analogWrite(5, 0);
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
    delay(100);
    
  }

  

  if (sensorValue1 - sensorValue3 > 200) //lean toward right
  {
    analogWrite(5, 80);
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 20);
  }

  else if (sensorValue3 - sensorValue1 > 200) //lean toward left
  {
    analogWrite(5, 20);
    analogWrite(6, 0);
    analogWrite(10, 0);
    analogWrite(11, 80);
  }
}
