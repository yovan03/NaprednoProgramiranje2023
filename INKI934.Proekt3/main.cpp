#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  const string str = "INKI934Jovan Metallica So close no matter how far Couldnt be much more from the heart"; // define the constant string
  int num;
  cout << "Vnesi tricifren broj: ";
  cin >> num;
  cout << "---------------------------\n";

  // izdvojuvanje najgolemata cifra od tricifreniot broj
  int largest_digit = num % 10;
  num /= 10;
  if (num % 10 > largest_digit) {
    largest_digit = num % 10;
  }
  num /= 10;
  if (num > largest_digit) {
    largest_digit = num;
  }

  // nagolemuvanje za vrednosta na najgolemata cifra na ASCII kodovite na karakterite od stringot 
  vector<char> vec;
  for (char c : str) {
    c += largest_digit;
    vec.push_back(c);
  }

  // sortiranje i pechatenje na vectorot na konzola
  sort(vec.begin(), vec.end());
  
  cout << "\nSortiran vektor: ";
  for (char c : vec) {
    cout << c << " ";
  }

  cout << endl;
  
  // zapishuvanje na vektorot vo izlezna datoteka
  ofstream output_file("INKI934.Proekt3.txt");
  if (output_file.is_open()) {
    for (char c : vec) {
      output_file << c << " ";
    }
    output_file.close();
  }

  return 0;
}