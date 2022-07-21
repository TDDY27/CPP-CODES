#include <bits/stdc++.h>
#define int long long

using namespace std;

struct info{
    int val;
    int pos;
};

map <int,int> mp; // can't use unordered_map because it would use too much time to search

int const maxn=2e5+500;
info num[maxn];

bool cmp(info a,info b){ return a.val>b.val; }

signed main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>num[i].val;
        num[i].pos=i+1;
    }

    for(int i=0;i<n;i++){
        if(mp.count(x-num[i].val) ){
            cout<<num[i].pos<<" "<<mp[x-num[i].val]<<endl;
            return 0;
        }
        if(!mp.count(num[i].val) ) mp[num[i].val]=num[i].pos;
    }
    cout<<"IMPOSSIBLE"<<endl;
}
