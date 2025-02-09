#include <stdio.h>

int main() {
    // aloque dois inteiros que consistirão nos operandos
    int a, b;
    // requisite o primeiro operando
    printf("insira o primeiro operando: ");
    scanf("%d", &a);                // leia o valor
    // requisite o segundo operando
    printf("insira o segundo operando: ");
    scanf("%d", &b);                // leia o valor
    // escreva o resultado das operações
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d mod %d = %d\n", a, b, a % b);
    return 0;
}