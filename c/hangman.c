#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SECRET_WORD "engineering"
#define MAX_ERRORS 5

void header(int size) {
  printf("#***************************************#\n");
  printf("#                HANGMAN                #\n");
  printf("#***************************************#\n");
  printf("# %d letras\n\n", size);
}

int main() {
  char letter;
  int size = strlen(SECRET_WORD);
  char word[size + 1];
  bool run = true;
  int great = 0;
  int errors = 0;

  header(size);
 
  for (int i=0; i < size; i++) {
    word[i] = '_';
  }

  do {
    int count = 0;
    printf("\n%s\n", word);
    printf("Erros: %d/7\n", errors);
    printf("Chute uma letra: ");
    scanf(" %c", &letter);

    for (int i=0; i < size; i++) {
      if (letter == SECRET_WORD[i]) {
        if (letter == word[i]) {
          printf("Você ja chutou essa letra!\n\n");
          break;
        } else {
          word[i] = letter;
          count++;
        }
      }
    }

    if (count == 0) {
      errors++;
    } else {
      great = great + count;
    }

    if (great == size) {
      printf("\nParabéns, você encontrou a palavra secreta: %s", word);
      printf("\n🎉🎉🎉🎉🎉🎉🎉\n");
      run = false;
    } else if (errors == MAX_ERRORS) {
      printf("\nInfelizmente você não encontrou a palavra secreta: %s", SECRET_WORD);
      printf("\n😓😓😓😓😓😓😓\n");
      run = false;
    }
  } while (run);
  return 0;
}