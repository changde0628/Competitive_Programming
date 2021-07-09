#include <iostream>
#include <cstring>
#include <math.h>
#include <cstdlib>
using namespace std;
int cheak1(string x);
int cheak2(string x);
int arr[105],counter[105];
int main()
{
    int n;
    string mod,num;
    cin>>n;
    string colar;
    for(int i=0;i<n;i++)
    {
        cin>>mod>>num>>colar;
        if(mod=="A")
        {
            arr[i]=(((cheak1(colar)+2)*(cheak2(num)+4)))%8;
        }
        if(mod=="B")
        {
            arr[i]=((cheak1(colar)+1)*(cheak2(num)+7))%8;
        }
        if(mod=="C")
        {
            arr[i]=((cheak1(colar)+3)*(cheak2(num)+3))%8;
        }
        mod.clear();
        num.clear();
    }
    int point=0;
    double tmp = 0;
    double total = 0;
    int i=0;
	while (i < n)
    {
        counter[arr[i]]+=1;
        i++;
	}
	for (int i=0; i<8; i++)
    {
        total+=counter[i]*(counter[i]-1);
    }
    int k = n*(n-1);
    cout<<round((float)total/(float)k*100)/100<<endl;
    return 0;
}

int cheak1(string x)
{
    if(x=="club")
    {
        return 1;
    }
    if(x=="diamond")
    {
        return 2;
    }
    if(x=="heart")
    {
        return 3;
    }
    if(x=="spade")
    {
        return 4;
    }
}

int cheak2(string x)
{
    if(x=="A")
    {
        return 1;
    }
    if(x=="J")
    {
        return 11;
    }
    if(x=="Q")
    {
        return 12;
    }
    if(x=="K")
    {
        return 13;
    }
    if(x=="10")
    {
        return 10;
    }
    else
    {
        return (int)x[0]-48;
    }
}
