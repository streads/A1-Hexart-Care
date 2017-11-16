#include "Arduino.h"
#include "cardio.h"
#include "coeur.h"

const short sensorPin = 0; // constante contenant le pin de notre "sonde" 
const int recordTime = 10; // constante contenant le temps nécessaire d'enregistrement pour determiner le pou
hearbeat *hb = NULL; // variable qui va contenir toutes les infos relative a la capture du pouls

void SendCSV(int bpm){ // fonction utilisé afin d'envoyer sur le port serie 
  Serial.println(bpm); // le bpm
}

void(* resetFunc) (void) = 0; // pointer vers fonction permettant avec comme adresse 0 equivaut a un JMP 0 en assembleur 


void setup() {
  Serial.begin(9600); // permet de commencer un transfert par le port serial.
  hb = (struct hearbeat *)malloc(sizeof(struct hearbeat)); // allocation dynamique de notre structure hearbeat
  hb->isOver = 1; // par default on ne lance pas l'enregistrement
  
  int a[] ={2,3,4,5,6,7,8,9,10,11}; // tableau contenant tous les pins relative au leds
  initLedPin(a, 10); // on appel la fonction de notre module coeur permettant de les stocker en mémoire

}

void loop() {   // fonction executé a chaque tick de l'arduino
  int sensorValue = analogRead(sensorPin); // sensorValue = la valeur lu par l'arduino du phototransistor.
  if(hb == NULL){exit(1);} // si hb == null on quitte le pgrm

  if (hb->isOver == 0){ // si l'enregistrement de la frequence cardiaque est pas fini

    if ((millis() - (hb->startTime + hb->period * 1000)) <= 0){ // on regarde si le temps écoulé est superieur ou egal au temps écoulé + le temps d'enregistrement parametré
      modeAll(); // on allume toute les leds
      delay(1000); // on attends 1sec
      int bpm = stopCapture(hb); // on stop la capture et on recupere le bpm
      SendCSV(bpm);// on envoi le bpm recuperer sur l'ordinateur
      delay(4000); // on attend 4 seconde
      clearLed();  // on eteint toutes les leds
/*       free(hb);    // on free notre hb pour liberer la mémoire 
      resetFunc(); // et on jmp en haut du fichier pour  */
      //asm volatile ("jmp 0");  
    }
    

    if (processing(hb, sensorValue)){ // si la valeur de notre 'sonde' est detecté comme correspondant a un pou
      printLed(); // alors on affiche les leds
      while(sensorValue > detectionLimit - 60){ // tant que la sonde ne redescend pas on attends 
        sensorValue = analogRead(sensorPin); 
        delay(1);
      }
      clearLed(); // puis on eteint les leds 
    }
    
  }else{ // si l'enregistrement n'est pas en cours
    if (sensorValue > detectionLimit){ // et que l'on detecte un pique au niveau de la sonde
      // on demmare la capture
      modeAll(); // on allume toutes les leds
      delay(1000); // on attends une 1sec
      clearLed(); // puis on eteint toutes les leds
      startCapture(hb, millis(), 10); // on appel notre fonction permettant d'initialiser les valeurs de la structure hb
      while(sensorValue > detectionLimit - 25){ // tant que notre sonde ne redescend pas on attends
        sensorValue = analogRead(sensorPin);
        delay(1);
      }
    }
  }
}


