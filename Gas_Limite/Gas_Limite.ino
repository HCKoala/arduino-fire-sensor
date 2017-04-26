int sensor=1; //Sensör arduinonun analog 1 pinine bağlandı.
int led1=8; // LED 8. dijital çıkış pinine bağlandı.
int led2=7; // LED 7. dijital çıkış pinine bağlandı.
int buzzer=4; // Buzzer 4. dijital çıkış pinine bağlandı.
int gas_limite; // Gaz limiti değişkeni tanımlandı.
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
int sensorPin=5;
int smoke_level;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT); // Sensör giriş yapıldı.
  pinMode(led1, OUTPUT); // LED çıkış yapıldı.
  pinMode(led2, OUTPUT); // LED çıkış yapıldı.
  pinMode(buzzer, OUTPUT); // Buzzer çıkış yapıldı.
  Serial.begin(9600); //sets the baud rate for data transfer in bits/second
  pinMode(sensorPin, INPUT);//the smoke sensor will be an input to the arduino
}

void loop() {
  // put your main code here, to run repeatedly:
  gas_limite=analogRead(sensor); // Sensörden değer okunuyor.
  smoke_level= digitalRead(sensorPin);
  Serial.print("Gaz Durumu: "); // Seri haberleşme ekranında Gaz Durumu yazısı yazdırıldı.
  Serial.print(gas_limite); // Seri haberleşme ekranında gaz limiti değeri gösteriliyor.
  Serial.println(" Limit"); // Seri haberleşme ekranında okunan değerin yanına Limit yazdırıldı.
  delay(1000); // 1 saniye aralıklarla değer gösterilecek.
  if (gas_limite>270 || smoke_level == LOW){ // Gaz limiti ayarı yapıldı. İstediğiniz değeri yapabilirsiniz. Gaz limiti 270'den büyükse...
  Serial.print("Gaz Limiti Asildi!!!  "); // Seri haberleşme ekranında Gaz Limiti Aşıldı yazısı yazdırıldı.
  digitalWrite(led1, LOW); // Mavi LED lojik 0 yapıldı.
  digitalWrite(led2, HIGH); // Kırmızı LED lojik 1 yapıldı.
  tone(buzzer,1000); // Buzzer çalıştırıldı.
   } 
  else{ // Eğer gaz limiti 270'den düşükse...
  Serial.println("Gaz Limiti Normal"); // Seri haberleşme ekranında Gaz Limiti Normal yazısı yazdırıldı.
  digitalWrite(led1, HIGH); // Mavi LED lojik 1 yapıldı.
  digitalWrite(led2, LOW); // Kırmızı LED lojik 0 yapıldı.
  noTone(buzzer);}

}
