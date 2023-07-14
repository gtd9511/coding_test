#include <iostream>
#include <deque>
#include <bitset>
using namespace std;

int T, N;

// string toInt(const string& binaryString)
// {
// 	bitset<30> set(binaryString);
// 	return to_string(set.to_ulong());
// }

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
		// 1
		// 홀수
		// (0 0 | 0 1 | 1 0 | 1 1)
		// 1짝 1짝  1짝 0짝 0짝 1짝 0짝 0짝
		// s  s   s      s
		// 1 (0 0 > 0 | 0 1 > 0 | 1 0 > 0)
		// 짝수
		// 10 10 > 0
		// 101 101 101 > 1
		// 0홀
		// 0 ()
		// 짝수

		// 10 10 10 10 10		10 10 10 10 first
		// 10 10 10 			10 10		second

		// 10

		// 1홀  - 1짝 - second
		// 	-0짝 (first 1)~~~
		// 1짝 - first
		// 0홀 - draw
		// 0짝 - draw
		// deque<int>::iterator iter;
		// cout << "DEQUE SIZE : " << v.size() << " DEQUE :";
		// for (iter = v.begin(); iter != v.end(); iter++)
		// 	std::cout << " " << *iter;
		// cout << endl;
		// for (int j = 0; j < N; j++)
		// {
		// 	if (j % 2 == 0)
		// 	{
		// 		// cout << "1" << endl;
		// 		int first_front = first ^ v.front();
		// 		int first_back = first ^ v.back();
		// 		// cout << "case first : " << first << " v.front : " << v.front() << " v.back : " << v.back()<< endl << "front : " << first_front << " back : " << first_back << endl;
		// 		if (first_front > first_back)
		// 		{
		// 			first = first_front;
		// 			v.pop_front();
		// 			// cout << "A : " << first << endl;
		// 		}
		// 		else if (first_front == first_back)
		// 		{
		// 			if ((second ^ v.front()) > (second ^ v.back()))
		// 			{
		// 				first = first_front;
		// 				v.pop_front();
		// 			}
		// 			else
		// 			{
		// 				first = first_back;
		// 				v.pop_back();
		// 			}
		// 		}
		// 		else
		// 		{
		// 			// cout << "B" << endl;
		// 			first = first_back;
		// 			v.pop_back();
		// 		}
		// 	}

		// 	if (j % 2 == 1)
		// 	{
		// 		// cout << "2" << endl;
		// 		int second_front = second ^ v.front();
		// 		int second_back = second ^ v.back();
		// 		// cout << "case second : " << first << " front : " << second_front << " back : " << second_back << endl;

		// 		if (second_front > second_back)
		// 		{
		// 			second = second_front;
		// 			v.pop_front();
		// 		}
		// 		else if (second_front == second_back)
		// 		{
		// 			if ((first ^ v.front()) > (first ^ v.back()))
		// 			{
		// 				second = second_front;
		// 				v.pop_front();
		// 			}
		// 			else
		// 			{
		// 				second = second_back;
		// 				v.pop_back();
		// 			}
		// 		}
		// 		else
		// 		{
		// 			second = second_back;
		// 			v.pop_back();
		// 		}
		// 	}
		// }
		// // cout << "first : " << first << " second : " << second << endl;
		// if (first > second)
		// 	cout << "First" << endl;
		// else if (first == second)
		// 	cout << "Draw" << endl;
		// else
		// 	cout << "Second" << endl;
		// v.clear();
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
