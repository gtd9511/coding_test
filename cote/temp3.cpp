#include <iostream>
#include <tuple>
#include <queue>
#include <climits>

#define MAX_N 15
#define MAX_M 30
#define DIR_NUM 4
#define EMPTY make_pair(-1, -1)

using namespace std;

int n, m;

int grid[MAX_N][MAX_N];

pair<int, int> cvs_list[MAX_M];

pair<int, int> people[MAX_M];

int curr_t;

int dx[DIR_NUM] = {-1,  0, 0, 1};
int dy[DIR_NUM] = { 0, -1, 1, 0};

int step[MAX_N][MAX_N];      // 최단거리 결과 기록
bool visited[MAX_N][MAX_N];  // 방문 여부 표시

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
    return InRange(x, y) &&       // 범위를 벗어나지 않으면서
           !visited[x][y] &&      // 방문했던 적이 없으면서
           grid[x][y] != 2;       // 이동 가능한 곳이어야 합니다.
}

void BFS(pair<int, int> start_pos) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            visited[i][j] = false;
            step[i][j] = 0;
        }

    queue<pair<int, int> > q;
    int sx = start_pos.first, sy = start_pos.second;
    q.push(start_pos);
    visited[sx][sy] = true;
    step[sx][sy] = 0;

    while(!q.empty()) {
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first, y = curr_pos.second;
        for(int i = 0; i < DIR_NUM; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(CanGo(nx, ny)) {
                visited[nx][ny] = true;
                step[nx][ny] = step[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void Simulate() {
    for(int i = 0; i < m; i++) {
        if(people[i] == EMPTY || people[i] == cvs_list[i])
            continue;

        BFS(cvs_list[i]);

        int px, py;
        tie(px, py) = people[i];
        int min_dist = INT_MAX;
        int min_x = -1, min_y = -1;
        for(int j = 0; j < DIR_NUM; j++) {
            int nx = px + dx[j], ny = py + dy[j];
            if(InRange(nx, ny) && visited[nx][ny] && min_dist > step[nx][ny]) {
                min_dist = step[nx][ny];
                min_x = nx; min_y = ny;
            }
        }

        people[i] = make_pair(min_x, min_y);
    }

    for(int i = 0; i < m; i++) {
        if(people[i] == cvs_list[i]) {
            int px, py;
            tie(px, py) = people[i];
            grid[px][py] = 2;
        }
    }


    if(curr_t > m)
        return;

    BFS(cvs_list[curr_t - 1]);

    int min_dist = INT_MAX;
    int min_x = -1, min_y = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] && grid[i][j] == 1 && min_dist > step[i][j]) {
                min_dist = step[i][j];
                min_x = i; min_y = j;
            }
        }
    }

    people[curr_t - 1] = make_pair(min_x, min_y);
    grid[min_x][min_y] = 2;
}

bool End() {
    for(int i = 0; i < m; i++) {
        if(people[i] != cvs_list[i])
            return false;
    }

    return true;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        cvs_list[i] = make_pair(x - 1, y - 1);
    }

    for(int i = 0; i < m; i++)
        people[i] = EMPTY;

    while(true) {
        curr_t++;
        Simulate();
        if(End()) break;
    }

    cout << curr_t;
    return 0;
}
