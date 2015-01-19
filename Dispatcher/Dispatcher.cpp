#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef int vertex;

struct edge
{
	vertex start;
	vertex end;
	int value;
};

//count of intersections
int intersections = 0;

//single source shortest path
int *BellmanFord(vertex source, edge *edgeS,int edgeSize)
{
	//the shortest distance from source node to other nodes.
	int *distance = new int[intersections];

	//initiate array distance
	for (int i = 0; i <= intersections; i++)
		distance[i] = 999999;

	distance[source] = 0;

	for (int i = 0; i < edgeSize; i++)
	{
		if (edgeS[i].start == source )
			distance[edgeS[i].end] = edgeS[i].value;	
	}

	for (int v = 0; v < intersections - 1; v++)
	{
		//O(vertex*edge)
		for (int edgeIndex = 0; edgeIndex < edgeSize; edgeIndex++)
		{
			//relaxation
			vertex start = edgeS[edgeIndex].start;
			vertex end = edgeS[edgeIndex].end;
			int value = edgeS[edgeIndex].value;

			int min = distance[start] + value;
			if (distance[end] > min)
				distance[end] = min;
		}
	}

	//for (int i = 1; i <= intersections; i++)
	//	cout << i<<" "<<distance[i]<<endl;


	//for (int i = 0; i < nodes; i++)
	//	cout << start << "->" << i << " : " << distance[i] << endl;

	return distance;
}

//turn string into integer
int str_2_int(string s,int startIndex,int length)
{
	string substr = s.substr(startIndex, length);

	int digit = 1;
	int sum = 0;

	for (int i = 0; i < substr.size(); i++)
	{
		digit = substr[i]-'0';
		for (int j = 0; j < substr.size() - i - 1; j++)
			digit *=  10;

		sum += digit;
	}

	return sum;
}

//turn city_map into edgeSet
edge *edgeSet(const vector<string> &city_map)
{
	//bidirection
	edge *result = new edge[city_map.size()*2];

	for (int i = 0; i < city_map.size(); i++)
	{
		int firstCommaIndex = city_map[i].find_first_of(",");
		int secondCommaIndex = city_map[i].find_last_of(",");

		//get edge's start node, end node and value
		vertex start = str_2_int(city_map[i],0,firstCommaIndex-0);
		vertex end = str_2_int(city_map[i],firstCommaIndex+1,secondCommaIndex-firstCommaIndex-1);
		int value = str_2_int(city_map[i],secondCommaIndex+1,city_map[i].size()-secondCommaIndex-1);

		//get count of intersections
		if (start > intersections)
			intersections = start;
		else if (end > intersections)
			intersections = end;
		
		//turn city_map into edgeSet
		result[i].start = start;
		result[i].end = end;
		result[i].value = value;

		int citySize = city_map.size();
		result[i + citySize].start = end;
		result[i + citySize].end = start;
		result[i + citySize].value = value;
	}

	return result;
}

void find_closest_car(const vector<string> &city_map, const vector<int> &cars, int customer) 
{
	edge *edgeS = edgeSet(city_map);

	//shortest distance from customer to every intersections
	int *distance = BellmanFord(customer, edgeS, 2*city_map.size());

	//find the closet car
	int closetDistance = 999999;
	int closetCar = -1;

	for (int i = 0; i < cars.size(); i++)
	{
		if (distance[cars[i]] < closetDistance)
		{
			closetCar = i+1;
			closetDistance = distance[cars[i]];
		}
	}

	cout << closetCar<<endl;
}

int main()
{
	vector<string> city_map;
	city_map.push_back("1,2,1");
	city_map.push_back("2,3,2");
	city_map.push_back("1,3,1");
	city_map.push_back("3,4,1");

	vector<int> cars;
	cars.push_back(2);
	cars.push_back(1);

	int customer = 4;

	find_closest_car(city_map,cars,customer);

	return 0;
}
