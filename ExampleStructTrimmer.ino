struct Trimmer{
  int analogInput;
  int digitalOutput;
  bool isPwm;
  int soglia;
  
};


Trimmer trimmers[3];

Trimmer tr1 = {A2, 4, false, 100};
Trimmer tr2 = {A4, 5, false, 800};
Trimmer tr3 = {A5, 6, true, 0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tr1.digitalOutput, OUTPUT);
  pinMode(tr2.digitalOutput, OUTPUT);
  pinMode(tr3.digitalOutput, OUTPUT);
  
  trimmers[0] = tr1;
  trimmers[1] = tr2;
  trimmers[2] = tr3;
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i < 3; i++)
  {
    int val = analogRead(trimmers[i].analogInput);
    if(!trimmers[i].isPwm)
    {
         
        if(val > trimmers[i].soglia)
        {
              digitalWrite(trimmers[i].digitalOutput, HIGH);
        } 
        else
        {
              digitalWrite(trimmers[i].digitalOutput, LOW);
        }
    }
    else
    {
        val = map(val, 0, 1024, 0, 255);
        analogWrite(trimmers[i].digitalOutput, val);
    }
    
  }

}


