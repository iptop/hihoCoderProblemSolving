#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <fstream>
using namespace std;

struct commodity
{
	int need;
	int value;
};
void inputdata(int * n ,int * m, commodity ** commoditys){
	cin >> *n>>*m;
	*commoditys = new commodity[*n];
	for (int i = 0; i < *n; i++){
		int n, v;
		cin >> (*commoditys)[i].need >> (*commoditys)[i].value;
	}
}
void calculate(int n, int m, commodity* commoditys){
	int ** dp = new int*[n];
	for (int i = 0; i < n; i++){
		dp[i] = new int[m+1];
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j <= m; j++){
			int max1;
			if (i - 1 >= 0){
				max1 = dp[i - 1][j];
			}
			else{
				max1 = 0;
			}
			int max2;
			if (i == 0){
				if (j >= commoditys[i].need){
					max2 =commoditys[i].value;
				}
				else{
					max2 = 0;
				}
			}
			else{
				if (j >= commoditys[i].need ){
					max2 = dp[i - 1][j - commoditys[i].need] + commoditys[i].value;
				}
				else{
					max2 = 0;
				}
			}

			if (max1 > max2){
				dp[i][j] = max1;
			}
			else{
				dp[i][j] = max2;
			}
		}
	}
	//ofstream fout("log.txt");
	//for (int i = 0; i <= m; i++){
	//	for (int j = 0; j < n; j++)
	//	{
	//		fout << dp[j][i] << "\t";
	//	}
	//	fout << endl;
	//}

	cout << dp[n - 1][m];

}
int main()
{
	int n, m;
	commodity * commoditys=NULL;
	inputdata(&n, &m, &commoditys);
	calculate(n, m, commoditys);


}