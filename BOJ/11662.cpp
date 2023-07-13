#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
double cur_Mx, cur_My, cur_Gx, cur_Gy;
double min_dist = 150000;

double dist(double x1, double y1, double x2, double y2)
{
	if (x1 == x2 && y1 == y2)
		return (0);
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main()
{
	double a, b, c, d;
	cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;
	double Mdist = dist(Ax, Ay, Cx, Cy);
	double Gdist = dist(Bx, By, Dx, Dy);

	for (double time = 0; time <= 1.0; time += 0.0000001)
	{
		// cout << time << " Ax : " << Ax << "Ay : " << Ay << " Bx : " << Bx << " By : " << By << " Cx : " << Cx << " Cy : " << Cy << " Dx : " << Dx << " Dy : " << Dy <<endl;
		cur_Mx = (Bx - Ax) * time + Ax;
		cur_My = (By - Ay) * time + Ay;

		cur_Gx = (Dx - Cx) * time + Cx;
		cur_Gy = (Dy - Cy) * time + Cy;

		// cout << time << " " << "cur_Mx : " << cur_Mx << " cur_My : " << cur_My << " cur_Gx : " << cur_Gx << " cur_Gy : " << cur_Gy << " dist : " << dist(cur_Mx, cur_My, cur_Gx, cur_Gy);
		double cur_dist = dist(cur_Mx, cur_My, cur_Gx, cur_Gy);
		if (cur_dist < 0.000001)
			cur_dist = 0;
		if (min_dist > cur_dist)
			min_dist = cur_dist;
	}
	cout.setf(ios::fixed);
	cout.precision(10);
	cout << min_dist << endl;
	return (0);
}
