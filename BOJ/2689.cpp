#include <iostream>
using namespace std;

int A, B, V;

int main()
{
	cin >> A >> B >> V;
	int day = (V - B - 1) / (A - B) + 1;
	// int day = 0;
	// while (1)
	// {
	// 	day++;
	// 	V -= A;
	// 	if (V <= 0)
	// 		break;
	// 	V += B;
	// }
	// cout << day;
	return (0);
}
