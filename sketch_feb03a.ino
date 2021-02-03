#include <PubSubClient.h>

#include <UIPEthernet.h>
#include <utility/logging.h>

#include <SPI.h>


//Define o endereço MAC que será utilizado
byte mac[] = {0x48, 0x62, 0x59, 0xD5, 0x57, 0x2B};

boolean mensagem;

int pino2 = 2; //Cria uma variável para o Pino 2
bool estado_sensor; //Cria uma variável para Armazenar o estado do sensor

//Inicia o cliente Ethernet
EthernetClient client;

PubSubClient mqttClient(client);

void setup() {
    //Inicia o controlador Ethernet e solicita um IP para o servidor de DHCP
    Ethernet.begin(mac);
    
    pinMode(pino2,INPUT_PULLUP); //Coloca o Pino 2 como Entrada
  Serial.begin(9600); //Inicia o Monitor Serial
}

    //Inicia o monitor Serial
    Serial.begin(9600);

    mqttClient.setServer("54.144.190.205",1883);

    //Exibe no Monitor Serial as informações sobre o IP do Arduino
    Serial.print("O IP do Arduino e: ");
    Serial.println(Ethernet.localIP());

    //Exibe no Monitor Serial as informações sobre a Máscara de Rede do Arduino
    Serial.print("A Mascara de Rede do Arduino e: ");
    Serial.println(Ethernet.subnetMask());

    //Exibe no Monitor Serial as informações sobre o Gateway do Arduino
    Serial.print("O Gateway do Arduino e: ");
    Serial.println(Ethernet.gatewayIP());

    //Exibe uma linha em branco
    Serial.println("");

}

void loop() {

   
  estado_sensor = digitalRead(pino2); //Efetua a leitura do Pino 2 e armazena o valor obtido na variável

  Serial.println(estado_sensor); //Exibe no Monitor Serial o Estado do Sensor

  if(estado sensor ==1) {
  Serial.print("O RACKER ESTA FECHADO!");
  Serial.println("");
  
  mqttClient.connect("guilhermef");

  mensagem = mqttClient.publish("guilhermef-t","FECHADO!");

  Serial.println(mensagem);
  
  mqttClient.loop();
    
}
 if(estado_sensor == 0){
 Serial.print("O RACKER ESTA ABERTO!");
 Serial.println("");
 mqttClient.connect("guilhermef");
 mensagem = mqttClient.publish("guilhermef-t",ABERTO!");
   Serial.println(mensagem);
 }

   mqttClient.loop();
}
