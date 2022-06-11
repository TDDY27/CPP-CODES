#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define INF 1e9
#define _INF -1e9

using namespace std;

int n;
int const maxn=1e5+500;
int const eps=1e-9;
int num[maxn];

signed main(){
    TDDY
    while(cin>>n && n){
        int mmax=_INF, mmin=INF;
        double sum=0;
        for(int i=0;i<n;i++){
            cin>>num[i];
            mmax=max(mmax,num[i]);
            mmin=min(mmin,num[i]);
            sum+=num[i];
        }

        sum-=(mmin+mmax);
        sum/=(n-2), sum+=eps;
        cout<<setprecision(2)<<fixed<<sum<<endl;
    }
}
