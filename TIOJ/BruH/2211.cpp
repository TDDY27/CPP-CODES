#include <bits/stdc++.h>
#include "lib2211.h"
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

signed main() {
    //TDDY
    unordered_map <int,int> mp;
    int n, k, tmp;

    n=Init();
    k=sqrt(n);
    tmp=Query(1,1);
    mp[tmp]=1;

    for(int i=2;i<=k;i++){
        tmp=Query(1,i);
        mp[tmp]=i;
        if(tmp==1){ Report( Query(1,i-1) ); return 0;}
    }

    int now,val;
    now=(2*k+2)%n;
    while(true){
        val=Query(1,now);
        if(val==1) break;
        if(mp.count(val)){
            now-=mp[val];
            break;
        }
        now=(now+k)%n;
        if(now==0) now=n;
    }

    int ans;
    ans=Query(1,now-1);
    Report(ans);
}
