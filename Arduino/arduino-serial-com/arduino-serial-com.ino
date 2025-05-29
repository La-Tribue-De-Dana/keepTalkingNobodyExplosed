#define	BoutonBandeRouge	2
#define	BoutonBandeVert	3
#define	BoutonBandeBleu	4

#define	CLK	6
#define	DIO	7

#define	chronoErr4	10
#define	chronoErr3	11
#define	chronoErr2	12
#define	chronoErr1	13

#define	chronoSon	9
#define	symboleLum3	18
#define	symboleLum2	19
#define	symboleLum1	20
#define	symboleLum0	21
#define	symboleErreur	22
#define	symboleVictoire	23
#define	symboleBtn0	24
#define	symboleBtn1	25
#define	symboleBtn2	26
#define	symboleBtn3	27
#define	calcLum3	28
#define	calcLum4	29
#define	calcLum2	30
#define	calcLum1	31
#define	calcLumVictoire	32
#define	calcLumErreur	33
#define	BoutonContact	34
#define	BoutonVictoire	35
#define	BoutonErreur	36
#define	fil5	37
#define	fil4	38
#define	fil3	39
#define	fil2	40
#define	fil1	41
#define	filVictoire	42
#define	filErreur	43
#define	simonBtn3	44
#define	simonBtn2	45
#define	simonBtn1	46
#define	simonBtn0	47
#define	simonLum4	48
#define	simonLum3	49
#define	simonLum2	50
#define	simonLum1	51
#define	simonLumVictoire	52
#define	simonLumErreur	53
 
#include <TM1637Display.h>
TM1637Display display(CLK, DIO);

#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

// Adafruit_7segment matrix = Adafruit_7segment();
int etatBlink = 0;
int etatLum = 5;


