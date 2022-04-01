#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define PB push_back
#define float double
using namespace std;

int t,n;
float f[20][3];

float func(float ind){
    float maxn=0;
    for(int i=1;i<=n;i++) maxn=max( maxn, f[i][0]*(ind-f[i][1])*(ind-f[i][1])+f[i][2] ) ;
    return maxn;
}

float ter(){
    int k=10000;
    float fa,fb,fc,fd;
    fa=0,fb=100,fc=200,fd=300;
    while(k>0){
        //cout<<fb<<" "<<fc<<endl;
        if( func(fb)>func(fc) ){
            fa=fb;
            fc=(fa+fd+fd)/3;
            fb=(fa+fa+fd)/3;
        }else{
            fd=fc;
            fc=(fa+fd+fd)/3;
            fb=(fa+fa+fd)/3;
        }
		    k--;
    }
    return func((fb+fc)/2);
}

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        memset(f,0,sizeof(f));

        cin>>n;
        for(int i=1;i<=n;i++) cin>>f[i][0]>>f[i][1]>>f[i][2];
		    cout<<setprecision(17)<<ter()<<endl;

        t--;
    }
}
