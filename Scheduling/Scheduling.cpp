#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int findPos(int *arr,int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i]>target)
		{
			if (i == 0)
				return 0;
			else
				return i - 1;
		}
	}
}

struct requestPair
{
	int startTime;
	int endTime;
};

bool compare(requestPair x, requestPair y)
{
	return x.endTime < y.endTime;
}

int main()
{
	vector<int> req_start;
	vector<int> req_end;

	req_start.push_back(4);
	req_start.push_back(1);
	req_start.push_back(5);
	req_start.push_back(6);

	req_end.push_back(5);
	req_end.push_back(4);
	req_end.push_back(7);
	req_end.push_back(8);

	//map is not a data structure on our demand because if we set end as a key, it will ignore the requests which the end time are the same but start time is different.
	//so we choose end and start as the key
	vector<requestPair> v;
	
	for (int i = 0; i < req_start.size(); i++)
	{
		requestPair r;
		r.endTime = req_end[i];
		r.startTime = req_start[i];

		v.push_back(r);
	}

	sort(v.begin(),v.end(),compare);

	//get sorted request end arry
	int *sortedEndArr = new int[req_start.size()+1];
	int endArrIndex = 0;

	for (int i=0; i<v.size(); i++)
		sortedEndArr[endArrIndex++] = v[i].endTime;

	unordered_map<int, int> max_req;
	int maxRequest=0;

	//max_req[sortedEndArr[0]] = 0;

	for (int i=0; i < v.size(); i++)
	{
		int pos = findPos(sortedEndArr, req_start.size(), v[i].startTime);
		if (maxRequest <= max_req[sortedEndArr[pos]] + 1)
			max_req[v[i].endTime] = max_req[sortedEndArr[pos]] + 1;
		else
			max_req[v[i].endTime] = maxRequest;

		maxRequest = max_req[v[i].endTime];
	}

	//unordered_map<int, int>::iterator iter;
	//for (iter = max_req.begin(); iter != max_req.end(); iter++)
	//	cout << iter->first<<" "<<iter->second<<endl;

	cout << maxRequest;

	return 0;
}