#include <stdio.h>
#include <stdlib.h> //to use the rand and srand functions
#include <time.h> //to use the time function

//command to compile the code in the linux terminal: "gcc nomeProgrma.c -o nomePrograma.out"

//to run the compiled program, just type the address of the complete compiled file: ./nameProgram.out

int main() {
  srand(time(NULL)); //For the rand function not to be repeated, it is necessary to use the srand functions (time (NULL))
  int secretNumber = rand() % 100; //randomic function

  // imprime cabecalho do nosso jogo
  printf("\n********************************************\n");
  printf("***** Bem vindo ao jogo da adivinhação *****\n");
  printf("********************************************\n");
  printf("                                                  !_\n");
  printf("                                                  |*~=-.,\n");
  printf("                                                  |_,-'`\n");
  printf("                                                  |\n");
  printf("                                                  |\n");
  printf("                                                 /^\\\n");
  printf("                   !_                           / %d\\\n",secretNumber);
  printf("                   |*`~-.,                     /,    \\ \n");
  printf("                   |.-~^`                     /#\"     \\\n");
  printf("                   |                        _/##_   _  \\_\n");
  printf("              _   _|  _   _   _            [ ]_[ ]_[ ]_[ ]\n");
  printf("             [ ]_[ ]_[ ]_[ ]_[ ]            |_=_-=_ - =_|\n");
  printf("           !_ |_=_ =-_-_  = =_|           !_ |=_= -    |\n");
  printf("           |*`--,_- _        |            |*`~-.,= []  |\n");
  printf("           |.-'|=     []     |   !_       |_.-\"`_-     |\n");
  printf("           |   |_=- -        |   |*`~-.,  |  |=_-      |\n");
  printf("          /^\\  |=_= -        |   |_,-~`  /^\\ |_ - =[]  |\n");
  printf("      _  /   \\_|_=- _   _   _|  _|  _   /   \\|=_-      |\n");
  printf("     [ ]/,    \\[ ]_[ ]_[ ]_[ ]_[ ]_[ ]_/,    \\[ ]=-    |\n");
  printf("      |/#\"     \\_=-___=__=__- =-_ -=_ /#\"     \\| _ []  |\n");
  printf("     _/##_   _  \\_-_ =  _____       _/##_   _  \\_ -    |\\\n");
  printf("    [ ]_[ ]_[ ]_[ ]=_0~{_   _}~0   [ ]_[ ]_[ ]_[ ]=-   | \\\n"); 
  printf("    |_=__-_=-_  =_|-=_ |  ,  |     |_=-___-_ =-__|_    |  \\\n");
  printf("     | _- =-     |-_   | ((* |      |= _=       | -    |___\\\n");
  printf("     |= -_=      |=  _ |  `  |      |_-=_       |=_    |/+\\|\n");
  printf("     | =_  -     |_ = _ `-.-`       | =_ = =    |=_-   ||+||\n");
  printf("     |-_=- _     |=_   =            |=_= -_     |  =   ||+||\n");
  printf("     |=_- /+\\    | -=               |_=- /+\\    |=_    |^^^|\n");
  printf("     |=_ |+|+|   |= -  -_,--,_      |_= |+|+|   |  -_  |=  |\n");
  printf("     |  -|+|+|   |-_=  / |  | \\     |=_ |+|+|   |-=_   |_-/\n");
  printf("     |=_=|+|+|   | =_= | |  | |     |_- |+|+|   |_ =   |=/\n");
  printf("     | _ ^^^^^   |= -  | |  | <>    |=_=^^^^^   |_=-   |/\n");
  printf("     |=_ =       | =_-_| |  | |     |   =_      | -_   |\n");
  printf("     |_=-_       |=_=  | |  | |     |=_=        |=-    |\n");
  printf("^^^^^^^^^^`^`^^`^`^`^^^""""""""^`^^``^^`^^`^^`^`^``^`^``^``^^\n");


  //printf("\n%d\n", secretNumber);
  
  int attempt;
  int attemptLoop = 1;
  double points = 1000;

  int win = 0;
  
  int level;
  printf("Qual o nível de dificuldade?\n");
  printf("(1)>> Fácil | (2)>> Médio | (3)>> Difícil");
  printf("Escolha: ");
  scanf("%d", &level);
  
  int attemptNumber;

  switch(level) {
    case 1:
      attemptNumber = 30;
      break;
    case 2:
      attemptNumber = 15;
      break;
    case 3:
      attemptNumber = 5;
      break;
    default: 
      printf("\nESCOLHA INVÁLIDA!\n");
      attemptNumber = 0;
      break;
  }
  /*if(level == 1) {
    attemptNumber = 30;
  } else if(level == 2) {
    attemptNumber = 15;
  } else if(level == 3) {
    attemptNumber = 5;
  } else {
    printf("\nESCOLHA INVÁLIDA!\n");
    attemptNumber = 0;
  }*/


  printf("\n*** Escolha um número entre 0  e 100 ***\n");
  for(int i = 1; i <= attemptNumber; i++) {
    printf("\n>> Tentativa nº %d. \n", i);
    printf("Qual é o seu chute? ");

    scanf("%d", &attempt);
    printf("Seu chute foi %d\n", attempt);

    if(attempt < 0) {
      printf("VOCÊ NÃO PODE DIGITAR NÚMEROS NEGATIVOS!\n");
      i--;
      continue; //pauses the code flow and skips to next loop interaction
    }

    int win = (attempt == secretNumber);
    int attemptBiggerThanSecretNumber = (attempt > secretNumber);

    if(win) {
      break;
    } else if(attemptBiggerThanSecretNumber) {
      printf("Seu chute foi maior que o número secreto\n");
    } else {
      printf("Seu chute foi menor que o número secreto\n");
    }
    double lostPoints = abs(attempt - secretNumber) / (double)2;
    /*
    *** the abs function transform a negative number to positive number
    */

    points = points - lostPoints;
    printf("\n          Pontuação: %.2f\n", points);
    attemptLoop++;
  }
  printf("\n*** FIM DE JOGO! *** ");

  if(attempt == secretNumber) {
    printf("\n    VOCÊ GANHOU!\n");
    printf("\nWe are the champions, my friends");
    printf("\nAnd we'll keep on fighting till the end...");
    printf("\n                      (Queen Music Limited)\n");
    printf("\nVocê acertou em %d tentativa(s).\n", attemptLoop);
    printf("Total de pontos: %.2f pontos.\n\n\n", points);
  } else {
    printf("\nVOCÊ PERDEU, TENTE DE NOVO!\n\n\n");
  }
      
}
