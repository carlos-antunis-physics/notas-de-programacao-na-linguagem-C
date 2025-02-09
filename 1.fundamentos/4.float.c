#include <stdio.h>

int main() {
   // aloque um número real que consistirá no raio do círculo
   float raio;
   // aloque um número real para armazenar o valor de pi
   float pi = 3.1415;
   // requisite o valor do raio
   printf("insira o valor do raio: ");
   scanf("%f", &raio);             // leia o valor
   // informe o valor da circunferência
   printf("circunferência = %f\n", 2. * pi * raio);
   return 0;
}