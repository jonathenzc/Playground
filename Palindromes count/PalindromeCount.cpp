#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "TAFY48O99O84YFAT";
	int strLen = s.size();

	//isPalindrome[i][j]=true means substr s[i...j] is palindrome
	//isPalindrome[i][j] = true if s[i] = s[j] and isPalindrome[i+1][j-1] = true
	bool **isPalindrome = new bool*[strLen];
	for (int i = 0; i < strLen; i++)
		isPalindrome[i] = new bool[strLen];

	int sumPalindrome = 0;
	for (int i = 0; i < strLen; i++)
	{
		isPalindrome[i][i] = true;
		sumPalindrome++;
	}
	
	//Here is the trick one. You can't just using i and j travel through the array 
	//Because eg. 0990 is palindrome until 99 is palindrome but 0990 is visited before 99.
	//So I use a variable called subLen for travelling through
	for (int subLen = 2; subLen <= strLen; subLen++)
	{
		//i is the start index
		for (int i = 0; i < strLen-subLen+1; i++)
		{
			//j is the end index
			int j = i+subLen-1;

			if (subLen==2)
			{
				if (s[i] == s[j])
				{
					isPalindrome[i][j] = true;
					cout << sumPalindrome << " " << i<<" "<<j<< endl;
					sumPalindrome++;
					
				}
				else
					isPalindrome[i][j] = false;
			}
			else
			{
				if (s[i] == s[j] && isPalindrome[i + 1][j - 1] == true)
				{
					isPalindrome[i][j] = true;
					cout << sumPalindrome << " " << i << " " << j << endl;
					sumPalindrome++;
				}
				else
					isPalindrome[i][j] = false;
			}
		}
	}

	cout << sumPalindrome;
	return 0;
}