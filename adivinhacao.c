#include <stdio.h>
#include <stdlib.h> //to use the rand and srand functions
#include <time.h> //to use the time function

//command to compile the code in the linux terminal: "gcc nomeProgrma.c -o nomePrograma.out"

//to run the compiled program, just type the address of the complete compiled file: ./nameProgram.out

int main() {
  // imprime cabecalho do nosso jogo
  printf("\n********************************************\n");
  printf("***** Bem vindo ao jogo da adivinhação *****\n");
  printf("********************************************\n");

  srand(time(NULL)); //For the rand function not to be repeated, it is necessary to use the srand functions (time (NULL))

  int secretNumber = rand() % 100; //randomic function
  double division = secretNumber / (double)2;
  printf("                                  ~(%.2f + %.2f)", division, division);
  int attempt;
  //int win = 0; only for "while(win == 0)" with "win = 1" to close te loop
  int attemptNumber = 0;
  double points = 1000;

  while(1) { // while(1) is infinity loop
    attemptNumber++;
    printf("\n>> Tentativa nº %d. \n", attemptNumber);
    printf("Qual é o seu chute? ");
    scanf("%d", &attempt);
    printf("Seu chute foi %d\n", attempt);

    if(attempt < 0) {
      printf("VOCÊ NÃO PODE DIGITAR NÚMEROS NEGATIVOS!\n");
      attemptNumber--;
      continue; //pauses the code flow and skips to next loop interaction
    }

    int acertou = (attempt == secretNumber);
    int attemptBiggerThanSecretNumber = (attempt > secretNumber);

    if(acertou) {
      printf("\nVOCÊ ACERTOU, PARABÉNS!\n");
      printf("\nWe are the champions, my friends");
      printf("\nAnd we'll keep on fighting till the end...");
      printf("\n                      (Queen Music Limited)");
      break; //The break has the same function, but to justify the existence of the win variable, let's negate the while condition to end the loop
      //win = 1;
    } 
    else if(attemptBiggerThanSecretNumber) {
      printf("Seu chute foi maior que o número secreto\n");
    }
    else {
      printf("Seu chute foi menor que o número secreto\n");
    }
    double lostPoints = abs(attempt - secretNumber) / (double)2;
    
    /*if(lostPoints < 0) {
      lostPoints = lostPoints * -1;
    }
    *** the abs function transform a negative number to positive number
    */

    points = points - lostPoints;

  }
  printf("\nFIM DO JOGO!\n");
  printf("Você acertou em %d tentativas.\n", attemptNumber);
  printf("Total de pontos: %.2f\n", points);
}
