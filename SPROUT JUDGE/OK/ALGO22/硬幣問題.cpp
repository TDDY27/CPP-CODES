#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back
using namespace std;

int t,n,m;
int const maxn=2e4+500;
int ind[maxn];
int num[maxn];
vector <int> Div; //divide
int dp[25000];

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        memset(ind,0,sizeof ind);
        memset(num,0,sizeof num);
        memset(dp,0,sizeof dp);
        Div.clear();

        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>ind[i]>>num[i];

        for(int i=1;i<=n;i++){
            for(int j=1;j<=num[i];j<<=1){
                if( (j<<1)>num[i] ){
                    int tmp=num[i]-(j-1);
                    Div.PB(tmp*ind[i]);
                    break;
                }
                Div.PB(j*ind[i]);
            }
        }

        for(int i=0;i<Div.size();i++){
            for(int j=m;j>=1;j--){
                if(j-Div[i]>=0) dp[j]=max(dp[j],dp[j-Div[i]]+Div[i]);
            }
        }

        if(dp[m]==m) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

        t--;
    }

}
