#include <iostream>
#include <deque>
#include <bitset>
using namespace std;

int T, N;

string toBinary(int num)
{
	bitset<30> toBinary(num);
	return toBinary.to_string();
}

int count_1(int num)
{
	int count = 0;
	string binary = toBinary(num);
	for (int i = 0; i < binary.length(); i++)
	{
		if (binary[i] == '1')
			count++;
	}
	return (count);
}

// int xor_sum(int a, int b)
// {
// 	return (toInt(toBinary(a) ^ toBinary(b)));
// }

int main()
{

	cin >> T;
	int first;
	int second;
	for (int i = 0; i < T; i++)
	{
		first = 0;
		second = 0;
		cin >> N;
		deque<int> v(0);
		int is0 = 0;
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
			is0 ^= temp;
		}
		// cout << "is0 : " << is0 << endl;

		if (is0 == 0)
		{
			cout << "Draw" << endl;
			continue;
		}
		if (N == 1)
		{
			cout << "First" << endl;
			continue;
		}

		if (N % 2 == 0)
		{
			cout << "First" << endl;
			continue;
		}

		int msb = 0;
		for (int j= ; j <31)
		else
		{
			if (N % 2 == 0)
			{
				cout << "First" << endl;
				continue;
			}
			else
			{
				if((count_1(v.front())) % 2 == 0 && (count_1(v.back())) % 2 == 0)
				{
					cout << "Second" << endl;
					continue;
				}
				else
				{
					if (((count_1(v.front())) % 2 == 1) && ((count_1(v.back())) % 2 == 0) )
						v.pop_front();
					else/* if (((count_1(v.front())) % 2 == 0) && ((count_1(v.back())) % 2 == 1))*/
						v.pop_back();

					int total = 0;
					for (int i = 0; i < N - 1; i++)
						total += (count_1(v[i]) % 2);
					// is0--;
					// cout << "is0 : " << is0 << endl;
					if (total % 4 == 0)
					{
						cout << "First" << endl;
						continue;
					}
					else
					{
						cout << "Second" << endl;
						continue;
					}
				}
			}
		}
	}
	return (0);
}

// 10 10 10
// 10 10
// 10
// 0 1

// 0 0
// 10 10 10 10 10
// 10 10

// 10 10
// 10 10 10
// 10 10

// 0 0
// 10
// 10

// 1 0

// 10 10 10
// 10 10
// 22
// 10 10 10 10 10
// 10 10 10 10
// 44
