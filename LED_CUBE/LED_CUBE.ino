// Define anode pins (X-Y grid: 5x5 = 25)
const int anodePins[5][5] = {
  {22, 24, 26, 28, 30},  // X = 0
  {32, 34, 36, 38, 40},  // X = 1
  {42, 44, 46, 48, 50},  // X = 2
  {52, 53, 5, 6, 7},     // X = 3
  {8, 9, 10, 11, 12}     // X = 4
};

// Define cathode layer pins (Z-axis)
const int layerPins[5] = {A0, A1, A2, A3, A4}; // Z = 0 to 4

void setup() {
  // Set anode pins as OUTPUT
  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 5; y++) {
      pinMode(anodePins[x][y], OUTPUT);
      digitalWrite(anodePins[x][y], LOW);
    }
  }

  // Set layer pins as OUTPUT
  for (int z = 0; z < 5; z++) {
    pinMode(layerPins[z], OUTPUT);
    digitalWrite(layerPins[z], HIGH); // HIGH = OFF (active LOW)
  }
}

void loop() {
  showPlane100(); delay(1000);
  showPlane010(); delay(1000);
  showPlane001(); delay(1000);
  showPlane110(); delay(1000);
  showPlane101(); delay(1000);
  showPlane011(); delay(1000);
  showPlane111(); delay(1000);
}

// Plane (100): x = constant
void showPlane100() {
  for (int x = 0; x < 5; x++) {
    for (int z = 0; z < 5; z++) {
      turnOffAll();
      digitalWrite(layerPins[z], LOW); // Activate layer z
      for (int y = 0; y < 5; y++) {
        digitalWrite(anodePins[x][y], HIGH);
      }
      delay(100);
      digitalWrite(layerPins[z], HIGH);
    }
  }
}

// Plane (010): y = constant
void showPlane010() {
  for (int y = 0; y < 5; y++) {
    for (int z = 0; z < 5; z++) {
      turnOffAll();
      digitalWrite(layerPins[z], LOW);
      for (int x = 0; x < 5; x++) {
        digitalWrite(anodePins[x][y], HIGH);
      }
      delay(100);
      digitalWrite(layerPins[z], HIGH);
    }
  }
}

// Plane (001): z = constant (entire layer)
void showPlane001() {
  for (int z = 0; z < 5; z++) {
    turnOffAll();
    digitalWrite(layerPins[z], LOW);
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
        digitalWrite(anodePins[x][y], HIGH);
      }
    }
    delay(500);
    digitalWrite(layerPins[z], HIGH);
  }
}

// Plane (110): x = y
void showPlane110() {
  for (int z = 0; z < 5; z++) {
    turnOffAll();
    digitalWrite(layerPins[z], LOW);
    for (int xy = 0; xy < 5; xy++) {
      digitalWrite(anodePins[xy][xy], HIGH);
    }
    delay(500);
    digitalWrite(layerPins[z], HIGH);
  }
}

// Plane (101): x = z
void showPlane101() {
  for (int z = 0; z < 5; z++) {
    turnOffAll();
    digitalWrite(layerPins[z], LOW);
    for (int x = 0; x < 5; x++) {
      digitalWrite(anodePins[x][z], HIGH);
    }
    delay(500);
    digitalWrite(layerPins[z], HIGH);
  }
}

// Plane (011): y = z
void showPlane011() {
  for (int z = 0; z < 5; z++) {
    turnOffAll();
    digitalWrite(layerPins[z], LOW);
    for (int y = 0; y < 5; y++) {
      digitalWrite(anodePins[z][y], HIGH);
    }
    delay(500);
    digitalWrite(layerPins[z], HIGH);
  }
}

// Plane (111): x = y = z
void showPlane111() {
  for (int z = 0; z < 5; z++) {
    turnOffAll();
    digitalWrite(layerPins[z], LOW);
    digitalWrite(anodePins[z][z], HIGH);
    delay(300);
    digitalWrite(layerPins[z], HIGH);
  }
}

// Helper: Turn off all anodes
void turnOffAll() {
  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 5; y++) {
      digitalWrite(anodePins[x][y], LOW);
    }
  }
}
