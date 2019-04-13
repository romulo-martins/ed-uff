#include <stdio.h>
#include <stdlib.h>

/*
Q4) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne os n primeiros números primos existentes depois de n. Por exemplo, se n = 2, a
resposta será os primos 3 e 5. É necessário salientar que n não precisa ser primo. Seu programa
para quando n for menor ou igual a zero.
*/

// Verifica se um determinado numero n é primo.
// Ou seja, ao encontrar qualquer divisor que não seja 1 ou n então é primo.
int is_prime(int n) {
  if(n < 2) return 0;
  
  for(int i = 2; i < n; i++) {
    if(n % i == 0) return 0;
  }
  return 1;
}

// Exibe os n números primos existente após n.
void show_n_primes(int n) {
  printf("Os %d numeros primos apos %d são: \n", n, n);

  int count = 0;
  for(int i = n+1; count < n; i++) {
    if(is_prime(i)) {
      printf(" %d ", i);
      count++;
    }
  }
  printf("\n");
}

int main (void) {

  int n;
  do {
    printf("Informe um numero positivo N (< 0 para sair): ");
    scanf("%d", &n);
    if(n < 0) break;
    show_n_primes(n);
  } while (1);

  printf("\n");
  return 0;
}
