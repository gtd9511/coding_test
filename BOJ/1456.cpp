#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> ap;
bool prime[10000001];

long long A, B;
int main()
{
	for (int i = 2; i < 10000001; i++)
	{
		if (prime[i] == 0)
		{
			int temp = 2;
			while (temp * i < 10000001)
			{
				prime[temp * i] = 1;
				temp++;
			}
		}
	}
	// cout << "A\n";
	// for (long long i = 2; i < 10000001; i++)
	for (long long i = 2; i < 100000; i++)
	{
		if (prime[i] == 0)
		{
			long long temp = i;
			// cout << temp << "\n";
			temp *= temp;
			while (temp < 100000000000001)
			{
				// if (temp == 0)
				// {
				// 	cout << temp <<"\n";
				// 	break;
				// }
				// cout << temp << "\n";
				ap.push_back(temp);
				temp *= i;
			}
		}
	}
	for (long long i = 100001; i < 10000001; i++)
	{
		if (prime[i] == 0)
			ap.push_back(i * i);
	}
	// cout << "B\n";
	// cout << ap.size() << endl;
	sort(ap.begin(), ap.end());
	// cout << "ap : " << endl;
	// for (int i = 0; i < 10; i++)
		// cout << ap[i] << " ";
	// cout << endl;

	cin >> A >> B;
	cout << upper_bound(ap.begin(), ap.end(), B) - lower_bound(ap.begin(), ap.end(), A);
	// int apA = 0, apB = 0;
	// for (int i = 0; i < ap.size(); i++)
	// {
	// 	if (ap[i] lowerbound A)
	// 	{
	// 		apA = i;
	// 		break;
	// 	}
	// 	apA = 0;
	// }
	// if (B < 4)
	// {
	// 	cout << 0;
	// 	return (0);
	// }
	// if (B >= 99999820000081)
	// 	apB = 670120;
	// else
	// {
	// 	for (int i = 0; i < ap.size(); i++)
	// 	{
	// 		if (ap[i] > B)
	// 		{
	// 			apB = i - 1;
	// 			break;
	// 		}
	// 		apB = 0;
	// 	}
	// }
	// int apA = 0, apB = 0;
	// for (int i = 0; i < ap.size(); i++)
	// {
	// 	if (ap[i] >= A)
	// 	{
	// 		apA = i;
	// 		break;
	// 	}
	// 	apA = 0;
	// }
	// if (B < 4)
	// {
	// 	cout << 0;
	// 	return (0);
	// }
	// if (B >= 99999820000081)
	// 	apB = 670120;
	// else
	// {
	// 	for (int i = 0; i < ap.size(); i++)
	// 	{
	// 		if (ap[i] > B)
	// 		{
	// 			apB = i - 1;
	// 			break;
	// 		}
	// 		apB = 0;
	// 	}
	// }
	// cout << "apA : " << apA << " : " << ap[apA] << "\n";
	// cout << "apB : " << apB << " : " << ap[apB] << "\n";
	// int a = ap.size() - 1;
	// cout << ap.size() << endl;;
	// cout << "! :" << ap[a] << endl;
	// while (ap[apA] > A)
	// 	apA++;
	// while (ap[apB] > B)
	// 	apB++;
	// cout << apB - apA + 1;
	return (0);
}
// 9 999 995 824 729
// 10 000 000 000 000
// 100 000 000 000 000
// 4 8 9

// 100 000 000 000 000
// 99999900000000
