#include <iostream>
using namespace std;

int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int A[N][M], B[N][M];
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> A[i][j];
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> B[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M - 1; j++) cout << A[i][j] + B[i][j] << ' ';
		cout << A[i][M - 1] + B[i][M - 1] << '\n';
	}
	return 0;
}
