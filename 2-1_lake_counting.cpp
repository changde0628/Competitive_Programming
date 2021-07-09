#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,m,counter=0;
vector<char>v[101];
int dfs(int x,int y);
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char tmp;
            cin>>tmp;
            v[i].push_back(tmp);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='W')
            {
                counter++;
                dfs(i,j);
            }
        }
    }
    cout<<counter<<endl;
    return 0;
}

int dfs(int x,int y)
{
    v[x][y] = '#';
    int arrx[8]={1,-1,0,0,1,-1,1,-1};
    int arry[8]={0,0,1,-1,1,1,-1,-1};
    for(int i=0;i<8;i++)
    {
        if(x+arrx[i]<n&&x+arrx[i]>=0&&y+arry[i]>=0&&y+arry[i]<m)
        {
            if(v[x+arrx[i]][y+arry[i]]=='W')
            {
                dfs(x+arrx[i],y+arry[i]);
            }
        }
    }
    return 0;
}
