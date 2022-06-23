//A LftMotor
//B RightMotor

int motorA1  = 10; 
int motorA2  = 11;
int motorB1 = 6; // motor b is to be reversed. B1 will go in pin b2
int motorB2  = 5; // wiil go in pin b1
char state;
int vSpeed;

int BTstate = 12;
int enableA3 = 8;
int enableA4 = 9;
int enableB3 = 3;
int enableB4 = 4;

void setup()
{
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);

    pinMode(enableA3, OUTPUT);
    pinMode(enableA4, OUTPUT);
    pinMode(enableB3, OUTPUT);
    pinMode(enableB4, OUTPUT);

    Serial.begin(9600);
}

void loop()
{   
    if(Serial.available()>0)
    {
        state = Serial.read();
        Serial.println(state);
    }

//speed 
    /*if (state == '0'){
      vSpeed=0;
    }else if (state == '1'){
      vSpeed=30;
    }else if (state == '2'){
      vSpeed=55;
    }else if (state == '3'){
      vSpeed=80;
    }else if (state == '4'){
      vSpeed=105;
    }else if (state == '5'){
      vSpeed=130;
    }else if (state == '6'){
      vSpeed=155;
    }else if (state == '7'){
      vSpeed=180;
    }else if (state == '8'){
      vSpeed=205;
    }else if (state == '9'){
      vSpeed=230;
    }else if (state == 'q'){
      vSpeed=255;
    }*/
    if(state >= '0' and state <= '9'){
      vspeed = (state - '0')*26;
    }
    else if(state == 'q'){
      vspeed = 255;
    }

//direction
    if(state == 'F'){ //forward
      digitalWrite(enableA3, HIGH); digitalWrite(enableA4, HIGH);
      digitalWrite(enableB3, HIGH); digitalWrite(enableB4, HIGH);
      
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
      analogWrite(motorB1, vSpeed); analogWrite(motorB2, 0); 
    }
    else if(state == 'B'){//back
      digitalWrite(enableA3, HIGH); digitalWrite(enableA4, HIGH);
      digitalWrite(enableB3, HIGH); digitalWrite(enableB4, HIGH);
      
      analogWrite(motorA1, 0); analogWrite(motorA2, vSpeed);
      analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed); 
    }
    else if(state == 'L'){// left
      digitalWrite(enableA3, HIGH); digitalWrite(enableA4, HIGH);
      digitalWrite(enableB3, HIGH); digitalWrite(enableB4, HIGH);
      
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
      analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed); 
    }
    else if(state == 'R'){ //right
      digitalWrite(enableA3, HIGH); digitalWrite(enableA4, HIGH);
      digitalWrite(enableB3, HIGH); digitalWrite(enableB4, HIGH);
      
      analogWrite(motorA1, 0); analogWrite(motorA2, vSpeed);
      analogWrite(motorB1, vSpeed); analogWrite(motorB2, 0);
    } 
    else if(state == 'S'){//stop
      digitalWrite(enableA3, LOW); digitalWrite(enableA4, LOW);
      digitalWrite(enableB3, LOW); digitalWrite(enableB4, LOW);
    }
    else if(state == 'I'){//forward right
      digitalWrite(enableA3, HIGH); digitalWrite(enableA4, HIGH);
      digitalWrite(enableB3, HIGH); digitalWrite(enableB4, HIGH);
      
      analogWrite(motorA1, 0); analogWrite(motorA2, 0);
      analogWrite(motorB1, vSpeed); analogWrite(motorB2, 0);
    }
    else if(state == 'G'){//forward left
      digitalWrite(enableA3, HIGH); digitalWrite(enableA4, HIGH);
      digitalWrite(enableB3, HIGH); digitalWrite(enableB4, HIGH);
      
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
      analogWrite(motorB1, 0); analogWrite(motorB2, 0);
    }
    else if(state == 'H'){//back left
      digitalWrite(enableA3, HIGH); digitalWrite(enableA4, HIGH);
      digitalWrite(enableB3, HIGH); digitalWrite(enableB4, HIGH);
      
      analogWrite(motorA1, 0); analogWrite(motorA2, vSpeed);
      analogWrite(motorB1, 0); analogWrite(motorB2, 0);
    }
    else if(state == 'J'){//forward right
      digitalWrite(enableA3, HIGH); digitalWrite(enableA4, HIGH);
      digitalWrite(enableB3, HIGH); digitalWrite(enableB4, HIGH);
      
      analogWrite(motorA1, 0); analogWrite(motorA2, 0);
      analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed);
    }
}
