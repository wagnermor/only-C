#include <stdio.h>

int main() {
  char palavraSecreta[20];
  sprintf(palavraSecreta, "MELANCIA E MAMÃO");
  printf("%s\n", palavraSecreta);

  /*palavraSecreta[0] = 'M';
  palavraSecreta[1] = 'E';
  palavraSecreta[2] = 'L';
  palavraSecreta[3] = 'A';
  palavraSecreta[4] = 'N';
  palavraSecreta[5] = 'C';
  palavraSecreta[6] = 'I';
  palavraSecreta[7] = 'A';
  palavraSecreta[8] = '\0'; Para saber que o array é menor que as 20 posições declaradas.
  
  printf("%c%c%c%c%c%c%c%c\n", palavraSecreta[0], palavraSecreta[1],
    palavraSecreta[2], palavraSecreta[3], palavraSecreta[4],
    palavraSecreta[5], palavraSecreta[6], palavraSecreta[7]);*/
}
