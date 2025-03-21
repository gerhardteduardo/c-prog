#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ERRORS 5

void clear() {
  #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif
}

void header(int size) {
  printf("#***************************************#\n");
  printf("#                HANGMAN                #\n");
  printf("#***************************************#\n");
  printf("# %d letras\n\n", size);
}

void hangman(int errors) {
  printf(" ______");
  printf("\n |    |");
  if (errors > 0) {
    printf("\n |    o ");
  } else {
    printf("\n |     ");
  }
  if (errors > 1) {
    printf("\n |   /|\\");
  } else {
    printf("\n |     ");
  }
  if (errors > 2) {
    printf("\n |    |");
  } else {
    printf("\n |     ");
  }
  if (errors > 3) {
    printf("\n |   / \\");
  } else {
    printf("\n |     ");
  }
  printf("\n |");
  printf("\n_|_");
}

bool isCorrect(char letter, char *ptr,  const char *secret) {
  bool ret = false;
  for (int i=0; i < strlen(secret); i++) {
    if (letter == secret[i]) {
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

bool isWin(char *ptr, const char *secret) {
  bool ret = true;
  for (int i=0; i < strlen(secret); i++) {
    if (ptr[i] != secret[i]) {
      ret = false;
    }
  }
  return ret;
}

bool randomWord(char *ptr) {
  FILE *fp = NULL;
  char word[256];

  fp = fopen("words.txt", "r");

  if (fp == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return false;
  }

  srand((unsigned int) time(NULL));

  for (int i = 0; i <= (rand() % 100); i++) {
    if (fgets(word, sizeof(word), fp) == NULL) {
      fclose(fp);
      return false;
    }
  }

  word[strcspn(word, "\r\n")] = 0;
  strcpy(ptr, word);

  fclose(fp);
  return true;
}

int main() {
  char letter;
  int size;
  char secret_word[256];
  char kicks[MAX_ERRORS + 1] = "";
  bool run = true;

  if (!randomWord(secret_word)) {
    return 0;
  } else {
    size = strlen(secret_word);
  }

  char word[size + 1];

  header(size);
 
  for (int i=0; i < size; i++) {
    word[i] = '_';
  }
  word[size] = '\0';

  do {
    printf("\n# %s\n", kicks);
    hangman(strlen(kicks));
    printf("   %s\n\n", word);
    printf("Chute: ");
    scanf(" %c", &letter);

    clear();
    usleep(100000);

    if (!isCorrect(letter, word, secret_word)) {
      if (!isError(letter, kicks)) {
        printf("Você ja chutou essa letra!\n");
      }
    }

    if (isWin(word, secret_word)) {
      printf("\nParabéns, você encontrou a palavra secreta: %s", word);
      printf("\n🎉🎉🎉🎉🎉🎉🎉\n");
      run = false;
    } else if (strlen(kicks) == MAX_ERRORS) {
      printf("\nInfelizmente você não encontrou a palavra secreta: %s", secret_word);
      printf("\n😓😓😓😓😓😓😓\n");
      run = false;
    }
  } while (run);
  return 0;
}