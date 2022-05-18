#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back
using namespace std;

int n,t;
int W[60],M[60],C[60];
vector <int> dW; //divided W
vector <int> dM; //divided M
int dp[15000];

signed main(){
    TDDY
    memset(dp,0,sizeof(dp));
    dW.clear();
    dM.clear();

    cin>>n;
    for(int i=1;i<=n;i++) cin>>W[i]>>M[i]>>C[i];
    //for(int i=1;i<=n;i++) cout<<W[i]<<" \n"[i==n];
    //for(int i=1;i<=n;i++) cout<<M[i]<<" \n"[i==n];

    cin>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=C[i];j<<=1){
            if( (j<<1)>C[i]){
                int rem=C[i]-(j-1); //若直接用j的話會造成全部加起來可能會超過C[i]
                dW.PB(rem*W[i]);
                dM.PB(rem*M[i]);
                break;
            }
            dW.PB(j*W[i]);
            dM.PB(j*M[i]);
        }
    }

    int len=dW.size();
    //for(int i=0;i<len;i++) cout<<dW[i]<<" \n"[i==n];
    //for(int i=0;i<len;i++) cout<<dM[i]<<" \n"[i==n];
    for(int i=0;i<len;i++){
        for(int j=t;j>=1;j--){
            if(j-dW[i]>0 ) dp[j]=max(dp[j],dp[j-dW[i]]+dM[i]);
            else if(j-dW[i]==0) dp[j]=max(dp[j],dM[i]);
        }
    }
    
    cout<<dp[t];
}
