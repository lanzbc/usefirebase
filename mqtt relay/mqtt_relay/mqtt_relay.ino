#include <ESP8266WiFi.h>
#include <PubSubClient.h>
void nhandl(char * tp, byte * nd, unsigned int length)
{
  String topic(tp);
  String noidung= String((char*)nd);
  noidung.remove(length);

  Serial.println(topic);
  Serial.println(noidung);

  if(topic=="ESPn/RLA")
  {
    if(noidung=="1")
      digitalWrite(12,HIGH);
    if(noidung=="0")
      digitalWrite(12,LOW);
  }

  if(topic=="ESPn/RLB")
  {
    if(noidung=="1")
      digitalWrite(13,LOW);
    if(noidung=="0")
      digitalWrite(13,HIGH);
  }
}
WiFiClient c;
PubSubClient MQTT("m16.cloudmqtt.com",13787,nhandl,c);

void setup() {
  Serial.begin(115200);
  WiFi.begin("Sikbon", "bon140115@@");
  while (1)
  {
    delay(1000);
    if (WiFi.status() == WL_CONNECTED)
      break;
  }
  Serial.println("Da vao duoc internet");
  while (1)
  {
    delay(1000);
    if (MQTT.connect("ESP", "cvyrnvgw", "PPSoKbeixyLf"))
      break;
  }
  Serial.println("Da vao duoc MQTT");
  MQTT.publish("test", "gui du lieu thu");
  MQTT.subscribe("ESPn/RLA");
  MQTT.subscribe("ESPn/RLB");

  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);

}

void loop() {
  MQTT.loop();
  MQTT.publish("ESPg/RLA", String(digitalRead(12)).c_str());
  MQTT.publish("ESPg/RLB", String(digitalRead(13)).c_str());
}
