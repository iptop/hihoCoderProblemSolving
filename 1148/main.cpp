#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LeapYear
{
private:
	int year1;
	int month1;
	int day1;
	int year2;
	int month2;
	int day2;

public:
	int judgeMonth(string month)
	{
		if ("January" == month) return 1;
		else if ("February" == month) return 2;
		else if ("March" == month) return 3;
		else if ("April" == month) return 4;
		else if ("May" == month) return 5;
		else if ("June" == month) return 6;
		else if ("July" == month) return 7;
		else if ("August" == month) return 8;
		else if ("September" == month) return 9;
		else if ("October" == month) return 10;
		else if ("November" == month) return 11;
		else return 12;
	}

	void init()
	{
		string monthStr;
		char sig;
		cin >> monthStr >> day1 >> sig >> year1;
		month1 = judgeMonth(monthStr);
		cin >> monthStr >> day2 >> sig >> year2;
		month2 = judgeMonth(monthStr);
	}

	int leapYearNum()
	{
		int lyNum = 0;
		int divide_4 = 0, divide_400 = 0, ndivide_100 = 0;
		if (month1 <= 1 || (month1 <= 2 && day1 <= 29))
			year1 -= 1;
		if (month2 <= 1 || (month2 <= 2 && day2<29))
			year2 -= 1;
		//从年份0年到开始年的闰年个数-从年分0年到结束年的闰年个数
		divide_400 = year2 / 400 - year1 / 400;
		divide_4 = year2 / 4 - year1 / 4;
		ndivide_100 = year2 / 100 - year1 / 100;
		lyNum = divide_4 + divide_400 - ndivide_100;
		return lyNum;
	}
};

int main()
{
	int n = 0;
	LeapYear leapYear;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			int lyNum = 0;
			leapYear.init();
			lyNum = leapYear.leapYearNum();
			cout << "Case #" << i << ": " << lyNum << endl;
		}
	}
	return 0;
}