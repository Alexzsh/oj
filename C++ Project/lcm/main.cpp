#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	char ch = ' ';
	int  j = 0, k = 0, sum = 0, max = 0;
	cin >> s;
	string ss = "";
	for (int i = 0; i < s.length(); i++) {
		
		size_t pos = ss.find(s[i]);
		if (pos == std::string::npos) {
			ss.push_back(s[i]);
			j++;
			sum++;
		}
		else
		{
			ss = "";
			max = sum > max ? sum : max;
			j = 0;
			k++;
		}
	}

	cout << max;

}

