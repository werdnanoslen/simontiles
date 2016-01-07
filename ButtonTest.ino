// Button pin definitions
#define BUTTON_CYAN   A0
#define BUTTON_YELLOW A1
#define BUTTON_GREEN  A2
#define BUTTON_RED    A3
#define BUTTON_BLUE   A4
#define BUTTON_WHITE  A5

int maxVal;
String button;
String prevButton;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  // Get all button press values
  int cyanVal = analogRead(BUTTON_CYAN);
  delay(1);        // delay in between reads for stability
  int yellowVal = analogRead(BUTTON_YELLOW);
  delay(1);        // delay in between reads for stability
  int greenVal = analogRead(BUTTON_GREEN);
  delay(1);        // delay in between reads for stability
  int redVal = analogRead(BUTTON_RED);
  delay(1);        // delay in between reads for stability
  int blueVal = analogRead(BUTTON_BLUE);
  delay(1);        // delay in between reads for stability
  int whiteVal = analogRead(BUTTON_WHITE);

  // Find button that's pressed on the most
  int vals[6] = {cyanVal, yellowVal, greenVal, redVal, blueVal, whiteVal};
  for (int i=0; i<6; ++i) {
    if (vals[i] > maxVal) {
      maxVal = vals[i];
    }
  }

  // Print when there's a change
  prevButton = button;
  if (maxVal == cyanVal) {
    button = "cyan";
  } else if (maxVal == yellowVal) {
    button = "yellow";
  } else if (maxVal == greenVal) {
    button = "green";
  } else if (maxVal == redVal) {
    button = "red";
  } else if (maxVal == blueVal) {
    button = "blue";
  } else if (maxVal == whiteVal) {
    button = "white";
  }
  if (maxVal > 0) {
    if (prevButton != button) {
      Serial.print(button + " - ");
      Serial.print(maxVal);
      Serial.print("\n");
    }
  }
  
}
