#define pot A0

int redCar = 13; //seta a variavel redCar o valor 13 (porta)
int yellowCar = 12; //seta a variavel yellowCar o valor 12(porta)
int greenCar = 11; //seta a variavel greenCar o valor 11(porta)
int redPeople = 9; //seta a variavel redPeople o valor 9(porta)
int greenPeople = 8; //seta a variavel greenPeolpe o valor 8(porta)
int button= 2; //seta a variavel button o valor 2(porta)
int valorPot=0;


void setup(){
 pinMode(redCar,OUTPUT); //seta saida
 pinMode(yellowCar,OUTPUT); //seta saida
 pinMode(greenCar,OUTPUT); //seta saida
 pinMode(redPeople,OUTPUT); //seta saida
 pinMode(greenPeople,OUTPUT); //seta saida



 pinMode(button,INPUT); //seta entrada (recebe valor)
 digitalWrite(greenCar, HIGH); //começa ligando led verde carro
 digitalWrite(redPeople, HIGH); //começa ligando led vermelho pessoa
}

void loop(){
 valorPot=analogRead(pot);
 int state = digitalRead(button); /*verifica se o botao foi pressionado e se faz mais de 5 seg desde a ultima vez*/
 if (state == HIGH) { //compara o state do button se for HIGH(apertado ele vai chamar changeLights(); em 1000(1 segundo)
 //se for HIGH == HIGH ele chama o changeLights
 delay(100); //
 changeLights();
 }
}
void changeLights(){
  delay(6000);
 digitalWrite(greenCar, LOW); //apaga carGreen
 digitalWrite(yellowCar, HIGH); //acende carYellow
 delay(2000);
 digitalWrite(yellowCar, LOW); //apaga carYellow
 digitalWrite(redCar, HIGH); //acende carRed
 digitalWrite(redPeople, LOW); //apaga pedRed
 digitalWrite(greenPeople, HIGH); //acende pedGreen
 delay(valorPot*8); //chama a variavel crossTime que voce setou no inicio do codigo

//aqui vai começar a piscar o LED verde avisando que esta acabando o tempo de atravessar

digitalWrite(greenPeople, HIGH);
 delay(valorPot);

 digitalWrite(greenPeople, LOW);
 digitalWrite(redPeople, HIGH);
 
 delay(250);

//aqui começa o estado inicial
 digitalWrite(redPeople, HIGH); //acende led vermelho pessoa
 digitalWrite(redCar, LOW); //apaga led vermelho pessoa
 digitalWrite(greenCar, HIGH); //acende led verde carro

}
