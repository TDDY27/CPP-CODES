#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define matrix array < array<int,1550>, 1550>
using namespace std;

matrix A; matrix B; matrix C;
matrix R; //random matrix to decrease time complexity
int n,m,k;

int MT[2000];
void mt19937_ing(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(MT,MT+2000,rng);
}

matrix mul(matrix tA, int rA,int cA, matrix tB, int rB, int cB){
    // temporary matrix A&B ; row A&B column A&B
    matrix res;
    for(int i=1;i<=rA;i++){
        for(int j=1;j<=cB;j++){
            res[i][j]=0;
            for(int k=1;k<=cA;k++){
                res[i][j]+=tA[i][k]*tB[k][j];
            }
        }
    }
    return res;
}


signed main(){
	TDDY
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>A[i][j];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=k;j++) cin>>B[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=k;j++) cin>>C[i][j];
    for(int i=0;i<2000;i++) MT[i]=i+1;
    mt19937_ing();
    for(int i=1;i<=k;i++) R[i][1]=MT[i];

    matrix BR; matrix ABR; matrix CR;
    BR=mul(B,m,k,R,k,1); ABR=mul(A,n,m,BR,m,1);
    CR=mul(C,n,k,R,k,1);

    int flag=1;
    for(int i=1;i<=n;i++){
        if(ABR[i][1]!=CR[i][1]){ flag=0; break;}
    }
    if(flag==0) cout<<"No";
    else cout<<"Yes";

}
