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

    for(int i=2;i<k;i++){
        tmp=Query(1,i);
        mp[tmp]=i;
        if(tmp==1){ Report( Query(1,i-1) ); return 0;}
    }

    int now,val,ind;
    now=(k+1)%n;
    ind=1;
    while(true){
        val=Query(ind,now);
        if(val==1) break;
        if(mp.count(val)){
            now-=mp[val];
            break;
        }
        if(now+k>n){
            ind=val;
            now=k;
        }else now+=k;
    }

    int ans;
    now--;
    ans=Query(ind,now);
    Report(ans);
}
