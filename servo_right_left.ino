#include <Servo.h>
#include <Pixy2.h>

int pin1 = 4;
int pin2 = 5;
int pin3 = 6;


Pixy2 pixy;
Servo myservo;  

int pos;    
// ENA IN1 IN2 IN3 IN4 ENB
int myPins[6] = {2, 3, 4, 5, 6, 7};
float deadZone = 0.15;
//int baseSpeed = 130;


void setup() {
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object

// setup camera  
  Serial.begin(115200);
  Serial.print("Starting...\n");
  pinMode (pin1,OUTPUT);
  pinMode (pin2,OUTPUT);
  pinMode (pin3,OUTPUT);
  
  pixy.init();
}

void loop() {

/*// camera reading 
int i; 
    int x;
//   grab blocks!
  pixy.ccc.getBlocks();
  
 //  If there are detect blocks, print them!
     if (pixy.ccc.numBlocks)
  {
      Serial.print("Detected ");
      Serial.println(pixy.ccc.numBlocks);
      for (i=0; i<pixy.ccc.numBlocks; i++)
      {
          Serial.print("  block ");
          Serial.print(i);
          Serial.print(": ");
          pixy.ccc.blocks[i].print();
          Serial.print ("x=  ");
          Serial.println (pixy.ccc.blocks[0].m_x);
          Serial.print (",  y=  ");
          Serial.println (pixy.ccc.blocks[0].m_y);
           delay(100);
           Serial.println (",  ");
      }
  }
  else
 {
   pixy.ccc.blocks[0].m_x=1000;
      Serial.println("  hahahah ");
       Serial.println (pixy.ccc.blocks[0].m_x);
      
 }
 
  
    
      if ( (pixy.ccc.blocks[0].m_x>155)&&(pixy.ccc.blocks[0].m_x<1000) )  
             {          

                if ((pixy.ccc.blocks[0].m_y>120))
                {
                  Serial.println ("fl");
                  digitalWrite (pin1,0);
                  digitalWrite (pin2,1);
                  digitalWrite (pin3,1);
                }
                           
               else if ((pixy.ccc.blocks[0].m_y<90))
        
                  {
                  Serial.println (" fr ");
                  digitalWrite (pin1,1);
                  digitalWrite (pin2,1);
                  digitalWrite (pin3,0);
                }
               
               else if((pixy.ccc.blocks[0].m_y>90)||(pixy.ccc.blocks[0].m_y<120))
               {
                Serial.println (" FF ");
                  digitalWrite (pin1,1);
                  digitalWrite (pin2,1);
                  digitalWrite (pin3,1);
                }
             }
               else if ((pixy.ccc.blocks[0].m_x<140)&&(pixy.ccc.blocks[0].m_x<1000) )  
             {          

                if ((pixy.ccc.blocks[0].m_y<90))
                {
                  Serial.println ("br");
                  digitalWrite (pin1,1);
                  digitalWrite (pin2,0);
                  digitalWrite (pin3,0);
                }

                else if ((pixy.ccc.blocks[0].m_y>90)&&(pixy.ccc.blocks[0].m_y<120))

                 {
                  Serial.println ("bb");
                  digitalWrite (pin1,1);
                  digitalWrite (pin2,0);
                  digitalWrite (pin3,1);
                }
                           
               else if ((pixy.ccc.blocks[0].m_y>120))
        
                  {
                  Serial.println (" bl ");
                  digitalWrite (pin1,0);
                  digitalWrite (pin2,0);
                  digitalWrite (pin3,1);
                }
             }
             else if (pixy.ccc.blocks[0].m_x=1000) 
             {          

                  Serial.println ("nd");
                  digitalWrite (pin1,0);
                  digitalWrite (pin2,0);
                  digitalWrite (pin3,0);
                
              
             }// end of camera reading*/
             


// servo movment
  
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(2000);
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(5000);



for (pos = 90; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(2000);
  for (pos = 0; pos <= 90; pos += 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  delay(5000);// end of servo movment
  
  
}



void moveRobot(int leftSpeed, int rightSpeed)
{
  if (leftSpeed >= 0) {
    digitalWrite(myPins[1], 0);
    digitalWrite(myPins[2], 1);
  }
  else {
    digitalWrite(myPins[1], 1);
    digitalWrite(myPins[2], 0);
  }

  if (rightSpeed >= 0) {
    digitalWrite(myPins[3], 0);
    digitalWrite(myPins[4], 1);
  }
  else {
    digitalWrite(myPins[3], 1);
    digitalWrite(myPins[4], 0);
  }

  analogWrite(myPins[0], abs(leftSpeed));
  analogWrite(myPins[5], abs(rightSpeed));
}
