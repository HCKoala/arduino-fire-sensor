//Değişkenler tanımlandı.
int sensor=1; // Gaz sensörü arduino'nun analog 1 pinine bağlandı.
int led1=8; // LED 8. dijital çıkış pinine bağlandı.
int led2=7; // LED 7. dijital çıkış pinine bağlandı.
int buzzer=4; // Buzzer 4. dijital çıkış pinine bağlandı.
int gas_limite; // Gaz limiti değişkeni tanımlandı.
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440}; //Buzzer'dan çıkan sesin tonu ayarlandı.
int sensorPin=5; // Alev sensörü arduino'nun dijital 5 pinine bağlandı.
int smoke_level; // Alev değişkeni tanımlandı.

//Tanımlamalar yapıldı.
void setup() {
  pinMode(sensor, INPUT); // Sensör giriş yapıldı.
  pinMode(led1, OUTPUT); // LED çıkış yapıldı.
  pinMode(led2, OUTPUT); // LED çıkış yapıldı.
  pinMode(buzzer, OUTPUT); // Buzzer çıkış yapıldı.
  Serial.begin(9600); //Saniyede yapılacak bit transferi miktarı belirlendi.
  pinMode(sensorPin, INPUT); //Alev sensörü giriş olarak belirlendi.
}

//Sürekli tekrarlanacak kodlar;
void loop() {
  gas_limite=analogRead(sensor); // Gaz sensöründen değer okunuyor.
  smoke_level= digitalRead(sensorPin); //Alev sensöründen değer okunuyor.
  Serial.print("Gaz Durumu: "); // Seri haberleşme ekranında Gaz Durumu yazısı yazdırıldı.
  Serial.print(gas_limite); // Seri haberleşme ekranında gaz limiti değeri gösteriliyor.
  Serial.println(" Limit"); // Seri haberleşme ekranında okunan değerin yanına Limit yazdırıldı.
  delay(1000); // 1 saniye aralıklarla değer gösterilecek.
  if (gas_limite>270 || smoke_level == LOW) // Değişkenlerden gelecek değerler kontrol ettiriliyor.
  {
  Serial.print("Gaz Limiti Asildi!!!  "); // Seri haberleşme ekranında Gaz Limiti Aşıldı yazısı yazdırıldı.
  digitalWrite(led1, LOW); // Yeşil LED'e gönderilen sinyal kesildi.
  digitalWrite(led2, HIGH); // Kırmızı LED'e sinyal gönderildi.
  tone(buzzer,1000); // Buzzer'a sinyal gönderildi.
  } 
  else // Değişkenlerden gelen veriler tutmuyorsa;
  {
  Serial.println("Gaz Limiti Normal"); // Seri haberleşme ekranında Gaz Limiti Normal yazısı yazdırıldı.
  digitalWrite(led1, HIGH); // Yeşil LED'e sinyal gönderildi.
  digitalWrite(led2, LOW); // Kırmızı LED'e gönderilen sinyal kesildi.
  noTone(buzzer); // uzzer'a gönderilen sinyal kesildi.
  }

}
