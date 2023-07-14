#include <iostream>
// #include <vector>
#include <deque>
// #include <algorithm>
// #include <bitset>
using namespace std;

int T, N;

// int a = 50000;
// vector<int> v(a);

// string toInt(const string& binaryString)
// {
// 	bitset<30> set(binaryString);
// 	return to_string(set.to_ulong());
// }

// string toBinary(int num)
// {
// 	bitset<30> toBinary(num);
// 	return toBinary.to_string();
// }
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
		// cout << "&&&" << endl;
		// std::vector<int>::iterator iter;
		// for(iter = v.begin(); iter!= v.end(); iter++)
		// 	v.erase(iter);
		first = 0;
		second = 0;
		// cout << "input N" << endl;
		cin >> N;
		// vector<int> v(N / 2 - 0.5);
		// deque<int> v(N/2 - 0.5);
		deque<int> v(0);

		// cout << v.size() << endl;
		for (int j = 0; j < N; j++)
		{
			// cout << "input temp [" << j + 1 << "]" << endl;
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		// std::vector<int>::iterator iter;
		// cout << "VECTOR SIZE : " << v.size() << " VECTOR :";
		// for(iter = v.begin(); iter!= v.end(); iter++)
		// 	std::cout << " " <<*iter;
		// cout << endl;
		// cout << "v[0] : " << v.front() << endl;
		// cout << "v[end] : " << v.back() << endl;

		// deque<int>::iterator iter;
		// cout << "DEQUE SIZE : " << v.size() << " DEQUE :";
		// for (iter = v.begin(); iter != v.end(); iter++)
		// 	std::cout << " " << *iter;
		// cout << endl;
		for (int j = 0; j < N; j++)
		{
			if (j % 2 == 0)
			{
				// cout << "1" << endl;
				int first_front = first ^ v.front();
				int first_back = first ^ v.back();
				// cout << "case first : " << first << " v.front : " << v.front() << " v.back : " << v.back()<< endl << "front : " << first_front << " back : " << first_back << endl;
				if (first_front > first_back)
				{
					// cout << "A" << endl;
					first = first_front;
					// v.erase(v.begin());
					v.pop_front();
					// cout << "A : " << first << endl;
				}
				else if (first_front == first_back)
				{
					// if ((second ^ v.front()) > (second ^ v.back()))
					// {
					// 	first = first_front;
					// 	v.pop_front();
					// }
					// else
					// {
					// 	first = first_back;
					// 	v.pop_back();
					// }
				}
				else
				{
					// cout << "B" << endl;
					first = first_back;
					v.pop_back();
				}
			}

			if (j % 2 == 1)
			{
				// cout << "2" << endl;
				int second_front = second ^ v.front();
				int second_back = second ^ v.back();
				// cout << "case second : " << first << " front : " << second_front << " back : " << second_back << endl;

				if (second_front > second_back)
				{
					second = second_front;
					// v.erase(v.begin());
					v.pop_front();
				}
				else if (second_front == second_back)
				{
					if ((first ^ v.front()) > (first ^ v.back()))
					{
						second = second_front;
						v.pop_front();
					}
					else
					{
						second = second_back;
						v.pop_back();
					}
				}
				else
				{
					second = second_back;
					v.pop_back();
				}
			}
		}
		// cout << "first : " << first << " second : " << second << endl;
		if (first > second)
			cout << "First" << endl;
		else if (first == second)
			cout << "Draw" << endl;
		else
			cout << "Second" << endl;
		// cout <<"^^^" << endl;
		// if (i == T - 1)
		// {
		// 	cout << "break" << endl;
		// 	break;
		// }
		v.clear();
		// vector<int>().swap(v);
	}
	return (0);
}
