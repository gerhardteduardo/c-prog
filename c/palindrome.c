#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool CheckIsPalindrome() {
  char str[] = "arara";

  for (int i=0; i < 5; i++) {
    int size = strlen(str);
    if (!(str[i] == str[((size - 1) - i)])) {
      return false;
    }
  }

  return true;
}

int main() {
  if (CheckIsPalindrome()) {
    printf("# Is Palindrome! :)\n");
  } else {
    printf("# Isn't Palindrome! :(\n");
  }
}