#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int,int>

using namespace std;

int n,r,x,y;
map <pii ,int> rec;

bool out(int nx, int ny, int x, int y, int r){
    int x1=nx-x, y1=ny-y;
    int dis=x1*x1+y1*y1;
    return dis> (r*r);
}

signed main(){
    cin>>n>>r;

    int ans=0;
    for(int t=1;t<=n;t++){
        cin>>x>>y;
        for(int j=y+r; j>=y-r; j-- ){
            for(int i=x-r; i<=x+r; i++ ){
                if(out(i,j,x,y,r)) continue;
                if(!rec.count({i,j}) ){
                    rec[{i,j}]=1;
                    ans++;
                }else{
                    rec[{i,j}]++;
                    if( rec[{i,j}]%2==0 ) ans--;
                    else ans++;
                }
            }
        }
    }

    cout<<ans<<endl;
}
