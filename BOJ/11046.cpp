#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

bool is_palin(vector<int> &sample)
{
	bool flag = true;
	// for (int i = 0; i < sample.size(); i++)
	// 	cout << sample[i] << " ";
	// cout << endl;
	for(int i = 0; i < sample.size(); i++)
	{
		// cout << "v[i] : " << v[i] << endl;
		// cout << "v[e] : " << v[v.size() - 1 - i] << endl;
		if (sample[i] != sample[sample.size() - 1 - i])
		{
			flag = false;
			// cout << "AAAAAAAAAAAA\n";
			break;
		}
	}
	return flag;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		vector<int> temp;
		for (int i = S - 1; i < E; i++)
			temp.push_back(v[i]);
		// for (int i = 0; i < temp.size(); i++)
		// 	cout << temp[i] << " ";
		// cout << endl;
		if (is_palin(temp))
			cout << "1\n";
		else
			cout << "0\n";
	}
	return (0);
}
