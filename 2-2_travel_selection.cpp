#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int cmp(pair<int,int> a,pair<int,int> b);
int main()
{
    int n,work=0;
    cin>>n;
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++)
    {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        v.push_back(make_pair(tmp1,tmp2));
    }
    sort(v.begin(),v.end(),cmp);
    int current_time = 0;
    for(auto n:v)
    {
        if(n.first>=current_time)
        {
            work++;
            current_time = n.second;
        }
    }
    cout<<work<<endl;
    return 0;
}

int cmp(pair<int,int> a,pair<int,int> b)
{
    return  a.second<b.second;
}
