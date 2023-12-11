#include <LiquidCrystal.h>

// Definir los pines para los botones y la Pantallita LCD
const int botonRojo = 2;
const int botonAzul = 3;
const int brazzer = 4;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Variables para almacenar el estado de los botones y el texto en Morse
int estadoBotonRojo = 0;
int estadoBotonAzul = 0;
int vectorMorse[5];
int i = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(botonRojo, INPUT_PULLUP);
  pinMode(botonAzul, INPUT_PULLUP);
}

void loop() {
  estadoBotonRojo = digitalRead(botonRojo);
  if (estadoBotonRojo == HIGH) {
    float tiempo = cuantoTiempo();
    if (tiempo < 0.05) {
      vectorMorse[i] = 1;
    } else if (tiempo >= 0.5) {
      vectorMorse[i] = 2;
    }
    i++;
  }

  estadoBotonAzul = digitalRead(botonAzul);
  if (estadoBotonAzul == HIGH) {
    EscribirLetra();
    for (int j = 0; j < 5; j++) {
      vectorMorse[j] = 0;
    }
    i = 0;
  }
}

float cuantoTiempo() {
  float tiempoInicial = millis();
  while (digitalRead(botonRojo) == HIGH) {}
  float tiempoFinal = millis();
  float deltaTiempo = (tiempoFinal - tiempoInicial) / 1000;
  Serial.println(deltaTiempo);
  return deltaTiempo;
}

void EscribirLetra() {
 // Definir las letras en código Morse
 int A[5] = {1, 2, 0, 0, 0};
 int B[5] = {2, 1, 1, 1, 0};
 int C[5] = {2, 1, 2, 0, 0};
 int D[5] = {2, 1, 1};
 int E[5] = {1};
 int F[5] = {2, 2, 1, 0, 0};
 int G[5] = {2, 2, 2, 0, 0};
 int H[5] = {4, 1, 0, 0, 0};
 int I[5] = {2, 2};
 int J[5] = {2, 4, 0, 0, 0};
 int K[5] = {2, 1, 2, 0, 0};
 int L[5] = {2, 1, 2, 1, 0};
 int M[5] = {3, 2, 0, 0, 0};
 int N[5] = {2, 2, 1};
 int O[5] = {3, 2, 2, 2, 0};
 int P[5] = {2, 2, 1, 2, 0};
 int Q[5] = {2, 2, 2, 1, 2};
 int R[5] = {2, 1, 2, 0, 0};
 int S[5] = {4, 2, 0, 0, 0};
 int T[5] = {2, 0, 0, 0, 0};
 int U[5] = {2, 2, 1, 0, 0};
 int V[5] = {3, 2, 2, 1, 0};
 int W[5] = {2, 2, 2, 0, 0};
 int X[5] = {2, 2, 1, 2, 0};
 int Y[5] = {2, 2, 2, 2, 0};
 int Z[5] = {2, 3, 2, 1, 0};

 // Comprobar qué letra se ingresó
 if (compararArreglos(vectorMorse, A)) {
   lcd.print("A");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, B)) {
   lcd.print("B");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, C)) {
   lcd.print("C");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, D)) {
   lcd.print("D");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, E)) {
   lcd.print("E");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, F)) {
   lcd.print("F");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, G)) {
   lcd.print("G");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, H)) {
   lcd.print("H");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, I)) {
   lcd.print("I");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, J)) {
   lcd.print("J");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, K)) {
   lcd.print("K");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, L)) {
   lcd.print("L");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, M)) {
   lcd.print("M");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, N)) {
   lcd.print("N");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, O)) {
   lcd.print("O");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, P)) {
   lcd.print("P");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, Q)) {
   lcd.print("Q");
   tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, R)) {
  lcd.print("R");
  tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, S)) {
  lcd.print("S");
  tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, T)) {
  lcd.print("T");
  tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, U)) {
  lcd.print("U");
  tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, V)) {
  lcd.print("V");
  tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, W)) {
  lcd.print("W");
  tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, X)) {
  lcd.print("X");
  tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, Y)) {
  lcd.print("Y");
  tone(brazzer, 440, 600);
 } else if (compararArreglos(vectorMorse, Z)) {
  lcd.print("Z");
  tone(brazzer, 440, 600);
 }

 delay(600);
}

bool compararArreglos(int arr1[5], int arr2[5]) {
 for (int i = 0; i < 5; i++) {
  if (arr1[i] != arr2[i]) {
    return false;
  }
 }
 return true;
}

