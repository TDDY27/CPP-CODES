#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t,n;
int const maxn=1e6+500;
int rck[maxn];

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        memset(rck,0,sizeof(rck));
        cin>>n;
        for(int i=1;i<=n;i++) cin>>rck[i];
        if(n==1){
            cout<<1<<endl;
            t--;
            continue;
        }

        int now=0;
        int len=0;
        for(int i=1;i<=n-1;i++){
            if(now==1){
                if(rck[i+1]<=rck[i]) continue;
                len++;
                now=0;
            }else{
                if(rck[i+1]>=rck[i]) continue;
                len++;
                now=1;
            }
        }
        if(now==0 && rck[n]>=rck[n-1]){
            len++;
            now=1;
        }
        if(now==0) len--;
        cout<<len<<endl;
        t--;
    }
}
