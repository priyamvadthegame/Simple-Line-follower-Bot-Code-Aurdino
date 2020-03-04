
long sensors[] = {0, 0, 0};
void setup()
{
 pinMode(A0,INPUT);  //LEFT MOST SENSOR
 pinMode(A1,INPUT);  //MIDDLE SENSOR
 pinMode(A2,INPUT);  //RIGHT MOST SENSOR
 pinMode(2,OUTPUT); //Left Motor Pin 1
 pinMode(4,OUTPUT); //Left Motor Pin 2
 pinMode(7,OUTPUT); //Right Motor Pin 1
 pinMode(8,OUTPUT);  //Right Motor Pin 2
 pinMode(9,OUTPUT);  //LEFT PWM PIN
 pinMode(10,OUTPUT);  //RIGHT PWN PIN
 Serial.begin(9600); //Enable Serial Communications

}

void loop()
{
  sensors[0] = digitalRead(A0);      //left most sensor
  sensors[1] = digitalRead(A1);      //Center Sensor
  sensors[2] = digitalRead(A2);      //Right Most Sensor
  Serial.print(sensors[0]);
  Serial.print(sensors[1]);
  Serial.print(sensors[2]);
  
  if((sensors[0] == 1)&&(sensors[1] == 0)&&(sensors[2] == 1))  //WHITE-BLACK-WHITE
    {
      forward();
    
    }
    
    else if((sensors[0]==0)&&(sensors[1]==1)&&(sensors[2]==1))  //BLACK-WHITE-WHITE
    {
     left();
    //halt();  
    }
       
    else if((sensors[0]==1)&&(sensors[1]==1)&&(sensors[2]==0))  //WHITE-WHITE-BLACK
    {
      right();
     // halt();
    } 
  
  else if((sensors[0]==1)&&(sensors[1]==1)&&(sensors[3]==1))  //WHITE-WHITE-WHITE
    {
      //halt();
    } 
    else forward();
  

//   delay(1000);
}

 
void forward()
{
      digitalWrite(2,HIGH); //FOR LEFT MOTORS
      digitalWrite(4,LOW); //FOR LEFT MOTORS
      digitalWrite(7,HIGH);  //FOR RIGHT MOTORS
      digitalWrite(8,LOW);    //FOR RIGHT MOTORS
      analogWrite(9,255);  //FOR CONTROLLING SPEED OF LEFT MOTOR
      analogWrite(10,255);  //FOR CONTROLLING SPEED OF RIGHTT MOTOR
      delay(60);
      Serial.println("f");
      
}

void left()
{
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(7,HIGH);
      digitalWrite(8,LOW);
      analogWrite(9,255);
      analogWrite(10,255);
      delay(210);
      Serial.println("l");
}

void right()
{
      digitalWrite(2,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      analogWrite(9,255);
      analogWrite(10,255);
      delay(210);
      Serial.println("R");
}
void halt()
{
      digitalWrite(2,LOW);
      digitalWrite(4,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      analogWrite(9,0);
      analogWrite(10,0);
      delay(100);
    Serial.println("H");
}

void reverse()
{
      digitalWrite(2,LOW);
      digitalWrite(4,HIGH);
      digitalWrite(7,LOW);
      digitalWrite(8,HIGH);
      analogWrite(9,255);
      analogWrite(10,255);
      delay(100);
      Serial.println("Rev");
}

//void follow()
//{
//   if((sensors[0]==1)&&(sensors[1]==0)&&(sensors[2]==1))  //WHITE-BLACK-WHITE
//    {
//      forward();
//      halt();
//    }
//    
//    else if((sensors[0]=0)&&(sensors[1]==1)&&(sensors[2]==1))  //BLACK-WHITE-WHITE
//    {
//     left();
//     halt();  
//    }
//       
//    else if((sensors[0]==1)&&(sensors[1]==1)&&(sensors[3]==0))  //WHITE-WHITE-BLACK
//    {
//      right();
//      halt();
//    } 
//  
//  else if((sensors[0]==1)&&(sensors[1]==1)&&(sensors[3]==1))  //WHITE-WHITE-WHITE
//    {
//      halt();
//    } 
//    //else
//     //forward();
//}
