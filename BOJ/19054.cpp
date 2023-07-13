#include <iostream>
#include <vector>
#include <algorithm>
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
	vector<int> v;

	cin >> T;
	int first;
	int second;
	for (int time = 0; time < T; time++)
	{
		cout << "&&&" << endl;
		v.clear();
		// std::vector<int>::iterator iter;
		// for(iter = v.begin(); iter!= v.end(); iter++)
		// 	v.erase(iter);
		first = 0;
		second = 0;
		cout << "input N" << endl;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cout << "input temp [" << j + 1 << "]" << endl;
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		// std::vector<int>::iterator iter;
		// // cout << "VECTOR :";
		// for(iter = v.begin(); iter!= v.end(); iter++)
		// 	std::cout << " " <<*iter;
		for (int j = 0; j < N; j++)
		{
			if (j / 2 == 0)
			{
				cout << "first : " << first << " " << v.front() << endl;
				int first_front = first ^ v.front();
				int first_back = first ^ v.back();
				if (first_front > first_back)
				{
					first = first_front;
					v.erase(v.begin());
					cout << "A : " << first << endl;
				}
				else
				{
					first = first_back;
					v.pop_back();
				}
			}

			if (j / 2 == 0)
			{
				int second_front = second ^ v.front();
				int second_back = second ^ v.back();
				if (second_front > second_back)
				{
					second = second_front;
					v.erase(v.begin());
				}
				else
				{
					second = second_back;
					v.pop_back();
				}
			}
		}
		cout << "first : " << first << " second : " << second << endl;
		if (first > second)
			cout << "First" << endl;
		else if (first == second)
			cout << "Draw" << endl;
		else
			cout << "Second" << endl;
		cout <<"^^^" << endl;
	}
	return (0);
}
