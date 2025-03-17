#include <iostream>
#include <cstring>

using namespace std;

#define SECRET_WORD "engineering"
#define MAX_ERRORS 7

void header(int size) {
  cout << "#***************************************#" << endl;
  cout << "#                HANGMAN                #" << endl;
  cout << "#***************************************#" << endl;
  cout << "# " << size << " letras" << endl << endl;
}

int main() {
  char letter;
  int size = strlen(SECRET_WORD);
  char word[size + 1] = {0};
  bool run = true;
  int great = 0;
  int errors = 0;

  header(size);
 
  for (int i=0; i < size; i++) {
    word[i] = '_';
  }

  do {
    int count = 0;
    
    cout << word << endl;
    cout << "Erros: " << errors << "/7" << endl;
    cout << "Chute uma letra: ";
    cin >> letter;

    for (int i=0; i < size; i++) {
      if (letter == SECRET_WORD[i]) {
        if (letter == word[i]) {
          cout << "Você ja chutou essa letra!";
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

    cout << endl;

    if (great == size) {
      cout << "Parabéns, você encontrou a palavra secreta: " << word << endl;
      cout << "🎉🎉🎉🎉🎉🎉🎉" << endl;
      run = false;
    } else if (errors == MAX_ERRORS) {
      cout << "Infelizmente você não encontrou a palavra secreta: " << SECRET_WORD << endl;
      cout << "😓😓😓😓😓😓😓";
      run = false;
    }
    cout << endl;
  } while (run);


  return 0;
}