void setup() {
  Serial.begin(19200);
  Serial.setTimeout(500); 

  // matrix.begin(0x70);
  // matrix.setBrightness(5);
  // matrix.blinkRate(0);
  display.setBrightness(0x0f);  // max brightness


  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(simonLum1, OUTPUT);
  pinMode(simonLum2, OUTPUT);
  pinMode(simonLum3, OUTPUT);
  pinMode(simonLum4, OUTPUT);
  pinMode(simonLumVictoire, OUTPUT);
  pinMode(simonLumErreur, OUTPUT);
  
  pinMode(calcLumErreur, OUTPUT);
  pinMode(calcLumVictoire, OUTPUT);
  pinMode(calcLum1, OUTPUT);
  pinMode(calcLum2, OUTPUT);
  pinMode(calcLum3, OUTPUT);
  pinMode(calcLum4, OUTPUT);

  pinMode(filErreur, OUTPUT);
  pinMode(filVictoire, OUTPUT);

  pinMode(symboleLum0, OUTPUT);
  pinMode(symboleLum1, OUTPUT);
  pinMode(symboleLum2, OUTPUT);
  pinMode(symboleLum3, OUTPUT);
  pinMode(symboleVictoire, OUTPUT);
  pinMode(symboleErreur, OUTPUT);
  
  pinMode(BoutonVictoire, OUTPUT);
  pinMode(BoutonErreur, OUTPUT);
  pinMode(BoutonBandeRouge, OUTPUT);
  pinMode(BoutonBandeVert, OUTPUT);
  pinMode(BoutonBandeBleu, OUTPUT);
  pinMode(chronoErr1, OUTPUT);
  pinMode(chronoErr2, OUTPUT);
  pinMode(chronoErr3, OUTPUT);
  pinMode(chronoErr4, OUTPUT);

  pinMode(fil1, INPUT_PULLUP);
  pinMode(fil2, INPUT_PULLUP);
  pinMode(fil3, INPUT_PULLUP);
  pinMode(fil4, INPUT_PULLUP);
  pinMode(fil5, INPUT_PULLUP);

  pinMode(simonBtn0, INPUT_PULLUP);
  pinMode(simonBtn1, INPUT_PULLUP);
  pinMode(simonBtn2, INPUT_PULLUP);
  pinMode(simonBtn3, INPUT_PULLUP);

  pinMode(symboleBtn0, INPUT_PULLUP);
  pinMode(symboleBtn1, INPUT_PULLUP);
  pinMode(symboleBtn2, INPUT_PULLUP);
  pinMode(symboleBtn3, INPUT_PULLUP);

  pinMode(BoutonContact, INPUT_PULLUP);

  pinMode(chronoSon, INPUT_PULLUP);




  // matrix.writeDigitNum(0, 0, 0);
  // matrix.writeDigitNum(1, 0, 0);
  // matrix.writeDigitNum(3, 0, 0);
  // matrix.writeDigitNum(4, 0, 0);
  // matrix.drawColon(1);
  // matrix.writeDisplay();

  display.showNumberDecEx(0, 0b01000000, true, 4, 0);

  digitalWrite(simonLum1, 1);
  digitalWrite(simonLum2, 1);
  digitalWrite(simonLum3, 1);
  digitalWrite(simonLum4, 1);
  digitalWrite(simonLumVictoire, 1);
  digitalWrite(simonLumErreur, 1);
  
  digitalWrite(calcLumErreur, 1);
  digitalWrite(calcLumVictoire, 1);
  digitalWrite(calcLum1, 1);
  digitalWrite(calcLum2, 1);
  digitalWrite(calcLum3, 1);
  digitalWrite(calcLum4, 1);

  digitalWrite(symboleVictoire, 1);
  digitalWrite(symboleErreur, 1);
  digitalWrite(symboleLum0, 1);
  digitalWrite(symboleLum1, 1);
  digitalWrite(symboleLum2, 1);
  digitalWrite(symboleLum3, 1);

  digitalWrite(filVictoire, 1);
  digitalWrite(filErreur, 1);
  digitalWrite(BoutonVictoire, 1);
  digitalWrite(BoutonErreur, 1);
  digitalWrite(BoutonBandeRouge, 1);
  digitalWrite(BoutonBandeVert, 1);
  digitalWrite(BoutonBandeBleu, 1);
  digitalWrite(chronoErr1, 1);
  digitalWrite(chronoErr2, 1);
  digitalWrite(chronoErr3, 1);
  digitalWrite(chronoErr4, 1);

}
void loop() {
  
  if (Serial.available() > 0) {
0
    String data = Serial.readStringUntil('\n');

    // Traitement Sortie
    for(int i=0;i<data.length();i++){
      data[i] = data[i] - '0';
    }
    
    digitalWrite(simonLum1, data[0]);
    digitalWrite(simonLum2, data[1]);
    digitalWrite(simonLum3, data[2]);
    digitalWrite(simonLum4, data[3]);
    digitalWrite(simonLumVictoire, data[4]);
    digitalWrite(simonLumErreur, data[5]);
    
    digitalWrite(calcLumErreur, data[6]);
    digitalWrite(calcLumVictoire, data[7]);
    digitalWrite(calcLum1, data[8]);
    digitalWrite(calcLum2, data[9]);
    digitalWrite(calcLum3, data[10]);
    digitalWrite(calcLum4, data[11]);

    digitalWrite(symboleVictoire, data[12]);
    digitalWrite(symboleErreur, data[13]);
    digitalWrite(symboleLum0, data[14]);
    digitalWrite(symboleLum1, data[15]);
    digitalWrite(symboleLum2, data[16]);
    digitalWrite(symboleLum3, data[17]);

    digitalWrite(filVictoire, data[18]);
    digitalWrite(filErreur, data[19]);

    
    if(data[36] == 1){;  // Toujours en OUTPUT pour le son
      tone(chronoSon, 100);    
      delay(300);
    } else {
      tone(chronoSon,22000);           // Arrête le son
    }
      
    if(etatLum != 0){

      byte lala = data[20] ;
      if(lala == 0xfd){ // signe "-"
        // matrix.writeDigitRaw(0,0b0000000001000000);

        display.showNumberDecEx(-1, 0, false, 4, 0); // affiche "-" sur premier digit
        display.showNumberDec(data.substring(21, 24).toInt(), false, 3, 1);

      }else{    
        // matrix.writeDigitNum(0, data[20], 0);   
         // Affiche les 4 chiffres normalement
        uint8_t colonMask = data[24] != 0 ? 0b01000000 : 0;
        int numberToDisplay = data[20]*1000 + data[21]*100 + data[22]*10 + data[23];
        display.showNumberDecEx(numberToDisplay, colonMask, true, 4, 0);
      }
      // matrix.writeDigitNum(1, data[21], 0);
      // matrix.writeDigitNum(3, data[22], 0);
      // matrix.writeDigitNum(4, data[23], 0);
      // matrix.drawColon(data[24]);
      // matrix.writeDisplay();

      // display.showNumberDecEx(
      //   digits[0]*1000 + digits[1]*100 + digits[2]*10 + digits[3], 
      //   colonMask, true, 4, 0
      // );
    }
    digitalWrite(BoutonVictoire, data[25]);
    digitalWrite(BoutonErreur, data[26]);
    digitalWrite(BoutonBandeRouge, data[27]);
    digitalWrite(BoutonBandeVert, data[28]);
    digitalWrite(BoutonBandeBleu, data[29]);
    
    digitalWrite(chronoErr1, data[30]);
    digitalWrite(chronoErr2, data[31]);
    digitalWrite(chronoErr3, data[32]);
    digitalWrite(chronoErr4, data[33]);
    
    // if(etatBlink != data[34]){
    //   matrix.blinkRate( data[34]);
    //   etatBlink = data[34];
    // }
    
    if(data[35] == 0){
      if(etatLum != 0){
        // matrix.setBrightness(0);
        // matrix.writeDigitRaw(0,0b0000000000000000);
        // matrix.writeDigitRaw(1,0b0000000000000000);
        // matrix.writeDigitRaw(2,0b0000000000000000);
        // matrix.writeDigitRaw(3,0b0000000000000000);
        // matrix.writeDigitRaw(4,0b0000000000000000);
        // matrix.writeDisplay();
        // etatLum = 0;
        display.clear();
        etatLum = 0;
      }
    }
    else if(data[35] == 1){
      if(etatLum != 3){
        // matrix.setBrightness(3);
        // etatLum = 3;
        display.setBrightness(3);
        etatLum = 3;
      }
    } 
    else{
      if(etatLum != 15){
        // matrix.setBrightness(15);
        // etatLum = 15;

        display.setBrightness(15);
        etatLum = 15;
      }
    }


    // Traitement entree
    Serial.print(digitalRead(simonBtn0));
    Serial.print(digitalRead(simonBtn1));
    Serial.print(digitalRead(simonBtn2));
    Serial.print(digitalRead(simonBtn3));

    Serial.print(digitalRead(symboleBtn0));
    Serial.print(digitalRead(symboleBtn1));
    Serial.print(digitalRead(symboleBtn2));
    Serial.print(digitalRead(symboleBtn3));

    Serial.print(digitalRead(fil1));
    Serial.print(digitalRead(fil2));
    Serial.print(digitalRead(fil3));
    Serial.print(digitalRead(fil4));
    Serial.print(digitalRead(fil5));
    Serial.print(digitalRead(BoutonContact));
    Serial.print(digitalRead(chronoSon));

    Serial.print('\n');

  }
  delay(2);
}
