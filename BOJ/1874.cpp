#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	stack<int> s;
	vector<int> v;
	int n, flag = 0, idx = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (s.empty())
		{
			s.push(idx);
			// cout << "push [" << idx << "]" << endl;
			v.push_back(1);
			idx++;
		}
		while (s.top() != temp)
		{
			s.push(idx);
			// cout << "push [" << idx << "]" << endl;
			v.push_back(1);
			idx++;
			if (idx > n)
				break;
		}
		if (s.top() == temp)
		{
			s.pop();
			// cout << "pop [" << idx << "]" << endl;
			v.push_back(2);
			flag++;
		}

	}
	if (flag == n)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] == 1)
				cout << "+\n";
			else if (v[i] == 2)
				cout << "-\n";
		}
	}
	else
		cout << "NO";
	return (0);
}

// 1 2 3 4
//4 3 6 8 7 5 2 1

// 4 3 6 8

//1 2 3 4 5 6 7 8

//1 2 5 7 8
//4 3 6 8 7 5 2 1

// 3 4 5
// 1 2
