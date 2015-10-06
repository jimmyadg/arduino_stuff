int x = 0;
int rate = 10;
int y = 600;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

x+= rate;
if(x >= y || x <= 0){
  rate = rate * -1;
}
Serial.println(rate);
}
