#include <bits/stdc++.h>
using namespace std;
map<string,int>m1,m2;
map<string,int>::iterator it;
int main()
{
	string a,b,c;
	int n,m;
	cin>>n;
	cin>>m;
	for (int i=1;i<=m;i++){
		cin>>a>>b>>c;
		m1[a+" "+c]=1;
	}
	for (int i=2;i<=n;i++){
		cin>>m;
		m2.clear();
		for (int j=1;j<=m;j++){
			cin>>a>>b>>c;
			m2[a+" "+c]=1;
		}
		for (it=m1.begin();it!=m1.end();it++){
			if (m2.find(it->first)==m2.end()){
				m1.erase(it->first);
			}
		}
	}
	for (it=m1.begin();it!=m1.end();it++){
		cout<<it->first.substr(0,9)<<endl;
	}
	return 0;
}

