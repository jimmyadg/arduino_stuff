int notes[] = {60, 33, 68, 79, 67, 84, 89, 80, 69, 32, 104, 116, 109, 108, 62, 32, 104, 116, 109, 108, 62, 10, 60, 104, 116, 109, 108, 32, 108, 97, 110, 103, 61, 34, 101, 110, 34, 62, 10, 32, 32, 60, 104, 101, 97, 100, 62, 10, 32, 32, 60, 104, 101, 97, 100, 62, 10, 32, 32, 60, 104, 101, 97, 100, 62, 10, 32, 32, 60, 109, 101, 116, 97, 32, 60, 109, 101, 116, 97, 32, 99, 104, 97, 114, 115, 101, 116, 61, 34, 117, 116, 102, 45, 56, 34, 62, 10, 32, 32, 60, 109, 101, 116, 97, 32, 99, 111, 110, 116, 101, 110, 116, 61};
const int speaker = 8;
int speakerNote;
unsigned long prevTime = 0;
int interval = 500;
int i = 0;
int Q[] = {125,250,500,2000}; 
int pitch;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long currentTime = millis();
  if (currentTime - prevTime >= interval) {
    prevTime = currentTime;
    i++;
    speakerNote = notes[i];
    if(notes[i]<= 70) pitch = Q[0];
    if(notes[i]<= 90) pitch = Q[1];
    if(notes[i]<= 100) pitch = Q[2];
    if(notes[i]<= 110) pitch = Q[3];
     

  }
    if (i >= 112) {
      i = 0;
    }
  tone(speaker, speakerNote,pitch);
  Serial.print(speakerNote);
  Serial.print("\t i = \t");
  Serial.print(i);
  Serial.println();
}


