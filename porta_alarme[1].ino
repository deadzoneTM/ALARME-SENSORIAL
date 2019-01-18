#include <Ultrasonic.h>

const int botao = 10; // Pino 10 envia o pulso para o botao

#define echoPin 13 //Pino 13 recebe o pulso do echo

#define trigPin 12 //Pino 12 envia o pulso para gerar o echo


Ultrasonic ultrasonic(trigPin, echoPin);

//iniciando a função e passando os pinos


float seno;
int frequencia;
int estadobotao = 0;

void setup()

{

Serial.begin(9600); //inicia a porta serial

pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe)

pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia)
 
 pinMode(7,OUTPUT);//define o pino 7 como saída do Buzzer (envia)

   pinMode(8,OUTPUT);//define o pino 8 como saída do led (envia)

      pinMode(botao,INPUT); // defini o pino 10 para entrada do botao (recebe)
}

void loop()
{
  
 estadobotao = digitalRead(botao);
 int distancia = 0;

 if( estadobotao == HIGH)
  {
  digitalWrite(8,HIGH); // liga led se o botao estiver acionado
   //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
    
  if(distancia<20){
  for(int x=0;x<180;x++){
  //converte graus para radiando e depois obtém o valor do seno
  seno=(sin(x*3.1416/180));
  //gera uma frequência a partir do valor do seno
  frequencia = 2000+(int(seno*1000));
  tone(7,frequencia);
  delay(2000);
  digitalWrite(13, HIGH);
  
 }
}
  noTone(7);
  }
  else{
    digitalWrite(8,LOW);
    }
  digitalWrite(13,LOW);
  }
