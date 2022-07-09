#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);

using namespace std;

int n,m,c;
int const mod=1e9+7;
int const maxn=2e4+500;

int bw[250], bv[250], aw[2][250], av[250];

int dpb[maxn]; // dp bb gun
int rcb[maxn]; // record ways bb gun
int dpa[maxn]; // dp arrow
int rca[maxn]; // record ways arrow
int arr[maxn]; // special for buying an arrow of a(n)

signed main(){
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++) cin>>bw[i]>>bv[i];
    for(int i=1;i<=m;i++) cin>>aw[0][i]>>aw[1][i]>>av[i];

    for(int i=1;i<=n;i++){
        for(int j=c;j>=bw[i];j--){
            if(dpb[j]<dpb[j-bw[i]]+bv[i]){
                dpb[j]=dpb[j-bw[i]]+bv[i];
                if(rcb[j-bw[i]]) rcb[j]=rcb[j-bw[i]];
                else if(j-bw[i]==0) rcb[j]=1;
            }else if(dpb[j]==dpb[j-bw[i]]+bv[i]){
                rcb[j]+=rcb[j-bw[i]];
            }
        }

    }

    for(int i=1;i<=m;i++){
        for(int j=aw[0][i];j<=c;j++)
            arr[j]=dpa[j-aw[0][i]];
        for(int )
        for(int j=aw[1][i]+aw[0][i];j<=c;j++){
            if(dpa[j]<arr[j-aw[1][i]]+av[i]){
                dpa[j]=arr[j-aw[1][i]]+av[i];
                arr[j]=dpa[j];
                if(rca[j-aw[1][i]]) rca[j]=rca[j-aw[1][i]];
                else rca[j]=1;
            }else if(dpa[j]==arr[j-aw[1][i]]+av[i]){
                rca[j]+=rca[j-aw[1][i]];
            }
        }
    }

    int ansb=0, wayb=0, ansa=0, waya=0;
    for(int i=0;i<=c;i++){
        if(dpb[i]>ansb){
            ansb=dpb[i];
            wayb=rcb[i];
        }else if(dpb[i]==ansb){
            wayb+=rcb[i];
        }
        if(dpa[i]>ansa){
            ansa=dpa[i];
            waya=rca[i];
        }else if(dpb[i]==ansb){
            waya+=rca[i];
        }
    }
    cout<<ansb<<" "<<wayb<<endl;
}

