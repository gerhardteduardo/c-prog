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

bool isCorrect(char letter, char *ptr) {
  bool ret = false;
  for (int i=0; i < strlen(SECRET_WORD); i++) {
    if (letter == SECRET_WORD[i]) {
      ptr[i] = letter;
      ret = true;
    }
  }
  return ret;
}

bool isError(char letter, char *ptr) {
  bool ret = true;
  for (int i=0; i < MAX_ERRORS; i++) {
    if (letter == ptr[i]) {
      ret = false;
    }
  }
  if (ret) {
    ptr[strlen(ptr)] = letter;
  }
  return ret;
}

bool isWin(char *ptr) {
  bool ret = true;
  for (int i=0; i < strlen(SECRET_WORD); i++) {
    if (ptr[i] != SECRET_WORD[i]) {
      ret = false;
    }
  }
  return ret;
}

int main() {
  char letter;
  int size = strlen(SECRET_WORD);
  char word[size + 1];
  char kicks[MAX_ERRORS + 1];
  bool run = true;

  header(size);
 
  for (int i=0; i < size; i++) {
    word[i] = '_';
  }

  do {
    int count = 0;
    printf("\n%s\n", word);
    printf("Chutes errados (%ld/5): %s\n", strlen(kicks), kicks);
    printf("Chute uma letra: ");
    scanf(" %c", &letter);

    if (!isCorrect(letter, word)) {
      if (!isError(letter, kicks)) {
        printf("Você ja chutou essa letra!\n\n");
      }
    }

    if (isWin(word)) {
      printf("\nParabéns, você encontrou a palavra secreta: %s", word);
      printf("\n🎉🎉🎉🎉🎉🎉🎉\n");
      run = false;
    } else if (strlen(kicks) == MAX_ERRORS) {
      printf("\nInfelizmente você não encontrou a palavra secreta: %s", SECRET_WORD);
      printf("\n😓😓😓😓😓😓😓\n");
      run = false;
    }
  } while (run);
  return 0;
}