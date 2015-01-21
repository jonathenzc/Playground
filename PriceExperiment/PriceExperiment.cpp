#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

void uber_price(int a, int b) 
{
	double delta = a*a + 12 * b;
	double twoA = 2 * a;
	double root_Delta = sqrt(delta);

	double x = (twoA-root_Delta)/12.0;
	
	string s;
	stringstream ss;
	ss << x;
	ss >> s;
	
	int pointIndex = s.find(".");

	cout << s.substr(0,pointIndex+3);
}

int main()
{
	uber_price(250,400);

	return 0; 
}