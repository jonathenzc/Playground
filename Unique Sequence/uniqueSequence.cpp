#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	vector<int> numbers;
	
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(3);
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(6);
	numbers.push_back(9);
	numbers.push_back(5);
	numbers.push_back(7);
	numbers.push_back(7);

	int start = 0;
	int length = 1;
	int max = 1;
	
	map<int, int> m;
	m[numbers[0]] = 0;

	for (int i = 1; i < numbers.size(); i++)
	{
		if (m.find(numbers[i]) == m.end())
			m[numbers[i]] = i;
		else
		{
			//clear numbers before start 
			//If you just clear the map you will skip the information eg:12123
			if (start>m[numbers[i]])
				m[numbers[i]] = i;
			else
			{
				length = i - start;
				start = m[numbers[i]] + 1;

				if (length >= max)
					max = length;

				m[numbers[i]] = i;
			}
		}
	}

	length = numbers.size() - start;
	if (length > max)
		max = length;

	cout << max;

	return 0;
}