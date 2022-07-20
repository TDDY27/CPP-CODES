#include <bits/stdc++.h>
#define INF 1e17
#define int long long

using namespace std;

int num[25];

void solve(int n){
    int a,b,mmin=INF;
    for(int i=0;i<(1<<n);i++){
        a=b=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) a+=num[j];
            else b+=num[j];
        }
        mmin=min(mmin, abs(a-b));
    }
    cout<<mmin<<endl;
}

signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];
    solve(n);
}
