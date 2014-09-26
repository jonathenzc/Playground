#include <iostream>
#include <vector>

using namespace std;

int biggerThan(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int smallerThan(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	vector<int> heights;
	heights.push_back(9);
	heights.push_back(8);
	heights.push_back(7);
	heights.push_back(8);
	heights.push_back(9);
	heights.push_back(5);
	heights.push_back(6);

	int heightSize = heights.size();
	int *leftHighest = new int[heightSize]; //record for biggest height on the left side of heights[i]
	int *rightHighest = new int[heightSize]; //record for biggest height on the right side of heights[i]

	leftHighest[0] = 0;
	rightHighest[heightSize - 1] = 0;

	for (int i = 1; i < heightSize - 1; i++)
	{
		//using dynamic program
		//left[i] = max(left[i-1],heights[i-1])
		//right[i] = max(right[i+1],heights[i+1])
		leftHighest[i] = biggerThan(leftHighest[i-1],heights[i-1]);
		rightHighest[heightSize - 1 - i] = biggerThan(rightHighest[heightSize-i],heights[heightSize-i]);
	}

	int volume = 0;
	for (int i = 1; i < heightSize - 1; i++)
	{
		int smallerHeight = smallerThan(leftHighest[i],rightHighest[i]);
		int diff = smallerHeight - heights[i];
		if ( diff > 0)
			volume += diff;
	}

	cout << volume;

	return 0;
}