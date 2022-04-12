#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;


void Report(int x1,int y1,int x2,int y2,int x3,int y3){
    cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
}

void resolve(int n,int xx,int yy,int x,int y){
    if(n<=2){
        if(x==xx&& y==yy) Report(xx+1,yy,xx+1,yy+1,xx,yy+1);
        else if(x==xx+1 && y==yy) Report(xx,yy,xx,yy+1,xx+1,yy+1);
        else if(x==xx && y==yy+1) Report(xx+1,yy,xx+1,yy+1,xx,yy);
        else Report(xx,yy,xx+1,yy,xx,yy+1);
        return;
    }
    int tmp=n/2;
    int divx,divy;
    divx=(x-xx)/tmp;
    divy=(y-yy)/tmp;
    //cout<<tmp<<" "<<divx<<" "<<divy<<endl;

    if(0==divx && 0==divy) resolve(tmp,xx,yy, x, y);
    else resolve(tmp,xx,yy, xx+tmp-1, yy+tmp-1);

    if(1==divx && 0==divy) resolve(tmp,xx+tmp,yy, x, y);
    else resolve(tmp,xx+tmp,yy, xx+tmp, yy+tmp-1);

    if(0==divx && 1==divy) resolve(tmp,xx,yy+tmp, x, y);
    else resolve(tmp,xx,yy+tmp, xx+tmp-1, yy+tmp);

    if(1==divx && 1==divy) resolve(tmp,xx+tmp,yy+tmp, x, y);
    else resolve(tmp,xx+tmp,yy+tmp, xx+tmp, yy+tmp);

    if(0==divx && 0==divy) Report(xx+tmp,yy+tmp-1,xx+tmp,yy+tmp,xx+tmp-1,yy+tmp);
    else if(1==divx && 0==divy) Report(xx+tmp-1,yy+tmp-1,xx+tmp,yy+tmp,xx+tmp-1,yy+tmp);
    else if(0==divx && 1==divy) Report(xx+tmp-1,yy+tmp-1,xx+tmp,yy+tmp,xx+tmp,yy+tmp-1);
    else if(1==divx && 1==divy) Report(xx+tmp,yy+tmp-1,xx+tmp-1,yy+tmp-1,xx+tmp-1,yy+tmp);
}

void solve(int n,int x,int y){
    resolve(n,1,1,x,y);
}

signed main(){
    TDDY
    int t;
    cin>>t;
    while(t>0){
        int len,cinx,ciny;
        cin>>len>>cinx>>ciny;
        solve(len,cinx,ciny);
        t--;
    }
}
