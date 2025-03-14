#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool CheckIsPalindrome(char str[]) {
  int size = strlen(str);
  for (int i=0; i < size; i++) {
    if (!(str[i] == str[((size - 1) - i)])) {
      return false;
    }
  }
  return true;
}

int main() {
  char word[15];

  printf("Input:");
  scanf("%s", word);

  if (CheckIsPalindrome(word)) {
    printf("# Is Palindrome! :)\n");
  } else {
    printf("# Isn't Palindrome! :(\n");
  }
}