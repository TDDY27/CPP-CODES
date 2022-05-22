#include <bits/stdc++.h>
#include "lib2211.h"
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

unordered_map <int,int> mp;

signed main() {
    //TDDY

    int n,k,tmp;
    n=Init();
    k=sqrt(n);
	
    tmp=Query(1,1);
    mp[tmp]=1;
    if(tmp==1){ Report(1); return 0;}

    for(int i=2;i<=k;i++){
        tmp=Query(1,i);
        mp[tmp]=i;
        if(tmp==1){ Report( Query(1,i-1) ); return 0;}
    }

    int now,val;
    now=k+1;
    while(true){
        val=Query(1,now);
        if(val==1) break;
        if(mp.count(val)){
	    // 要注意因為now會％n所以now可能會比mp[val]小
            if(now<=mp[val]) now+=n;
	    now-=mp[val];
            break;
        }
        now=(now+k)%n;
        if(now==0) now=n;
    }

    int ans;
    now--;
    now=(now+n)%n;
    if(now==0) now=n;
    ans=Query(1,now);
    Report(ans);
}
