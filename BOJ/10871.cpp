#include <iostream>
using namespace std;

int N, X;
int A[10000];

int main() {
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (A[i] < X) cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
