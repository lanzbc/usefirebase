#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


ESP8266WebServer sever(80); //port 80 cua web
int count=0;
void setup() {
  WiFi.mode(WIFI_AP_STA); //ESP la tram phat wifi
  WiFi.softAP("lanzbc","meomeomeo"); // tao ten dang nhap va mat khua cho esp
  WiFi.begin("Sikbon","bon140115@@"); // ket no voi wifi noi bo mang

  while(WiFi.waitForConnectResult()!=WL_CONNECTED)
    delay(5000);
    Serial.begin(115200);
    Serial.println(WiFi.localIP());
    
    sever.on("/",HTTP_GET,[]{
      Serial.println(String("Co nguoi truy cap: ") + count++);
      sever.send(200,"text/plain","Chao chu Phong");
    });

    sever.on("/count",[]{
      Serial.println(String("Co nguoi truy cap: ")+ count++);
      sever.send(200,"text/plain",String("so truy cap: ") + count);
    });
    
    sever.begin();  
}

void loop() {
  sever.handleClient();
  
}
