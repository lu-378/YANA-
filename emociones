#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Ancho de la pantalla OLED
#define SCREEN_HEIGHT 64 // Alto de la pantalla OLED
#define BUTTON_PIN 2     // Pin del pulsador

// Inicializa la pantalla OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

enum EyeState {
  NORMAL,
  ANGRY,
  SAD,
  HAPPY
};

EyeState currentEyeState = NORMAL; // Estado inicial de los ojos
bool areEyesVisible = false;       // Estado de los ojos (visibles o no visibles)
unsigned long previousMillis = 0;  // Almacena el tiempo desde el último cambio de estado
const long interval = 500;         // Intervalo de tiempo para parpadear (en milisegundos)

void setup() {
  // Inicializa la comunicación con la pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("No se pudo inicializar la pantalla OLED"));
    while (true);
  }

  // Configura el pin del pulsador como entrada con pull-up interno
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Borra la pantalla
  display.clearDisplay();

  // Dibuja los ojos en el estado inicial
  drawEyes(currentEyeState);

  // Actualiza la pantalla
  display.display();
}

void loop() {
  unsigned long currentMillis = millis();

  // Verifica el estado del pulsador
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Cambia al siguiente estado de los ojos al presionar el botón
    switch (currentEyeState) {
      case NORMAL:
        currentEyeState = ANGRY;
        break;
      case ANGRY:
        currentEyeState = SAD;
        break;
      case SAD:
        currentEyeState = HAPPY;
        break;
      case HAPPY:
        currentEyeState = NORMAL;
        break;
    }

    // Borra la pantalla
    display.clearDisplay();

    // Dibuja los ojos en el nuevo estado
    drawEyes(currentEyeState);

    // Actualiza la pantalla
    display.display();

    // Espera un breve tiempo para evitar rebotes del botón
    delay(200);
  }

  // Alterna el estado de los ojos cada intervalo de tiempo
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    areEyesVisible = !areEyesVisible;

    // Borra la pantalla
    display.clearDisplay();

    // Dibuja o borra los ojos según el estado actual
    if (areEyesVisible) {
      drawEyes(currentEyeState);
    } else {
      clearEyes();
    }

    // Actualiza la pantalla
    display.display();
  }
}

// Función para dibujar los ojos según el estado
void drawEyes(EyeState state) {
  int radius = 20; // Radio del ojo

  int x1 = SCREEN_WIDTH / 4;     // Centro del ojo izquierdo
  int x2 = 3 * SCREEN_WIDTH / 4; // Centro del ojo derecho
  int y = SCREEN_HEIGHT / 2;     // Centro vertical

  switch (state) {
    case NORMAL:
      // Dibuja ojos normales
      display.fillCircle(x1, y, radius, SSD1306_WHITE);
      display.fillCircle(x2, y, radius, SSD1306_WHITE);
      break;
    case ANGRY:
      // Dibuja ojos enojados
       display.fillCircle(x1, y, radius, SSD1306_WHITE);

      // Borra la parte superior izquierda del círculo izquierdo con un círculo
        display.fillCircle(x1 + radius / 1, y - radius / 1, radius / 1, SSD1306_BLACK);

      // Dibuja el círculo derecho completo
        display.fillCircle(x2, y, radius, SSD1306_WHITE);

      // Borra la parte superior derecha del círculo derecho con un círculo
       display.fillCircle(x2 - radius / 1, y - radius / 1, radius / 1, SSD1306_BLACK);
      break;
    case SAD:
      // Dibuja ojos tristes
       // Dibuja el círculo izquierdo completo
        display.fillCircle(x1, y, radius, SSD1306_WHITE);

        // Borra la parte superior izquierda del círculo izquierdo
        display.fillCircle(x1 - radius / 1, y - radius / 1, radius, SSD1306_BLACK);

       // Dibuja el círculo derecho completo
        display.fillCircle(x2, y, radius, SSD1306_WHITE);

       // Borra la parte superior derecha del círculo derecho
        display.fillCircle(x2 + radius / 1, y - radius / 1, radius, SSD1306_BLACK);
      break;
    case HAPPY:
      // Dibuja ojos felices
      display.fillCircle(x1, y, radius, SSD1306_WHITE);
      display.fillCircle(x2, y, radius, SSD1306_WHITE);

      // Dibuja triángulos en la parte inferior para ojos felices
      display.fillTriangle(x1 - radius, y + radius, x1 + radius, y + radius, x1, y + radius - 10, SSD1306_BLACK);
      display.fillTriangle(x2 - radius, y + radius, x2 + radius, y + radius, x2, y + radius - 10, SSD1306_BLACK);
      break;
  }
}

// Función para borrar los ojos
void clearEyes() {
  int radius = 20; // Radio del ojo

  int x1 = SCREEN_WIDTH / 4;     // Centro del ojo izquierdo
  int x2 = 3 * SCREEN_WIDTH / 4; // Centro del ojo derecho
  int y = SCREEN_HEIGHT / 2;     // Centro vertical

  // Borra el ojo izquierdo completo
  display.fillCircle(x1, y, radius, SSD1306_BLACK);

  // Borra el ojo derecho completo
  display.fillCircle(x2, y, radius, SSD1306_BLACK);
}
