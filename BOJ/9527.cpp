#include <iostream>
#include <cmath>
using namespace std;

//10 000 000 000 000 000
//2 4 8 16 32 64 128 256 512 1024
long long arr[55] = {0, };
long long arr2[55] = {0, };

long long count_one(long long x)
{
	if (x < 3)
		return x;
	long long res = 0;
	int i = 0;
	// long long idx = 1;
	while (arr2[i] <= x)
	{
		// cout << "d : " << idx << endl;
		// cout << "x : " << x << endl;
		// cout << "i : " << i << endl;
		// cout << endl;
		// res += 2 ^ (i - 1) + (2 ^ (i - 2)) * (i - 1);
		// idx *= 2;
		i++;
	}
	// cout << "x : " << x << " i : " << i << endl;
	res += arr[i - 1];
	// cout << "X : " << x << " i : " << i << " res : " << res << endl;
	long long temp = x - arr2[i - 1];
	res += count_one(temp) + temp;
	// x -= pow(2, i);
	// res += count_one(x) + x;
	// res = i - 1;
	return res;
}

int main()
{
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 5;
	arr2[0] = 1;
	for (int i = 1; i < 55; i++)
		arr2[i] = arr2[i - 1] * 2;
	for (int i = 3; i < 55; i++)
		arr[i] = arr[i - 1] + arr2[i - 1] + (arr2[i - 2] * (i - 1));

	long long A, B;
	cin >> A >> B;
	// cout << count_one(A) << endl;
	cout << count_one(B) - count_one(A - 1) << endl;
	// cout << count_one(B) << endl;
	// for (long long i = 9999999999999990; i < 10000000000000000; i++)
	// {
		// if (count_one(i) - count_one(i - 1) == 2)
			// break;
		// cout << i << " " << count_one(i) << " " << count_one(i) - count_one(i - 1) << endl;
	// }
	// for (long long i = 135291469823; i < 200000000000; i++)
	// {
	// 	cout << "############ " << i << " " << count_one(i) << endl;
	// }
	// cout << "135291469823 : " << count_one(135291469823) << endl;
	// cout << count_one(10000000000000000) << endl;

	return (0);
}


//  1	1	1	1
// 10	1	2	2		2 1 + 1
// 11	2	4	3		// 2 + 1		3

//100	1	5	4		5	2 + 2 + 1
//101	2	7	5
//110	2	9	6
//111	3	12	7		// 4 + 2 + 2	8

//1000	1	13	8		13	5 + 4 + 2 + 2
//1001	2	15	9
//1010	2	17	10
//1011	3	20	11
//1100	2	22	12
//1101	3	25	13
//1110	3	28	14
//1111	4	32	15		//8 + 4 + 4 + 4	20

//10000 1	33	16		33	13 + 8 + 4 + 4 + 4
//10001 2	35	17
//10010 2	37	18
//10011 3	40	19
//10100 2	42	20
//10101 3	43	21
//10110 3	43	22
//10111 4	47	23
//11000 2	49	24
//11001 3	52	25
//11010 3	55	26
//11011 4	59	27
//11100 3	62	28
//11101 4	66	29
//11110 4	70	30
//11111 5	75	31

//19 16 > 33 19 - 16 = 3 > 4 + 3

// 1 2 2 3 2 3 3 4 2 3 3 3 4 3 4 4 5

//2 ^ N = 2 ^ (N - 1) + 2 ^ (N - 2) * (N - 1)



//2 2 3 2 3 3 4
//

//34 100010


//15 32 13+12
