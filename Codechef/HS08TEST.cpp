#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int x;
	double y;
	cin >> x >> y;
	if ( x%5==0 && (x+0.5)<=y )
		y = y-x-0.5;
	cout << fixed << setprecision(2) << y << endl;
	return 0;
}
