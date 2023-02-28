#include<SPI.h>
#include<MFRC522.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS3231 rtc;
char NamaHari[7][12]= {"Min","Sen","Sel","Rab","Kam","Jum","Sab"};

const int pin_ss=10;
const int pin_rst=9;
String Nama,Posisi;

MFRC522 rfid(pin_ss,pin_rst);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  lcd.begin();
  if(!rtc.begin()) {
    Serial.println("RTC tidak terbaca!");
    
  }
  else {
    // menyetel RTC ke tanggal dan waktu
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

}

void loop() {
  DateTime now = rtc.now();
  
  if(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()){ // read tag rfid
    return;
  } 
  String id;
  for (int i=0; i<=3; i++){
    id=id+(rfid.uid.uidByte[i]<0x10 ? "0" : "") + String(rfid.uid.uidByte[i],HEX) + (i==3 ? "" : ":"); //read code rfid tag
  } 
  Serial.print("ID Anda: ");
  Serial.println(id);

  if(id=="f8:48:b3:0d"){     // id tag rfid
    Nama = "kelompok3";
    Posisi = "Owner";
    Serial.println(" Nama:" + Nama + " Position:" + Posisi);
    Serial.print(NamaHari[now.dayOfTheWeek()]);
    Serial.print(now.day());
    Serial.print("-");
    Serial.print(now.month());
    Serial.print("-");
    Serial.println(now.year());
    Serial.print(now.hour());
    Serial.print(":");
    Serial.println(now.minute());
    Serial.print("suhu: ");
    Serial.print(rtc.getTemperature());
   Serial.println();
   lcd.setCursor(1,0);
   lcd.print(" Nama:" + Nama + " Position:" + Posisi);
   lcd.setCursor(1,1);
   lcd.print(NamaHari[now.dayOfTheWeek()]);
   lcd.print(now.day());
    lcd.print("-");
    lcd.print(now.month());
    lcd.print("-");
    lcd.println(now.year());
    delay(5000);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(now.hour());
    lcd.print(":");
    lcd.print(now.minute());
    lcd.setCursor(2,1);
    lcd.print("suhu: ");
    lcd.print(rtc.getTemperature());
     delay(5000);
  }
  if(id=="80:8b:ec:26"){ // id tag rfid
    Nama = "aku";
    Posisi = "pelajar";
    Serial.println(Nama + " " + Posisi);
    Serial.print(NamaHari[now.dayOfTheWeek()]);
    Serial.print( now.day());
    Serial.print("-");
    Serial.print(now.month());
    Serial.print("-");
    Serial.println(now.year());
    Serial.print(now.hour());
    Serial.print(":");
    Serial.println(now.minute());
    Serial.print("suhu:");
    Serial.print(rtc.getTemperature());
    Serial.println();
  lcd.setCursor(1,0);
  lcd.print(Nama + " " + Posisi);
  lcd.setCursor(1,1);
  lcd.print(NamaHari[now.dayOfTheWeek()]);
  lcd.print(now.day());
    lcd.print("-");
    lcd.print(now.month());
    lcd.print("-");
    lcd.println(now.year());
    delay(5000);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(now.hour());
    lcd.print(":");
    lcd.print(now.minute());
    lcd.setCursor(2,1);
    lcd.print("suhu: ");
    lcd.print(rtc.getTemperature());
     delay(5000);
  }
  
  if(id=="05:82:a8:63"){     // id tag rfid
    Nama = "Dafa";
    Posisi = "Pelajar";
    Serial.println(" Nama:" + Nama + " Position:" + Posisi);
    Serial.print(NamaHari[now.dayOfTheWeek()]);
    Serial.print(now.day());
    Serial.print("-");
    Serial.print(now.month());
    Serial.print("-");
    Serial.println(now.year());
    Serial.print(now.hour());
    Serial.print(":");
    Serial.println(now.minute());
    Serial.print("suhu: ");
    Serial.print(rtc.getTemperature());
   Serial.println();
   lcd.setCursor(0,0);
   lcd.print(Nama +" " + Posisi);
   lcd.setCursor(1,1);
   lcd.print(NamaHari[now.dayOfTheWeek()]);
   lcd.print(now.day());
    lcd.print("-");
    lcd.print(now.month());
    lcd.print("-");
    lcd.println(now.year());
    delay(5000);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(now.hour());
    lcd.print(":");
    lcd.print(now.minute());
    lcd.setCursor(2,1);
    lcd.print("suhu: ");
    lcd.print(rtc.getTemperature());
    delay(5000);
  }
  if(id=="04:25:6f:4a"){    // id tag rfid
    Nama = "agung";         
    Posisi = "Pelajar";    
    Serial.println(Nama + " Position:"+ Posisi);
    Serial.print(NamaHari[now.dayOfTheWeek()]);
    Serial.print(now.day());
    Serial.print("-");
    Serial.print(now.month());
    Serial.print("-");
    Serial.println(now.year());
    Serial.print(now.hour());
    Serial.print(":");
    Serial.println(now.minute());
    Serial.print("suhu: ");
    Serial.print(rtc.getTemperature());
   Serial.println();
   lcd.setCursor(0,0);
   lcd.print(Nama + " " + Posisi);
   lcd.setCursor(1,1);
   lcd.print(NamaHari[now.dayOfTheWeek()]);
   lcd.print(now.day());
    lcd.print("-");
    lcd.print(now.month());
    lcd.print("-");
    lcd.println(now.year());
    delay(5000);
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print(now.hour());
    lcd.print(":");
    lcd.print(now.minute());
    lcd.setCursor(2,1);
    lcd.print("suhu: ");
    lcd.print(rtc.getTemperature());
     delay(5000);
  }
  
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();  
  
  //putih:f8:48:b3:0d
  //biru: 80:8b:ec:26

}
