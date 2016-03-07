void proximity() {
  digitalWrite(trigPin, LOW);  
  digitalWrite(trigPin, HIGH); 
  digitalWrite(trigPin, LOW); 

  pingTime = pulseIn(echoPin, HIGH);  
  pingTime = pingTime / 1000000; 
  pingTime = pingTime / 3600; 
  distance = speedOfSound * pingTime; 
  distance = distance / 2; 
  distance = distance * 63360;
}
