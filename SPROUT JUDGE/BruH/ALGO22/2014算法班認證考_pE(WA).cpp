#include <bits/stdc++.h>
#define int long long
#define PB push_back
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t,n,m;
int const maxn=1e5+500;
int box[maxn];
int plm[maxn];
int vis[maxn];
int full[maxn];//rec full box

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        cin>>n>>m;
        memset(box,0,sizeof(box));
        memset(plm,0,sizeof(plm));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) cin>>box[i];
        for(int i=0;i<m;i++) cin>>plm[i];
        sort(box,box+n);
        sort(plm,plm+m);

        int ans=0;
        for(int i=0;i<m;i++){
            if(vis[i]==1) continue;
            int now=0;// record box
            int temp=0;
            memset(full,0,sizeof(full));
            for(int j=i;j<m;j++){
                if(plm[j]%plm[i]==0){
                    vis[j]=1;
                    while(box[now]-full[now]<plm[j] && now<m) now++;
                    if(now==m) break;
                    full[now]+=plm[j];
                    temp++;
                }

            }
            ans=max(ans,temp);
        }

        cout<<ans<<endl;

        t--;
    }
}
