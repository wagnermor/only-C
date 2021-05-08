#include <stdio.h>
#include <stdlib.h> //to use the rand and srand functions
#include <time.h> //to use the time function

#define NUMBER_OF_ATTEMPTS 5 //The directive / constant in C is declared in uppercase and separated by underline.

//command to compile the code in the linux terminal: "gcc nomeProgrma.c -o nomePrograma.out"

//to run the compiled program, just type the address of the complete compiled file: ./nameProgram.out

int main() {
  // imprime cabecalho do nosso jogo
  printf("********************************************\n");
  printf("***** Bem vindo ao jogo da adivinhação *****\n");
  printf("********************************************\n");

  srand(time(NULL)); //For the rand function not to be repeated, it is necessary to use the srand functions (time (NULL))

  int secretNumber = rand() % 100; //randomic function
  int division = secretNumber / 2;
  printf("                                  ~(%d + %d)", division, division);
  int attempt;

  for(int i = 1; i <= NUMBER_OF_ATTEMPTS; i++) {
    printf("\nTentativa %d de %d\n", i, NUMBER_OF_ATTEMPTS);
    printf("Qual é o seu chute? ");
    scanf("%d", &attempt);
    printf("Seu chute foi %d\n", attempt);

    if(attempt < 0) {
      printf("VOCÊ NÃO PODE DIGITAR NÚMEROS NEGATIVOS!\n");
      i--;
      continue; //pauses the code flow and skips to the nest for loop interaction
    }

    int acertou = (attempt == secretNumber);
    int attemptBiggerThanSecretNumber = (attempt > secretNumber);

    if(acertou) {
      printf("\nVOCÊ ACERTOU, PARABÉNS!\n");
      printf("\nWe are the champions, my friends");
      printf("\nAnd we'll keep on fighting till the end...");
      printf("\n                      (Queen Music Limited)");
      break;
    } 
    else if(attemptBiggerThanSecretNumber) {
      printf("Seu chute foi maior que o número secreto\n");
    }
    else {
      printf("Seu chute foi menor que o número secreto\n");
    }
    if(i == NUMBER_OF_ATTEMPTS) {
      printf("\nVOCÊ ERROU AS %d TENTATIVAS\n", NUMBER_OF_ATTEMPTS);
      printf("O número secreto é: %d\n", secretNumber);
    }
  }
  printf("\nFIM DO JOGO!\n");
}
