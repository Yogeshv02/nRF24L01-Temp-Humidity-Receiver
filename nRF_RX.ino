#include <U8x8lib.h>
#include<Arduino.h>

//---------------------------------
//nRF24L01 Temp & Humidity Receiver
//---------------------------------

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>

//------------------------------------------
RF24 radio(10, 9);
U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(SCL,SDA,U8X8_PIN_NONE);  
//------------------------------------------
const uint64_t pipe1 = 0xF0F0F0F066;
//------------------------------------------ 
struct sensor
{
  float temp;
  int   hum;
  float pre;
  byte  sensorNum;
};
sensor sensorData;
//===============================================================
void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT); pinMode(3,OUTPUT);
  //----------------------------------------
  u8x8.begin();
  u8x8.setPowerSave(0);
  //----------------------------------------
  radio.begin();
  //radio.openReadingPipe(1, pipe1);
  radio.openReadingPipe(1, pipe1);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
}
//===============================================================
void loop()
{
  //--------------------------------------------
  if(radio.available())
  {
    radio.read(&sensorData, sizeof(sensorData));
    Serial.print("Temperature = ");
    Serial.print(sensorData.temp);
    Serial.println(" *C");
    Serial.print("Humidity = ");
    Serial.print(sensorData.hum);
    Serial.println(" hPa");
    Serial.print("Pressure = ");
    Serial.print(sensorData.pre);
    Serial.println(" hPa");
    disp_sensor_data();
    //radio.read(&sensorData, sizeof(sensorData));
    //disp_sensor_data();
    //------------------------------------------
    digitalWrite(3, HIGH); digitalWrite(2, LOW);
  }
  else
  {
    digitalWrite(3, LOW); digitalWrite(2, HIGH);
  }
  u8x8.refreshDisplay();    // only required for SSD1606/7  
  delay(2000);
}
//===============================================================
void disp_sensor_data()
{
  if(sensorData.sensorNum == 1)
  {
    //u8x8.clearBuffer();
    u8x8.setFont(u8x8_font_chroma48medium8_r);
    u8x8.setCursor(1, 0);  // Set the cursor position
    u8x8.print("Sensor Node");
    u8x8.setCursor(1, 2);  // Set the cursor position
    u8x8.print("Temp : ");
    u8x8.print(sensorData.temp); u8x8.println(" °C");
    u8x8.setCursor(1, 4);  // Set the cursor position
    u8x8.print("Hum : ");
    u8x8.print(sensorData.hum); u8x8.println(" %");
    u8x8.setCursor(1, 6);  // Set the cursor position
    u8x8.print("Pre : ");
    u8x8.print(sensorData.pre); u8x8.println(" hpa");
    //u8x8.sendBuffer();
    //delay(1000);
    /*u8x8.drawString(1,0,"Sensor Node");
    u8x8.drawString(1,2,sensorData.temp);
    u8x8.drawString(4,2,"C");
    u8x8.drawString(1,4,sensorData.hum);
    u8x8.drawString(4,4,"%");
    u8x8.drawString(1,6,sensorData.pre);
    u8x8.drawString(4,6,"hpa");*/
  }
}
