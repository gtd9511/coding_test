#include <iostream>
using namespace std;

//10 000 000 000 000 000
//2 4 8 16 32 64 128 256 512 1024
int arr[55] = {0, };
// long long count_one_two(long long x)
// {
// 	if (x == 1)
// 		return 2;
// 	else if (x == 2)
// 		return 5;
// 	else
// 	 	return (pow(2, x - 1) + pow(2, x - 2) * (x - 1));

// }

long long count_one(long long x)
{
	if (x == 1)
		return 1;
	if (x == 2)
		return 2;
	if (x == 3)
		return 4;
	long long res = 0;
	int i = 0;
	while (pow(2, i) < x)
	{
		// cout << "x : " << x << endl;
		// cout << "i : " << i << endl;
		// cout << endl;
		// res += 2 ^ (i - 1) + (2 ^ (i - 2)) * (i - 1);
		i++;
	}
	res += arr[i - 1];
	// x -= 2 ^ i;
	// res += count_one(x - pow(2, i - 1)) + 1;
	// res = i - 1;
	return res;
}

int main()
{
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 5;
	for (int i = 3; i < 55; i++)
		arr[i] = arr[i - 1] + pow(2, i - 1) + (pow(2, i - 2) * (i - 1));

	long long A, B;
	cin >> A >> B;
	cout << count_one(A) << endl;
	cout << count_one(B) << endl;
	return (0);
}


//  1	1	1	1
//1

// 10	1	2	2		2

// 11	2	4	3
// 2 + 1	3

//100	1	5	4		5	2 + 2 + 1

//101	2	7	5
//110	2	9	6
//111	3	12	7
// 4 + 2 + 2	8

//1000	1	13	8		13	5 + 4 + 2 + 2

//1001	2	15	9
//1010	2	17	10
//1011	3	20	11
//1100	2	22	12

//1101	3	25	13
//1110	3	28	14
//1111	4	32	15
//8 + 4 + 4 + 4	20
//10000 1	33	16		33	13 + 8 + 4 + 4 + 4
//2 ^ N = 2 ^ (N - 1) + 2 ^ (N - 2) * (N - 1)


//4 = 2 + 1 * 1 = 3


//34 100010


//15 32 13+12
