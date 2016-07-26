#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <fstream>
#include <bitset>
using namespace std;

int main()
{

    int x;
    cin>>x;
    for (int i = 0; i <24 ; ++i) {
        for (int j = 0; j < 60; ++j) {
            bitset<5> b1(i);
            bitset<6> b2(j);
            if( (b1.count()+b2.count())==x){
                if(i<10){
                    cout<<"0";
                }
                cout<<i<<":";
                if(j<10){
                    cout<<"0";
                }
                cout<<j<<endl;
            }
        }
    }
    return 0;
}