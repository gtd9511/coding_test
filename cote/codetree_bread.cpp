#include <iostream>
#include <queue>

using namespace std;

int N, M;

int map[15][15];

pair<int, int> cs[30];

pair<int, int> man[30];

int cur_time;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int step[15][15];
bool visited[15][15];

bool InBound(int x, int y)
{
	return (0 <= x && x < N && 0 <= y && y < N);
}

bool ispossible(int x, int y)
{
	return (InBound(x, y) && !visited[x][y] && map[x][y] != 2);
}

void BFS(pair<int, int> start_pos)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = false;
			step[i][j] = 0;
		}
	}

	queue<pair<int, int> > myqueue;
	int sx = start_pos.first;
	int sy = start_pos.second;
	myqueue.push(start_pos);
	visited[sx][sy] = true;
	step[sx][sy] = 0;

	while (!myqueue.empty())
	{
		pair<int, int> curr_pos = myqueue.front();
		myqueue.pop();

		int x = curr_pos.first;
		int y = curr_pos.second;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (ispossible(nx, ny))
			{
				visited[nx][ny] = true;
				step[nx][ny] = step[x][y] + 1;
				myqueue.push(make_pair(nx, ny));
			}
		}
	}
}

void simulate()
{
	for (int i = 0; i < M; i++)
	{
		if (man[i] == make_pair(-1, -1) || man[i] == cs[i])
			continue;
		BFS(cs[i]);

		int px, py;
		px = man[i].first;
		py = man[i].second;

		int min_dist = N * N;
		int min_x = -1;
		int min_y = -1;
		for (int j = 0; j < 4; j++)
		{
			int nx = px + dx[j];
			int ny = py + dy[j];
			if (InBound(nx, ny) && visited[nx][ny] && min_dist > step[nx][ny])
			{
				min_dist = step[nx][ny];
				min_x = nx;
				min_y = ny;
			}
		}
		man[i] = make_pair(min_x, min_y);
	}

	for (int i = 0; i < M; i++)
	{
		if (man[i] == cs[i])
		{
			int px, py;
			px = man[i].first;
			py = man[i].second;
			map[px][py] = 2;
		}
	}

	if (cur_time > M)
		return ;

	BFS(cs[cur_time - 1]);

	int min_dist = N * N;
	int min_x = -1;
	int min_y = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] && map[i][j] == 1 && min_dist > step[i][j])
			{
				min_dist = step[i][j];
				min_x = i;
				min_y = j;
			}
		}
	}

	man[cur_time - 1] = make_pair(min_x, min_y);
	map[min_x][min_y] = 2;
}

/*
void simulate() {
    // Step 1. 격자에 있는 사람들에 한하여 편의점 방향을 향해 1칸 움직입니다.
    for(int i = 0; i < M; i++) {
        // 아직 격자 밖에 있는 사람이거나 이미 편의점에 도착한 사람이라면 패스합니다.
        if(man[i] == make_pair(-1, -1) || man[i] == cs[i])
            continue;

        // 원래는 현재 위치에서 편의점 위치까지의 최단거리를 구해줘야 합니다.
        // 다만 최단거리가 되기 위한 그 다음 위치를 구하기 위해서는
        // 거꾸로 편의점 위치를 시작으로 현재 위치까지 오는 최단거리를 구해주는 것이 필요합니다.
        // 따라서 편의점 위치를 시작으로 하는 BFS를 진행합니다.
        BFS(cs[i]);

        int px, py;
		px = man[i].first;
		py = man[i].second;
        //tie(px, py) = man[i];
        // 현재 위치에서 상좌우하 중 최단거리 값이 가장 작은 곳을 고르면
        // 그 곳으로 이동하는 것이 최단거리 대로 이동하는 것이 됩니다.
        // 그러한 위치 중 상좌우하 우선순위대로 가장 적절한 곳을 골라줍니다.
        int min_dist = INT_MAX;
        int min_x = -1, min_y = -1;
        for(int j = 0; j < 4; j++) {
            int nx = px + dx[j], ny = py + dy[j];
            if(InBound(nx, ny) && visited[nx][ny] && min_dist > step[nx][ny]) {
                min_dist = step[nx][ny];
                min_x = nx; min_y = ny;
            }
        }

        // 우선순위가 가장 높은 위치로 한 칸 움직여줍니다.
        man[i] = make_pair(min_x, min_y);
    }

    // Step 2. 편의점에 도착한 사람에 한하여
    //         앞으로 이동 불가능하다는 표시로
    //         grid값을 2로 바꿔줍니다.
    for(int i = 0; i < M; i++) {
        if(man[i] == cs[i]) {
            int px, py;
            //tie(px, py) = man[i];
			px = man[i].first;
			py = man[i].second;
            map[px][py] = 2;
        }
    }

    // Step 3. 현재 시간 curr_t에 대해 curr_t ≤ m를 만족한다면
    //         t번 사람이 베이스 캠프로 이동합니다.

    // curr_t가 m보다 크다면 패스합니다.
    if(cur_time > M)
        return;

    // Step 3-1. 편의점으로부터 가장 가까운 베이스 캠프를 고르기 위해
    //           편의점을 시작으로 하는 BFS를 진행합니다.
    BFS(cs[cur_time - 1]);

    // Step 3-2. 편의점에서 가장 가까운 베이스 캠프를 선택합니다.
    //           i, j가 증가하는 순으로 돌리기 때문에
    //           가장 가까운 베이스 캠프가 여러 가지여도
    //           알아서 (행, 열) 우선순위대로 골라집니다.
    int min_dist = INT_MAX;
    int min_x = -1, min_y = -1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            // 방문 가능한 베이스 캠프 중
            // 거리가 가장 가까운 위치를 찾아줍니다.
            if(visited[i][j] && map[i][j] == 1 && min_dist > step[i][j]) {
                min_dist = step[i][j];
                min_x = i; min_y = j;
            }
        }
    }

    // 우선순위가 가장 높은 베이스 캠프로 이동합니다.
    man[cur_time - 1] = make_pair(min_x, min_y);
    // 해당 베이스 캠프는 앞으로 이동이 불가능한 칸임을 표시합니다.
    map[min_x][min_y] = 2;
}
*/
bool End()
{
	for (int i = 0; i < M; i++)
	{
		if (man[i] != cs[i])
			return (false);
	}
	return (true);
}

int main(void)
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		cs[i] = make_pair(x - 1, y - 1);
	}
	for (int i = 0; i < M; i++)
		man[i] = make_pair(-1, -1);
	while(1)
	{
		cur_time++;

		simulate();

		if (End())
			break;
	}

	cout << cur_time << endl;
	return (0);
}
