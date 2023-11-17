#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define matrix array< array<int ,4>,4>
using namespace std;

int x1,x2,a,b,n;
int const mod=1e9+7;

matrix mul(matrix A,matrix B){
    matrix res;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            res[i][j]=0;
            for(int k=1;k<=2;k++){
                res[i][j]=(res[i][j]+A[i][k]*B[k][j])%mod;
            }
        }
    }
    return res;
}

matrix exp(matrix A,int t){
    matrix res;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++) res[i][j]=0;
        res[i][i]=1;
    }

    for(int i=1;i<=t;i<<=1){
        if(i&t) res=mul(res,A);
        A=mul(A,A);
    }
    return res;
}

signed main(){
    TDDY
    cin>>x1>>x2>>a>>b>>n;
    matrix ord;
    ord[1][1]=b; ord[1][2]=a; ord[2][1]=1; ord[2][2]=0;
    ord=exp(ord,n-2);
    int ans=0;
    ans=( ans+(ord[1][1]*x2+ord[1][2]*x1) )%mod;
    cout<<ans<<endl;
}
