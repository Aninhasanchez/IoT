#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "SUA_REDE_WIFI";
const char* password = "SENHA_WIFI";

String nome = "Ana Luisa"; // Substitua pelo seu nome
const char* serverName = "https://script.google.com/macros/s/SEU_LINK_AQUI/exec";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
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

  delay(1000); // Aguarda 10 segundos
}
