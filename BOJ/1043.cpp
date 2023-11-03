#include <iostream>
#include <vector>
using namespace std;

int N, M, T, ans = 0;
bool people[51] = {0, };

int main()
{
	cin >> N >> M >> T;
	for (int i = 0; i < T; i++)
	{
		int temp;
		cin >> temp;
		people[temp] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		int num;
		bool flag = 1;
		cin >> num;
		vector<int> v;

		for (int j = 0; j < num; j++)
		{
			int man;
			cin >> man;
			v.push_back(man);
			if (people[man] == 1)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			ans++;
		else
		{
			for (int j = 0; j < v.size(); j++)
				people[v[j]] = 1;
		}
	}
	cout << ans;
	return (0);
}


// 2 1 5	x
// 2 2 6	x
// 1 7		o
// 1 8		o
// 2 7 8	o
// 1 9		o
// 1 10		o	x
// 2 3 10	x
// 1 4		x
// https://seokjin2.tistory.com/44

