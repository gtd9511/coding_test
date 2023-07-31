#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	float credit[20] = {0, };
	float grade[20] = {0, };
	float final_grade = 0;
	float total_credit = 0;

	for (int i = 0; i < 20; i++)
	{
		string class_name;
		string class_credit;
		string class_grade;
		cin >> class_name >> class_credit >> class_grade;
		if (class_credit == "1.0")
			credit[i] = 1;
		else if (class_credit == "2.0")
			credit[i] = 2;
		else if (class_credit == "3.0")
			credit[i] = 3;
		else if (class_credit == "4.0")
			credit[i] = 4;

		if (class_grade == "A+")
			grade[i] = 4.5;
		else if (class_grade == "A0")
			grade[i] = 4;
		else if (class_grade == "B+")
			grade[i] = 3.5;
		else if (class_grade == "B0")
			grade[i] = 3;
		else if (class_grade == "C+")
			grade[i] = 2.5;
		else if (class_grade == "C0")
			grade[i] = 2;
		else if (class_grade == "D+")
			grade[i] = 1.5;
		else if (class_grade == "D0")
			grade[i] = 1;
		else if (class_grade == "F")
			grade[i] = 0;
		else if (class_grade == "P")
		{
			credit[i] = 0;
			grade[i] = 0;
		}
		final_grade += credit[i] * grade[i];
		total_credit += credit[i];
	}
	cout << fixed << setprecision(8) << final_grade / total_credit;
	return (0);
}
