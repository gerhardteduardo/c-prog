#include <iostream>
#include <cstring>

using namespace std;

#define SECRET_WORD "engineering"
#define MAX_ERRORS 7

void header(int size) {
  cout << "#***************************************#" << endl;
  cout << "#                HANGMAN                #" << endl;
  cout << "#***************************************#" << endl;
  cout << "# " << size << " letras / " << " Máximos de erros: " << MAX_ERRORS  << endl;

  for (int i=0; i < size; i++) {
    cout << "_ ";
  }
  cout << endl << endl;
}

int main() {
  char letter;
  int size = strlen(SECRET_WORD);
  int errors = 0;

  header(size);
 
  while (errors < MAX_ERRORS) {
    int count = 0;
    cout << "Erros: " << errors << endl;
    cout << "Chute uma letra: ";
    cin >> letter;

    for (int i=0; i < size; i++) {
      if (letter == SECRET_WORD[i]) {
        cout << letter << " ";
        count++;
      } else {
        cout << "_ ";
      }
    }

    if (count == 0) {
      errors++;
    }
    cout << endl << endl;
  }


  return 0;
}