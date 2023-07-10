#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int T, N, M, TestCase;

int map[401][401] = {0,};
int tempmap[401][401] = {0, };
bool visited[401][401] = {0, };
int flag[401] = {0, };
int total;

// vector<int> totallist;

// void print_vector(vector<int> vec)
// {
// 	vector<int>::iterator iter;
// 	cout << "totallist : ";
// 	for (iter =  vec.begin(); iter !=  vec.end(); iter++)
// 		cout << *iter << " ";
// 	cout << endl;
// }

void print_map()
{
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void solo(int x)
{
	for (int i = 1; i < N + 1; i++)
	{
		map[x][i] = 0;
		map[i][x] = 0;
	}
}

int cnt_receive(int x)
{
	int cnt = 0;
	for (int i = 1; i < N + 1; i++)
	{
		if (map[i][x] != 0)
			cnt++;
	}
	return (cnt);
}

int cnt_give(int x)
{
	int cnt = 0;
	for (int i = 1; i < N + 1; i++)
	{
		if (map[x][i] != 0)
			cnt++;
	}
	return (cnt);
}

void reset_case()
{
	for (int i = 1; i < 401; i++)
	{
		for (int j = 1; j < 401; j++)
		{
			map[i][j] = 0;
			tempmap[i][j] = 0;
			visited[i][j] = false;
		}
	}
	// totallist.clear();
}

void reset_visited()
{
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
			visited[i][j] = false;
	}
}

void recur(int cur_point, int start_point, int cost)
{
	int res_cost = cost;
	for (int i = 1; i < N + 1; i++)
		visited[i][cur_point] = true;
	//
	// cout << "|current point : " << cur_point << " start_point : " << start_point << " res_cost : " << res_cost << endl;
	for (int next_point = 1; next_point < N + 1; next_point++)
	{
		if (flag[next_point] == 0 && map[cur_point][next_point] != 0)
		{
			if (next_point == start_point)
			{
				res_cost += map[cur_point][next_point];
				//
				// cout << "|********End Cycle // cost : " << res_cost << endl;
				// totallist.push_back(res_cost);
				if (total > res_cost)
					total = res_cost;
				flag[next_point] = 1;
			}
			if (!visited[cur_point][next_point])
			{
				//
				// cout << "|next point : " << next_point << " plus : " << map[cur_point][next_point] << endl;
				res_cost += map[cur_point][next_point];
				if (res_cost < total)
					recur(next_point, start_point, res_cost);
			}
		}
		res_cost = cost;
	}
}

int manito(int n, int m)
{
	total = 2147483647;
	for (int i = 0; i < m; i++)
	{
		int from, to, cash;
		cin >> from >> to >> cash;
		map[from][to] = cash;
		tempmap[from][to] = cash;
		if (from == to)
		{
			map[from][to] = 0;
			tempmap[from][to] = 0;
			//
			// cout << "|********SAME CASE : " << cash << endl;
			// totallist.push_back(cash);
			if (total > cash)
				total = cash;
		}
	}
	// print_map();
	for (int i = 1; i < n + 1; i++)
	{
		// cout << "i :" << i << " rec : " << cnt_receive(i) << " giv : " << cnt_give(i) << endl;
		if (cnt_receive(i) * cnt_give(i) == 0)
			solo(i);
	}
	// print_map();
	for (int i = 1; i < n + 1; i++)
	{
		reset_visited();
		flag[i] = 0;
		int start_point = i;
		for (int j = 1; j < n + 1; j++)
		{
			// copy(&map[0][0], &map[0][0] + 401 * 401, &tempmap[0][0]);
			if (map[i][j] * map[j][i] > 0)
			{
				//
				// cout << "|********EACH CASE : " << map[i][j] + map[j][i] << endl;
				// totallist.push_back(map[i][j] + map[j][i]);
				if (total > map[i][j] + map[j][i])
					total = map[i][j] + map[j][i];
				map[i][j] = 0;
				map[j][i] = 0;
			}
		}
		recur(i, start_point, 0);
		// copy(&tempmap[0][0], &tempmap[0][0] + 401 * 401, &map[0][0]);
	}
	// sort(totallist.begin(), totallist.end());
	// if (!totallist.empty())
	// 	total = totallist[0];
	// else
	if (total == 2147483647)
		total = -1;
	return (total);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		reset_case();
		cin >> N >> M;
		int ans = manito(N, M);
		cout << "#" << i << " " << ans << endl;
	}

	return (0);
}
