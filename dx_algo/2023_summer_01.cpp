#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int T, N, M, C, TestCase;
// vector<int> graph[401];
int map[401][401] = {0, };
bool visited[401][401] = {0, };
vector<int> totallist;
void reset_case()
{
	for (int i = 0; i < 401; i++)
	{
		for (int j = 0; j < 401; j++)
		{
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
	totallist.clear();
}

void reset_visited()
{
	for (int i = 0; i < 401; i++)
	{
		for (int j = 0; j < 401; j++)
			visited[i][j] = false;
	}
}

int recur(int x, int start_point,int recurtotal)
{
	for (int i = 0; i < 401; i++)
		visited[i][x] = true;
	cout << "x : " << x << endl;
	for (int i = 1; i < N + 1; i++)
	{
		bool flag = 0;
		recurtotal += map[x][i];
		cout << "x: " << x << " i : " << i << " start_point: " << start_point << " recur total : " << recurtotal << endl;
		if (i == start_point && map[x][i] != 0 && flag == 1)
		{
			recurtotal += map[x][i];
			cout << "A" << endl;
			// vector<int>::iterator iter2;
			// cout << endl << endl << totallist.size() << " before totallist : ";
			// for (iter2 = totallist.begin(); iter2 != totallist.end(); iter2++)
			// 	cout << *iter2 << " ";
			// cout << endl;
			cout << "recurtotal : " << recurtotal << endl;
			totallist.push_back(recurtotal);
			recurtotal = 0;
			return (recurtotal);
			// vector<int>::iterator iter3;
			// cout << endl << endl << totallist.size() << " after totallist : ";
			// for (iter3 = totallist.begin(); iter3 != totallist.end(); iter3++)
			// 	cout << *iter3 << " ";
			// cout << endl;

			// return (recurtotal);
		}
		if (map[x][i] != 0 && (!visited[x][i]))
		{
			flag = 1;
			cout << "next : " << i << endl;
			cout << "=---- recur :" << recurtotal << " x: " << x << " i: " << i << endl;
			recur(i, start_point, recurtotal);
		}
		recurtotal = 0;
	}
	return (0);
}

int manitto(int n, int m)
{
	int total = 0;
	for (int i = 0; i < m; i++)
	{
		int from, to, cash;
		cin >> from >> to >> cash;
		// graph[a].push_back(b);
		map[from][to] = cash;
		if (from == to)
			totallist.push_back(cash);
	}
	cout << endl << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i + 1][j + 1] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
	for (int i = 1; i < n + 1; i++)
	{
		reset_visited();
		int start_point = i;
		int recurtotal = 0;
		cout << "START POINT : " << start_point << endl;
		recurtotal = recur(i, start_point, recurtotal);
		// vector<int>::iterator iter4;
		// cout << endl << endl << "--------------------------totallist : ";
		// for (iter4 = totallist.begin(); iter4 != totallist.end(); iter4++)
		// 	cout << *iter4 << " ";
		// cout << endl;
		// cout << "C :" << recurtotal << endl;
	}

	vector<int>::iterator iter;
	cout << endl << endl << "totallist : ";
	for (iter = totallist.begin(); iter != totallist.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	//그래프 탐색
	//cash 합 totallist push_back

	sort(totallist.begin(), totallist.end());
	total = totallist[0];
	return (total);
}

int main ()
{
	cin >> T;
	TestCase = T;

	while (T--)
	{
		reset_case();
		cin >> N >> M;
		cout << "AAA" << endl;
		int lowtotal = manitto(N, M);
		cout << "#" << TestCase - T << " " << lowtotal << endl;
	}

	return (0);
}


int check_friend(int x)
{
	int temp = 0;
	for (int i = 0; i < 401; i++)
		temp += map[x][i];
	return (temp);
}
