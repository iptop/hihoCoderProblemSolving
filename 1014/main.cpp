#include <iostream>
#include <list>
#include <vector>
#include <map> 
#include <cstdlib>
using namespace std;

int main(int argc, char** argv) {
	map<string,int> m;
	int n;
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		for(int i=0;i<s.length();i++)
		{
			m[s.substr(0,i+1)]++;
		}
	} 
	cin>>n;
	while(n--)
	{
		string s;
		cin>>s;
		cout<<m[s]<<endl;
	}
	return 0;
}