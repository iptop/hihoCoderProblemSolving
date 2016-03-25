#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
using namespace std;
void swap(int *a, int *b){
		int temp = *a;
		*a = *b;
		*b = temp;
}
void sort(int *a,int *b,int *c){
	if (*a > *b){
		swap(a, b);
	}
	if (*b > *c){
		swap(b, c);
	}
	if (*a > *b){
		swap(a, b);
	}
}
int abs(int x){
	if (x < 0){
		return -x;
	}
	else{
		return x;
	}
}
void dx(int *d1,int *d2,int *d3,int cr,int cy,int cb){
	*d1 = abs(cr - cy);
	*d2 = abs(cy - cb);
	*d3 = abs(cb - cr);
}
bool cmp(int d1,int d2,int d3,int x,int y,int z){
	sort(&d1, &d2, &d3);
	if (d1 == x && d2 == y && d3 == z){
		return true;
	}
	return false;
}
int main()
{
	int x, y, z;
	int cr=0, cy=0, cb=0;
	int d1, d2, d3;
	int max = 0;
	string s;
	cin >> x >> y >> z;
	sort(&x, &y, &z);
	cin >> s;
	for (string::iterator i = s.begin(); i < s.end(); i++){
		if (*i == 'R'){
			cr++;
		}
		else if (*i == 'Y'){
			cy++;
		}
		else{
			cb++;
		}
		dx(&d1, &d2, &d3, cr, cy, cb);
		int sum = cr + cy + cb;
		if (sum > max){
			max = sum;
		}
		if (cmp(d1, d2, d3, x, y, z)){
			cr = 0, cy = 0, cb = 0;
		}

	}
	cout << max<<endl;
	return 0;
}
