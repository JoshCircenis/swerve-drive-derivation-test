#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <cmath>
#include <Windows.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

using namespace std;

int main() {
	double FWD = 0;
	double STR = 0;
	double RCW = 0;

	cout << "Enter Y (forward): ";
	cin >> FWD;
	cout << endl << "Enter X1 (strafe): ";
	cin >> STR;
	cout << endl << "Enter X2 (rotation): ";
	cin >> RCW;

	double L = 10;
	double W = 10;
	double R = sqrt((L*L) + (W*W));

	double A = STR - RCW*(L / R);
	double B = STR + RCW*(L / R);
	double C = FWD - RCW*(W / R);
	double D = FWD + RCW*(W / R);

	double ws1 = sqrt((B*B) + (C*C)); 
	double wa1 = atan2(B, C)*180 / M_PI;
	double ws2 = sqrt((B*B) + (D*D)); 
	double wa2 = atan2(B, D)*180 / M_PI;
	double ws3 = sqrt((A*A) + (D*D)); 
	double wa3 = atan2(A, D)*180 / M_PI;
	double ws4 = sqrt((A*A) + (C*C)); 
	double wa4 = atan2(A, C)*180 / M_PI;

	double max = ws1; 
	if (ws2 > max)max = ws2;
	if (ws3 > max)max = ws3; 
	if (ws4 > max)max = ws4;
	if (max > 1) { ws1 /= max; ws2 /= max; ws3 /= max; ws4 /= max; }

	cout << endl;
	cout << endl;
	cout << "                     " << "2( " << ws2 << ", " << wa2 << ")" << "                     " << "1( " << ws1 << ", " << wa1 << ")" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                     " << "3( " << ws3 << ", " << wa3 << ")" << "                    " << "4( " << ws4 << ", " << wa4 << ")" << endl;
	cout << endl;
	cout << endl;

	system("pause");
	system("CLS");
	main();
}