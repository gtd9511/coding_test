#include <iostream>
using namespace std;

int Rx, Ry, Bx, By, Gx, Gy;
static int cnt = 0;

void printstate (char** arr, int N, int M, int cnt)
{
	cout << "current state" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << "Rx : " << Rx << "Ry : " << Ry << endl;
	cout << "Bx : " << Bx << "By : " << By << endl;
	cout << cnt << endl;
}

int checkstate(char** arr, int Rx, int Ry, int Bx, int By, int Gx, int Gy, int cnt)
{
	if (Rx == Bx && Rx == Gx)
		return (-1);
	if (Ry == By && Ry == Gy)
		return (-1);
	if (cnt > 10)
		return (-1);
	if (Rx == Gx && Ry == Gy)
		return (-2);
	return (cnt);
}

void mv_up(char** arr, int N, int M)
{
	int curRy, curBy;
	curRy = Ry;
	curBy = By;

	for (int i = By; i > 0; i--)
	{
		if (arr[i][Bx] == '#' || arr[i][Bx] == 'R')
			break;
		// if (arr[i][Bx] == '0')
		// {
//
		// }
		By = i;
	}
	for (int i = Ry; i > 0; i--)
	{
		if (arr[i][Rx] == '#' || arr[i][Rx] == 'B')
			break;
		// if (arr[i][Rx] == '0')
			// return ;
		Ry = i;
	}
	if (Ry != curRy || By != curBy)
	{
		cnt++;
		arr[curRy][Rx] = '.';
		arr[curBy][Bx] = '.';
		arr[Ry][Rx] = 'R';
		arr[By][Bx] = 'B';
	}
}

void mv_dw(char** arr, int N, int M)
{
	int curRy, curBy;
	curRy = Ry;
	curBy = By;

	for (int i = By; i < N; i++)
	{
		if (arr[i][Bx] == '#' || arr[i][Bx] == 'R')
			break;
		By = i;
	}
	for (int i = Ry; i < N; i++)
	{
		if (arr[i][Rx] == '#' || arr[i][Rx] == 'B')
			break;
		Ry = i;
	}
	if (Ry != curRy || By != curBy)
	{
		cnt++;
		arr[curRy][Rx] = '.';
		arr[curBy][Bx] = '.';
		arr[Ry][Rx] = 'R';
		arr[By][Bx] = 'B';
	}
}

void mv_rg(char** arr, int N, int M)
{
	int curRx, curBx;
	curRx = Rx;
	curBx = Bx;

	for (int i = Bx; i < M; i++)
	{
		if (arr[By][i] == '#' || arr[By][i] == 'R')
			break;
		Bx = i;
	}
	for (int i = Rx; i < M; i++)
	{
		if (arr[Ry][i] == '#' || arr[Ry][i] == 'B')
			break;
		Rx = i;
	}
	if (Ry != curRx || By != curBx)
	{
		cnt++;
		arr[Ry][curRx] = '.';
		arr[By][curBx] = '.';
		arr[Ry][Rx] = 'R';
		arr[By][Bx] = 'B';
	}
}

void mv_lf(char** arr, int N, int M)
{
	int curRx, curBx;
	curRx = Rx;
	curBx = Bx;

	for (int i = Bx; i > 0; i--)
	{
		if (arr[By][i] == '#' || arr[By][i] == 'R')
			break;
		Bx = i;
	}
	for (int i = Rx; i > 0; i--)
	{
		if (arr[Ry][i] == '#' || arr[Ry][i] == 'B')
			break;
		Rx = i;
	}
	if (Ry != curRx || By != curBx)
	{
		cnt++;
		arr[Ry][curRx] = '.';
		arr[By][curBx] = '.';
		arr[Ry][Rx] = 'R';
		arr[By][Bx] = 'B';
	}
}


int main()
{
	int N, M;
	cin >> N >> M;
	if (N > 10 || M > 10)
		return (1);
	char** arr = new char* [N];
	for (int i = 0; i < N; i++)
		arr[i] = new char[M];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
			{
				Rx = j;
				Ry = i;
			}
			if (arr[i][j] == 'B')
			{
				Bx = j;
				By = i;
			}
			if (arr[i][j] == '0')
			{
				Gx = j;
				Gy = i;
			}
		}
	}
//	while (1)
//	{
		//int curcnt = cnt;

		mv_up(arr, N, M);
		mv_dw(arr, N, M);
		mv_rg(arr, N, M);
		mv_lf(arr, N, M);
		printstate(arr, N, M, cnt);
		checkstate(arr, Rx, Ry, Bx, By, Gx, Gy, cnt);
//	}
	return (0);
}



//0 R B 같은 선상에 있는 경우 x
