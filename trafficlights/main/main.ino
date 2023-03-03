#include "Led.h"

#define LED_RED_PIN 8
#define LED_YELLOW_PIN 9
#define LED_GREEN_PIN 10

Led ledRed(LED_RED_PIN);
Led ledYellow(LED_YELLOW_PIN);
Led ledGreen(LED_GREEN_PIN);

int state = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  changeTrafficLights();
}

void changeTrafficLights() {
  switch(state) {
    case 0:
      ledRed.on();
      ledYellow.off();
      ledGreen.off();
      Serial.println("STOP");
      delay(5000);
      state = 10;
      break;

    // Red-Yellow
		case 10:
			ledRed.on();
			ledYellow.on();
			ledGreen.off();
			Serial.println("GET READY");
			delay(1000);
			state = 20;
			break;

		// Green
		case 20:
			ledRed.off();
			ledYellow.off();
			ledGreen.on();
			Serial.println("GO");
			delay(5000);
			state = 30;
			break;

		// Yellow
		case 30:
			ledRed.off();
			ledYellow.on();
			ledGreen.off();
			Serial.println("SLOW DOWN");
			delay(2000);
			state = 0;
			break;


		// default
		default:
			ledRed.off();
			ledYellow.off();
			ledGreen.off();
			state = 0;
			break;
  }
}