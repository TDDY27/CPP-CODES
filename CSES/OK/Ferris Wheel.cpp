#include <bits/stdc++.h>

using namespace std;

int const maxn=2e5+500;
int ch[maxn];
priority_queue< int, vector<int>, less<int> > pq;

bool cmp(int a,int b){ return a>b; }

signed main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++) cin>>ch[i];
    sort(ch,ch+n,cmp);

    int ans=0;
    for(int i=0;i<n;i++){
        if(ch[i]==x){
            ans++;
            continue;
        }
        if(!pq.size() || pq.top()<ch[i]){
            pq.push(x-ch[i]);
        }else if(pq.top()>=ch[i]){
            pq.pop();
            ans++;
        }
    }
    cout<<ans+pq.size()<<endl;
}
