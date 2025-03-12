#include <stdio.h>
#include <string.h>

void CheckIsPalindrome() {
  char str[] = "arara";

  for (int i=0; i < 5; i++) {
    int size = strlen(str);
    if (!(str[i] == str[((size - 1) - i)])) {
      printf("Not Palindrome");
      break;
    }
  }
}

int main() {
  CheckIsPalindrome();
}