#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Ancho de la pantalla OLED
#define SCREEN_HEIGHT 64 // Alto de la pantalla OLED

// Inicializa la pantalla OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool areCirclesVisible = false; // Estado de los círculos (visibles o no visibles)

void setup() {
  // Inicializa la comunicación con la pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("No se pudo inicializar la pantalla OLED"));
    while (true);
  }
  
  // Borra la pantalla
  display.clearDisplay();
  
  // Actualiza la pantalla
  display.display();
}

void loop() {
  // Alterna el estado de los círculos cada 700 milisegundos
  areCirclesVisible = !areCirclesVisible;
  
  // Dibuja o borra los círculos según el estado actual
  if (areCirclesVisible) {
    drawCircles(); // Dibuja los círculos
  } else {
    clearCircles(); // Borra los círculos
  }
  
  // Actualiza la pantalla
  display.display();
  
  // Espera 700 milisegundos
  delay(700);
}

// Función para dibujar los círculos
void drawCircles() {
  int radius = 20; // Radio del círculo

  int x1 = SCREEN_WIDTH / 4; // Centro del círculo izquierdo
  int x2 = 3 * SCREEN_WIDTH / 4; // Centro del círculo derecho
  int y = SCREEN_HEIGHT / 2; // Centro vertical

  // Dibuja el círculo izquierdo completo
  display.fillCircle(x1, y, radius, SSD1306_WHITE);

  // Borra la parte superior izquierda del círculo izquierdo
  display.fillCircle(x1 - radius / 1, y - radius / 1, radius, SSD1306_BLACK);

  // Dibuja el círculo derecho completo
  display.fillCircle(x2, y, radius, SSD1306_WHITE);

  // Borra la parte superior derecha del círculo derecho
  display.fillCircle(x2 + radius / 1, y - radius / 1, radius, SSD1306_BLACK);
}

// Función para borrar los círculos
void clearCircles() {
  int radius = 20; // Radio del círculo

  int x1 = SCREEN_WIDTH / 4; // Centro del círculo izquierdo
  int x2 = 3 * SCREEN_WIDTH / 4; // Centro del círculo derecho
  int y = SCREEN_HEIGHT / 3; // Centro vertical

  // Borra el círculo izquierdo completo
  display.fillCircle(x1, y, radius, SSD1306_BLACK);

  // Borra el círculo derecho completo
  display.fillCircle(x2, y, radius, SSD1306_BLACK);
}

