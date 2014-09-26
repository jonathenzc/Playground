#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cntReversePair(int *HTCnt, int start, int middle, int end)
{
	int *temp = new int[end - start+2];
	int i = start, j = middle + 1;
	int tempIndex = 0;
	int reversePairCnt = 0;

	while (i <= middle && j <= end)
	{
		if (HTCnt[i] <= HTCnt[j])
		{
			temp[tempIndex] = HTCnt[i];
			tempIndex++;
			i++;
		}
		else
		{
			temp[tempIndex++] = HTCnt[j++];
			reversePairCnt += middle - i + 1;
		}
	}

	while (i <= middle)
		temp[tempIndex++] = HTCnt[i++];

	while (j <= end)
		temp[tempIndex++] = HTCnt[j++];

	int HTIndex = start;
	for (int k = 0; k < tempIndex; k++)
		HTCnt[HTIndex++] = temp[k];

	return reversePairCnt;
}

void getReversePair(int *HTCnt, int start,int end,int& sum)
{
	if (start == end)
		return;
	else
	{
		int middle = (start + end) / 2;
		
		getReversePair(HTCnt,start, middle,sum);
		getReversePair(HTCnt,middle+1,end,sum);
		sum += cntReversePair(HTCnt,start,middle,end);
	}
}



int main()
{
	vector<string> data;
	data.push_back("H");
	data.push_back("T");
	data.push_back("H");
	data.push_back("T");
	data.push_back("T");
	data.push_back("H");

	int *HTCnt = new int[data.size()+1];
	int HTSize = data.size()+1;

	HTCnt[0] = 0;
	if (data.at(0) == "T")
		HTCnt[1] = -1;
	else
		HTCnt[1] = 1;

	for (int i = 1; i < data.size(); i++)
	{
		if (data[i] == "H")
			HTCnt[i+1] = HTCnt[i] + 1;
		else
			HTCnt[i+1] = HTCnt[i] - 1;
	}

	int sum = 0;
	getReversePair(HTCnt,0,HTSize-1,sum);

	cout << HTSize*(HTSize-1)/2-sum;

	return 0;
}4