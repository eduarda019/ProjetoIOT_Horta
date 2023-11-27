 
#define sinal A0
#define LedVermelho 5
#define LedAmarelo 6
#define LedVerde 7
 
int valor;
 
void setup()
{
  Serial.begin(9600);
  pinMode(sinal, INPUT);
  pinMode(LedVermelho, OUTPUT);
  pinMode(LedAmarelo, OUTPUT);
  pinMode(LedVerde, OUTPUT);
}
 
void loop()
{
  //Le o valor do pino A0 do sensor
  valor = analogRead(sinal);
 
  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica: ");
  Serial.print(valor);
 
  //Solo umido, acende o led verde
  if (valor > 0 && valor < 400)
  {
    Serial.println(" Status: Solo umido");
    apagaleds();
    digitalWrite(LedVerde, HIGH);
  }
 
  //Solo com umidade moderada, acende led amarelo
  if (valor > 400 && valor < 800)
  {
    Serial.println(" Status: Umidade moderada");
    apagaleds();
    digitalWrite(LedAmarelo, HIGH);
  }
 
  //Solo seco, acende led vermelho
  if (valor > 800 && valor < 1024)
  {
    Serial.println(" Status: Solo seco");
    apagaleds();
    digitalWrite(LedVermelho, HIGH);
  }
  delay(100);
}
 
void apagaleds()
{
  digitalWrite(LedVermelho, LOW);
  digitalWrite(LedAmarelo, LOW);
  digitalWrite(LedVerde, LOW);
}
