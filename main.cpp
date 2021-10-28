#include <iostream>

using namespace std;

void printMessage (string message, bool, bool);
void drawHangMan (int);
void printLetters (string, char, char);
void printAvailLetters (string);
int main() {
  string guesses;
  printMessage("HANG MAN", true, true);
  drawHangMan(9);
  printLetters("SHIRLEY", 'A', 'M');
   printLetters("SHIRLEY", 'N', 'Z');
  return 0;
} 

void printMessage (string message, bool top = true, bool bottom = true) {
  if (top) {
    //33 -
    cout << "+---------------------------------+" << endl;
    cout << '|';
  }
  else {
    cout << "|"; //side border
  }

  bool front = true;

  for (int i = message.length(); i < 33; ++i) {
    if (front) {
      message = ' ' + message;
    }
    else {
      message = message + ' ';
    }
    front = !front;
  }
  cout << message;

  if (bottom) {
    //33 -
    cout << '|' << endl;
    cout << "+---------------------------------+" << endl;
  }
  else {
    cout << "|" << endl; //side border
  }
}

void drawHangMan (int guessCount = 0) {
  if (guessCount >= 1) {
    printMessage("|", false, false); //only print rope, not borders
  }
  else {
    printMessage("", false, false);
  }

  if (guessCount >= 2) {
    printMessage("|", false, false); //only print rope, not borders
  }
  else {
    printMessage("", false, false);
  }

  if (guessCount >= 3) {
    printMessage("O", false, false); //only print head, not borders
  }
  else {
    printMessage("", false, false);
  }

  if (guessCount == 4) {
    printMessage("/  ", false, false); //only print left arm
  }

  if (guessCount == 5) {
    printMessage("/| ", false, false); //print left arm and body
  }

  if (guessCount >= 6) {
    printMessage("/|\\", false, false); //print left arm and body
  }
  else {
    printMessage("", false, false);
  }

  if (guessCount >= 7) {
    printMessage("|", false, false); 
  }
  else {
    printMessage("", false, false);
  }

  if (guessCount == 8) {
    printMessage("/  ", false, false); 
  }
  
  if (guessCount >= 9) {
    printMessage("/ \\", false, false); //print left arm and body
  }
  else {
    printMessage("", false, false);
  }
}

void printLetters (string input, char from, char to) {
  string s;

  for (char i = from; i <= to; ++i) {
    if(input.find(i) == string::npos) { //not find
      s += i;
      s += ' ';
    }
    else {
      s += "  ";
    }
  }
  printMessage(s, false, false);
}