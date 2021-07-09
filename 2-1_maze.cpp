#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
int n,m;
vector<char>v[101];
int t[101][101];
queue< pair<int,int> >q;
int bfs(int x,int y);
int main()
{
    cin>>n>>m;
    pair<int,int> s;
    pair<int,int> e;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char tmp;
            cin>>tmp;
            v[i].push_back(tmp);
            if(tmp=='S')
            {
                s.first = i;
                s.second = j;
            }
            if(tmp=='G')
            {
                e.first = i;
                e.second = j;
            }
        }
    }
    int res = bfs(e.first,e.second);
    cout<<res<<endl;
    return 0;
}

int bfs(int x,int y)
{
    int arrx[4]={1,-1,0,0};
    int arry[4]={0,0,1,-1};
    q.push(make_pair(0,0));
    while(q.size())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(x+arrx[i]<n&&x+arrx[i]>=0&&y+arry[i]>=0&&y+arry[i]<m)
            {
                if(v[x+arrx[i]][y+arry[i]]!='#')
                {
                    q.push(make_pair(x+arrx[i],y+arry[i]));
                    t[x+arrx[i]][y+arry[i]] = t[nx][ny]+1;
                }
            }
        }
    }
    return t[x][y];
}
