#include <bits/stdc++.h>
#define TDDY::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

double const eps=1e-10;
int n;
double num[550];

bool Equal(double a, double b){
    return a+eps>b && a-eps<b;
}

signed main(){
    TDDY
    memset(num,0,sizeof num);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];

    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if( Equal(num[j]+num[i],num[k]) )ans++;

    cout<<ans<<endl;
}
