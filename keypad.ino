//FIPPITHETECHIE 
//24.08.17


#include <Keypad.h>
int start;
int prevnum =0;
int lastnum=0;
int temp;
int keyy=0;
int pin;
bool error = false;
int counter = 0;
int topright = 15;
int top = 14;
int dot = 10;
int bottomright = 11;
int bottomleft = 12;
int bottom = 13;
int topleft = 16;
int middle = 17;

//pinMode(10,OUTPUT);
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //ROWS
byte colPins[COLS] = {9, 8, 7, 6}; //COLUMNS

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
   Serial.begin(9600);
   pinMode(topright,OUTPUT);
   pinMode(top,OUTPUT);
   pinMode(bottomright,OUTPUT);
   pinMode(bottomleft,OUTPUT);
   pinMode(bottom,OUTPUT);
   pinMode(dot,OUTPUT);
   pinMode(topleft,OUTPUT);
   pinMode(middle,OUTPUT);
   start = 1;

}
  
void loop(){
  
  char key = keypad.getKey();
  
  
  if (key){
    start = 0;
    temp = int(key);
    error = false;
    counter = 0;
    Serial.print(key);
    //char(Serial.read());
   Serial.print(temp);
   convert();
   
   Serial.print(keyy);
   check();   
   }

   
  if(error == true && counter<=4)
  { 
        digitalWrite(topright,0);
       digitalWrite(bottomright,0);
       digitalWrite(middle,1);
       digitalWrite(topleft,HIGH);
       digitalWrite(top,HIGH);
       digitalWrite(bottomleft,HIGH);
       digitalWrite(bottom,HIGH);
       digitalWrite(dot,1);
       delay(100);
       digitalWrite(topright,0);
       digitalWrite(bottomright,0);
       digitalWrite(middle,0);
       digitalWrite(topleft,0);
       digitalWrite(top,0);
       digitalWrite(bottomleft,0);
       digitalWrite(bottom,0);
       digitalWrite(dot,0);
       delay(100);
       counter++;
    }
    else 
    {
      if(keyy==0)
      {
      check();  
      }
      
      keyy = lastnum;
      check();
    }
    
  }

  void lastnumm()
  {
    lastnum = keyy;
    
  }


  void check()
   {
      
   if(keyy==1)
   {

    digitalWrite(topright,HIGH);
       digitalWrite(bottomright,HIGH);
       digitalWrite(middle,LOW);
       digitalWrite(topleft,LOW);
       digitalWrite(top,LOW);
       digitalWrite(bottomleft,LOW);
       digitalWrite(bottom,LOW);
       

   }
   else if(keyy==2)
   {

    digitalWrite(topright,HIGH);
       digitalWrite(bottomright,0);
       digitalWrite(middle,1);
       digitalWrite(topleft,LOW);
       digitalWrite(top,HIGH);
       digitalWrite(bottomleft,HIGH);
       digitalWrite(bottom,HIGH);

   }
   else if(keyy==3)
   {

    digitalWrite(topright,HIGH);
       digitalWrite(bottomright,HIGH);
       digitalWrite(middle,1);
       digitalWrite(topleft,0);
       digitalWrite(top,HIGH);
       digitalWrite(bottomleft,0);
       digitalWrite(bottom,HIGH);

   }
   else if(keyy==4)
   {

    digitalWrite(topright,HIGH);
       digitalWrite(bottomright,HIGH);
       digitalWrite(middle,1);
       digitalWrite(topleft,HIGH);
       digitalWrite(top,0);
       digitalWrite(bottomleft,0);
       digitalWrite(bottom,0);

   }
   else if(keyy==5)
   {

    digitalWrite(topright,0);
       digitalWrite(bottomright,1);
       digitalWrite(middle,1);
       digitalWrite(topleft,HIGH);
       digitalWrite(top,HIGH);
       digitalWrite(bottomleft,0);
       digitalWrite(bottom,HIGH);

   }
   else if(keyy==6)
   {

    digitalWrite(topright,0);
       digitalWrite(bottomright,HIGH);
       digitalWrite(middle,1);
       digitalWrite(topleft,HIGH);
       digitalWrite(top,HIGH);
       digitalWrite(bottomleft,HIGH);
       digitalWrite(bottom,HIGH);

   }
   else if(keyy==7)
   {

    digitalWrite(topright,HIGH);
       digitalWrite(bottomright,HIGH);
       digitalWrite(middle,LOW);
       digitalWrite(topleft,0);
       digitalWrite(top,HIGH);
       digitalWrite(bottomleft,0);
       digitalWrite(bottom,0);

   }
   else if(keyy==8)
   {

    digitalWrite(topright,HIGH);
       digitalWrite(bottomright,HIGH);
       digitalWrite(middle,1);
       digitalWrite(topleft,HIGH);
       digitalWrite(top,HIGH);
       digitalWrite(bottomleft,HIGH);
       digitalWrite(bottom,HIGH);

   }
   else if(keyy==0)
   {
    if(start == 1 && counter<=4)
    {
      digitalWrite(topright,HIGH);
       digitalWrite(bottomright,HIGH);
       digitalWrite(middle,LOW);
       digitalWrite(topleft,HIGH);
       digitalWrite(top,HIGH);
       digitalWrite(bottomleft,HIGH);
       digitalWrite(bottom,HIGH);
       delay(100);
       digitalWrite(topright,0);
       digitalWrite(bottomright,0);
       digitalWrite(middle,LOW);
       digitalWrite(topleft,0);
       digitalWrite(top,0);
       digitalWrite(bottomleft,0);
       digitalWrite(bottom,0);
       delay(100);
       counter++;
    }
    digitalWrite(topright,HIGH);
       digitalWrite(bottomright,HIGH);
       digitalWrite(middle,LOW);
       digitalWrite(topleft,HIGH);
       digitalWrite(top,HIGH);
       digitalWrite(bottomleft,HIGH);
       digitalWrite(bottom,HIGH);

   }
   else if(keyy==9 && counter<=10)
   {
    
    digitalWrite(topright,HIGH);
       digitalWrite(bottomright,HIGH);
       digitalWrite(middle,1);
       digitalWrite(topleft,HIGH);
       digitalWrite(top,HIGH);
       digitalWrite(bottomleft,0);
       digitalWrite(bottom,HIGH);
       delay(400);
       digitalWrite(topright,0);
       digitalWrite(bottomright,0);
       digitalWrite(middle,LOW);
       digitalWrite(topleft,0);
       digitalWrite(top,0);
       digitalWrite(bottomleft,0);
       digitalWrite(bottom,0);
       delay(200);
       digitalWrite(topright,HIGH);
       digitalWrite(bottomright,HIGH);
       digitalWrite(middle,1);
       digitalWrite(topleft,HIGH);
       digitalWrite(top,HIGH);
       digitalWrite(bottomleft,0);
       digitalWrite(bottom,HIGH);
       counter++;
       
   }
   else
   {
       error = true;
       prevnum = lastnum;
   }
   }

  void convert()
  {
    if(temp == 49)
   {
    keyy = 1; 
    lastnumm();
   }
   else if(temp == 50)
   {
    keyy = 2;
    lastnumm();
   }
   else if(temp == 51)
   {
    keyy = 3;
    lastnumm();
   }
   //else if(temp == 65)
   //{
    //keyy = int("A");//3
   //}
   else if(temp == 52)
   {
    keyy = 4;
    lastnumm();
   }
   else if(temp == 53)
   {
    keyy = 5;
    lastnumm();
   }
   else if(temp == 54)
   {
    keyy = 6;
    lastnumm();
   }
   //else if(temp == 66)
   //{
    //keyy = int("B");//10
   //}
   else if(temp == 55)
   {
    keyy = 7;
    lastnumm();
   }else if(temp == 56)
   {
    keyy = 8;
    lastnumm();
   }else if(temp == 57)
   {
    keyy = 9;
    lastnumm();
   }
   //else if(temp == 67)
   //{
    //keyy = int("C");//
   //}
   else if(temp == 48)
   {
    keyy = 0;
    lastnumm();
   }
   else
   {
   keyy = 1000; 
   } 
  }

