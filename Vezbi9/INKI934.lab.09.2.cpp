#include<bits/stdc++.h>
using namespace std;
  
int main(){  
  ifstream in("file1.txt");     //chitanje od file

  ofstream f("file2.txt");      //zapishuvanje vo drug file
      
  // Reading file.txt completely using 
  // END OF FILE eof() method
  while(!in.eof())
  {
    string text;       
    getline(in, text);      //chitanje string od file1
        
    f << text << endl;      //zapishuvanje na stringot od file1 vo file2
  }
  return 0;
}