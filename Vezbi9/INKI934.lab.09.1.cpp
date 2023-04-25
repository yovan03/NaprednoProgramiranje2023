#include<iostream>
#include <string>
#include <cstdlib>
#include <ctype.h>
using namespace std;
 
void Count(string str)
{
    int upper = 0, lower = 0, number = 0, special = 0;
    
    for (int i = 0; i < str.length(); i++)
    {
        if (isupper (str[i]) )
            upper++;
        else if (islower (str[i]) )
            lower++;
        else if (isdigit (str[i]) )
            number++;
        else
            special++;
    }
    cout << "\n--------------------------" << endl;
    cout << "\nVo rechenicta ima: " << endl;
    cout << "Golemi bukvi: " << upper << endl;
    cout << "Mali bukvi: " << lower << endl;
    cout << "Broevi : " << number << endl;
    cout << "Specijalni znaci: " << special << endl;
}
 
int main()
{
    string str;
    cout << "Vnesi rechenica:"<< endl;
    getline(cin, str);
    Count(str);
    return 0;
}