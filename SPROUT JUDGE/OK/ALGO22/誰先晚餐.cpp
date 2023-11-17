#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t,n;

struct fin{
    int ck;
    int eat;
} ;

bool cmp(fin a,fin b){ return a.eat>b.eat;}

int const maxn=1e5;
fin res[maxn];

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n;
        for(int i=0;i<n;i++) cin>>res[i].ck>>res[i].eat;
        sort(res,res+n,cmp);
        //for(int i=0;i<n;i++) cout<<res[i].ck<<" "<<res[i].eat<<endl;
        int now=0;
        int ans=0;
        for(int i=0;i<n;i++){
            now+=res[i].ck;
            ans=max(ans,now+res[i].eat);
        }

        cout<<ans<<endl;
        t--;
    }
}
