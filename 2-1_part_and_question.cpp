#include <iostream>
#include <vector>
using namespace std;
int dfs(int i,int sum);
int n,k;
vector<int>v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    cin>>k;
    if(dfs(0,0))
        cout<<"Yes"<<endl;
    return 0;
}

int dfs(int i,int sum)
{
    cout<<i<<' '<<sum<<endl;
    if(i==n)
        return sum==k;
    if(dfs(i+1,sum))
        return true;
    if(dfs(i+1,sum+v[i]))
        return true;
    return false;
}
