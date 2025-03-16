#include <iostream>
#include <cstring>

using namespace std;

#define word "engineering"

void header(int size) {
  cout << "#***************************************#" << endl;
  cout << "#                HANGMAN                #" << endl;
  cout << "#***************************************#" << endl;
  cout << "# " << size << " letras" << endl;

  for (int i=0; i < size; i++) {
    cout << "_ ";
  }
}

int main() {
  char letter;
  int size = strlen(word);

  header(size);
 

  while (true) { 
    cout << "\n\nChute uma letra: ";
    cin >> letter;

    for (int i=0; i < size; i++) {
      if (letter == word[i]) {
        cout << letter << endl;
      }
    }
  }


  return 0;
}