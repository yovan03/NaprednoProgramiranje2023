#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	int num, guess, tries = 0;
	srand(time(0)); //random generator za broj
	num = rand() % 100 + 1; // random broj od 1 do 100
	cout << "Pogodi go brojot!\n\n";

	do
	{
		cout << "Vnesete broj pomegju 1 i 100 : ";
		cin >> guess;
		tries++;

		if (guess > num)
			cout << "Premnogu visoko!\n\n";
		else if (guess < num)
			cout << "Premnogu nisko!\n\n";
		else
			cout << "\nGo pogodivte brojot! Vi bea potrebni " << tries << " obidi!\n";
	} while (guess != num);

	return 0;
}	