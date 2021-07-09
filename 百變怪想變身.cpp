#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int len1,len2;
    len1 = str1.size();
    len2 = str2.size();
    if(len1!=len2)
    {
        cout<<"No"<<endl;
        return 0;
    }
    for(int i=0;i<len1;i++)
    {
        if( isalpha(str1[i])==isalpha(str2[i]) )
        {
            if( isupper(str1[i])==isupper(str2[i]) )
            {

            }
            else if( islower(str1[i])==islower(str2[i]) )
            {

            }
            else
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
        else
        {
            if( isdigit(str1[i])==isdigit(str2[i]) )
            {

            }
            else
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
