#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

struct lnk{
    int f;
    int ths;
    int b;
};

int n,m,t,x;
int const maxn=1e5+500;
lnk ply[maxn];

signed main(){
    TDDY
    cin>>n>>m;
    memset(ply,0,sizeof(ply));

    int frst=1;
    int bck=n;

    for(int i=1;i<=n;i++){
        ply[i].f=i-1;
        ply[i].ths=i;
        ply[i].b=i+1;
    }

    int flag=0;
    for(int i=0;i<m;i++){
        cin>>t>>x;
        if(t==0){
            if(ply[x].ths==frst && ply[x].ths==bck){flag=1;break;}
            if(ply[x].ths==frst){
                frst=ply[x].b;
                continue;
            }
            if(ply[x].ths==bck) bck=ply[x].f;
            ply[ply[x].b].f=ply[x].f;
            ply[ply[x].f].b=ply[x].b;
            ply[x].ths=-1;
        }else{
            if(ply[x].ths==frst) continue;
            int temp=ply[x].f;
            ply[ply[x].b].f=temp;
            ply[ply[temp].f].b=ply[x].ths;

            ply[temp].b=ply[x].b;
            ply[x].f=ply[temp].f;
            ply[temp].f=ply[x].ths;
            ply[x].b=temp;
            if(temp==frst) frst=ply[x].ths;
            if(ply[x].ths==bck) bck=ply[x].b;
        }

        /*lnk now=ply[frst];
        while(now.b!=ply[bck].b){
            cout<<now.ths<<" ";
            now=ply[now.b];
        }
        cout<<now.ths<<endl;*/
    }
    if(flag==1){cout<<endl;return 0;}
    lnk now=ply[frst];
    while(now.b!=ply[bck].b){
        cout<<now.ths<<" ";
        now=ply[now.b];
    }
    cout<<now.ths<<endl;


}
