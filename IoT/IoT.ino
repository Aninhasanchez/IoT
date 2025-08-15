//Instalar Adafruit IO Arduino

#include <WiFi.h>
#include <WiFiClientSecure.h>

// Credenciais da rede Wi-Fi
const char* ssid     = "WIFI_EDUC_CFP501";
const char* password = "SENAICAMPINAS501";

String nome = "Ana Luisa"; // Substitua pelo seu nome
const char* serverName = "https://script.google.com/macros/s/SEU_LINK_AQUI/exec";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Substitua pelos valores reais do sensor
    String temperatura = "28.5";
    String umidade = "65";

    String url = String(serverName) + "?temperatura=" + temperatura + "&umidade=" + umidade + "&nome=" + nome;

    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Resposta: " + response);
    } else {
      Serial.print("Erro na requisição: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  }

  delay(10000); // Aguarda 10 segundos
}
