#include <ArduinoJson.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
StaticJsonBuffer<256> jb;
JsonObject& obj=jb.createObject();

void setup() {
  WiFi.disconnect();
  WiFi.begin("Sikbon","bon140115@@"); // ket no voi wifi noi bo mang
  while(WiFi.waitForConnectResult()!=WL_CONNECTED){
    delay(5000);
  }
  Firebase.begin("lanzbc.Firebaseio.com");
  Firebase.stream("/getData");

  obj["ten insta:"]=String(" lanzbc ");
  Serial.begin(115200);
  

}

void loop() {
//  Firebase.setString("/xinchao","chao, to la Lan");
//  Firebase.setString("/info","bai rac");
//  Firebase.setInt("setInt", millis());
//  Firebase.setInt("setInt", millis()/3.0);
//    
//    obj["thoigian"] = millis();
//    Firebase.set("/JSON", obj);

//    Firebase.pushString("/pushString", String(millis()));
//    Serial.println(Firebase.getInt("/getData/cafe"));

//    FirebaseObject fbO=Firebase.get("/getData/obj");
//    Serial.println(String("cafe: ")+fbO.getString("cafe"));
//    Serial.println(String("gia: ")+fbO.getInt("gia"));
//  delay(5000);
  if(Firebase.available()){
    FirebaseObject fbO= Firebase.readEvent();
    Serial.println(String("type: ") + fbO.getString("type"));
    Serial.println(String("path: ") + fbO.getString("path"));
    Serial.println(String("path: ") + fbO.getString("data"));
  }

}
