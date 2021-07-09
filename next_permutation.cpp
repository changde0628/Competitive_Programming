#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int len = str.size();
	do{
		cout<<str;
		cout<<endl;
	}while(next_permutation(str.begin(),str.end()));

	return 0;
}
