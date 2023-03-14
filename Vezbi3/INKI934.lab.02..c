#include <bits/stdc++.h>
using namespace std;

enum Month {
Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

int main(){
    for (int i = Jan; i <= Dec; i++)
    cout << i <<" ";
    Month month = Apr;
    cout<<endl;
    switch (month){
    case Jan: case Feb: case Mar:
        cout<<month<<" Winter"; break;
    case Apr: case May: case Jun:
        cout<<month<<" Spring"; break;
    case Jul: case Aug: case Sep:
        cout<<month<<" Summer"; break;
    case Oct: case Nov: case Dec:
        cout<<month<<" Autumn"; break;
    }
}
