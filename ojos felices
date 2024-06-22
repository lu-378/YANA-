#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Ancho de la pantalla OLED
#define SCREEN_HEIGHT 64 // Alto de la pantalla OLED

// Inicializa la pantalla OLED
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

bool isCircleVisible = false; // Estado del círculo (visible o no visible)

void setup() {
  // Inicializa la comunicación con la pantalla OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("No se pudo inicializar la pantalla OLED"));
    while(true);
  }
  
  // Borra la pantalla
  display.clearDisplay();
  
  // Actualiza la pantalla
  display.display();
}

void loop() {
  // Alterna el estado del círculo cada 500 milisegundos
  isCircleVisible = !isCircleVisible;
  
  // Dibuja o borra los círculos según el estado actual
  if(isCircleVisible) {
    drawEyes(); // Dibuja los ojos
  } else {
    clearEyes(); // Borra los ojos
  }
  
  // Actualiza la pantalla
  display.display();
  
  // Espera 500 milisegundos
  delay(500);
}

// Función para dibujar los ojos
void drawEyes() {
  int radius = 20; // Radio del círculo

  int x1 = SCREEN_WIDTH / 4; // Centro del ojo izquierdo
  int x2 = 3 * SCREEN_WIDTH / 4; // Centro del ojo derecho
  int y = SCREEN_HEIGHT / 2; // Centro vertical

  // Dibuja el ojo izquierdo
  display.fillCircle(x1, y, radius, SSD1306_WHITE);

  // Dibuja el ojo derecho
  display.fillCircle(x2, y, radius, SSD1306_WHITE);

  // Dibujar triángulo negro en la parte inferior del ojo izquierdo
  int triangleHeight = 10;
  display.fillTriangle(x1 - radius, y + radius, x1 + radius, y + radius, x1, y + radius - triangleHeight, SSD1306_BLACK);

  // Dibujar triángulo negro en la parte inferior del ojo derecho
  display.fillTriangle(x2 - radius, y + radius, x2 + radius, y + radius, x2, y + radius - triangleHeight, SSD1306_BLACK);
}

// Función para borrar los ojos
void clearEyes() {
  int radius = 20; // Radio del círculo

  int x1 = SCREEN_WIDTH / 4; // Centro del ojo izquierdo
  int x2 = 3 * SCREEN_WIDTH / 4; // Centro del ojo derecho
  int y = SCREEN_HEIGHT / 2; // Centro vertical

  // Borra el ojo izquierdo
  display.fillCircle(x1, y, radius, SSD1306_BLACK);

  // Borra el ojo derecho
  display.fillCircle(x2, y, radius, SSD1306_BLACK);
}
