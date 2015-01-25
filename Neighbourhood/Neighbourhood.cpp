#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool isEqualTo360(int x, int y, int *neighX, int *neighY,int size)
{
	double *angle = new double[size];
	double angleSum = 0;

	for (int i = 0; i < size; i++)
	{
		//vector a
		int aX = x - neighX[i];
		int aY = y - neighY[i];

		//vector b
		int bX;
		int bY;
		if (i != size - 1)
		{
			bX = x - neighX[i + 1];
			bY = y - neighY[i + 1];
		}
		else
		{
			bX = x - neighX[0];
			bY = y - neighY[0];
		}

		//cout << aX << " " << aY << endl;
		//cout << bX << " " << bY << endl;

		//cos = a¡¤b/(|a|*|b|)
		int powerab = aX*bX+aY*bY;
		double aValue = sqrt(aX*aX + aY*aY);
		double bValue = sqrt(bX*bX + bY*bY);
		double cosab = powerab / (aValue*bValue);

		//cout << "powerab " << powerab << endl;
		//cout << "aValue " << aValue << endl;
		//cout << "bValue " << bValue << endl;
		//cout << "cosab " << cosab << endl;

		//arccos
		double acosab = acos(cosab);
		//cout << "acosab " << acosab<<endl;
		angleSum += acosab;
	}

	//cout << "angleSum " << angleSum << endl;

	//2¦Ð = 6.28319 = 360 
	if (fabs(angleSum - 6.28319) < 0.001)
		return true;
	else
		return false;
}

int str2int(string s)
{
	int result = 0;

	for (int i = 0; i < s.size(); i++)
	{
		int a = s[i] - '0';
		for (int j = i; j < s.size() - 1; j++)
			a *= 10;

		result += a;
	}

	return result;
}

void count_trips(const vector<string> &neighbourhood, const vector<string> &trips)
{
	int cnt_trips_in_neighbourhood = 0;

	//get neighbourhood X and Y
	int *neighX = new int[neighbourhood.size()];
	int *neighY = new int[neighbourhood.size()];

	for (int i = 0; i < neighbourhood.size(); i++)
	{
		//get coordinates of each neighbourhood
		int commaIndex = neighbourhood[i].find(",");
		int x = str2int(neighbourhood[i].substr(0, commaIndex));
		int y = str2int(neighbourhood[i].substr(commaIndex + 1, neighbourhood[i].size() - commaIndex - 1));
		neighX[i] = x;
		neighY[i] = y;
	}

	//iterate for every string in trips
	for (int i = 0; i < trips.size();i++)
	{
		//get coordinates of each trip
		int commaIndex = trips[i].find(",");
		int x = str2int(trips[i].substr(0,commaIndex));
		int y = str2int(trips[i].substr(commaIndex+1,trips[i].size()-commaIndex-1));

		if (isEqualTo360(x, y, neighX, neighY, neighbourhood.size()))
			cnt_trips_in_neighbourhood++;
	}

	cout << cnt_trips_in_neighbourhood<<endl;
}

int main()
{
	vector<string> neighbourhood;
	neighbourhood.push_back("1,3");
	neighbourhood.push_back("4,5");
	neighbourhood.push_back("3,1");

	vector<string> trips;
	trips.push_back("1,1");
	trips.push_back("2,3");
	trips.push_back("3,3");
	trips.push_back("4,2");

	count_trips(neighbourhood,trips);

	return 0;
}
