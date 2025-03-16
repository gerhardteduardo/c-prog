#include <iostream>

using namespace std;

#define word "engineering"

int main() {
  char letter;

  cout << "Chute uma letra: ";
  cin >> letter;

  if (letter == word[0]) {
    cout << letter << endl;
  }

  return 0;
}