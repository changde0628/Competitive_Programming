#include <iostream>
#include <deque>
using namespace std;
int ans[10000005];
int main(){
    deque<pair<int,int> > d;
    int n,m,a,b,c;      //k-> m q->a i->b x->c
    cin>>n>>m;
    cin>>c;
    d.push_back(make_pair(c,0));
    for(int i=1;i<n;i++){
        cin >> c;
        while(d.size() && d.back().first > c)
            d.pop_back();
        d.push_back(make_pair(c,i));
        if(d.front().second == i-m)
            d.pop_front();
        ans[i] = d.front().first;
    }
    cin>>a;
    while(a--)
    {
        cin>>b;
        cout<<ans[b+m-1] << endl;
    }
}
