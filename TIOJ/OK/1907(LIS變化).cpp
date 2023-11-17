#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back

using namespace std;

int t,m;
struct doll{
    int w;
    int h;
};
doll ind[21000];

bool cmp(doll a,doll b){
    if(a.w!=b.w) return a.w<b.w;
    else return a.h>b.h;
}

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        memset(ind,0,sizeof ind);
        cin>>m;
        for(int i=0;i<m;i++) cin>>ind[i].w>>ind[i].h;
        sort(ind,ind+m,cmp);
        //for(int i=0;i<m;i++) cout<<ind[i].w<<" \n"[i==m-1];

        vector<int> dp;
        dp.PB(ind[0].h);
        for(int i=1;i<m;i++){
            if(ind[i].h>dp.back()){
                dp.PB(ind[i].h);
            }else{
                int tmp=lower_bound(dp.begin(),dp.end(),ind[i].h)-dp.begin();
                dp[tmp]=ind[i].h;
            }
        }
        cout<<dp.size()<<endl;
        t--;
    }

}
