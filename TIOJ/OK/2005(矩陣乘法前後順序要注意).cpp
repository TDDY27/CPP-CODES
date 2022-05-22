#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define matrix array< array< int,5> ,5>

using namespace std;

array<int ,5> dp;
matrix FA; //FA-SHEA-
int n,m;

matrix mul(matrix A, matrix B){
    matrix res;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            res[i][j]=0;
            for(int k=1;k<=3;k++){
                res[i][j]=(res[i][j]+A[i][k]*B[k][j])%m;
            }
        }
    }
    return res;
}

matrix exp(matrix A, int t){
    matrix res;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++) res[i][j]=0;
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

    while(cin>>n>>m){
        dp[1]=0; dp[2]=1; dp[3]=1;
        FA[1][1]=10; FA[1][2]=1; FA[1][3]=0;
        FA[2][1]=0; FA[2][2]=1; FA[2][3]=1;
        FA[3][1]=0; FA[3][2]=0; FA[3][3]=1;

        matrix rec;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++) rec[i][j]=0;
            rec[i][i]=1;
        }

        for(int i=1;i<=n;i*=10){
            if(n==i){
                rec=mul(exp(FA,1),rec); //矩陣前後順序要注意
                break;
            }else if(n<i*10){
                rec=mul(exp(FA,n-i+1),rec); //矩陣前後順序要注意
                break;
            }
            rec=mul(exp(FA,i*10-i),rec); //矩陣前後順序要注意
            FA[1][1]*=10;
            //cout<<FA[1][1]<<endl;
        }

        int ans=0;
        //cout<<rec[1][1]<<" "<<rec[1][2]<<" "<<rec[1][3]<<endl;
        ans=(rec[1][1]*dp[1]+rec[1][2]*dp[2]+rec[1][3]*dp[3])%m;
        cout<<ans<<endl;
    }

}
