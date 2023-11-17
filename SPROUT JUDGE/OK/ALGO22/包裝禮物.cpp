#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t;
int box[10];

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        memset(box,0,sizeof(box));
        for(int i=1;i<=6;i++) cin>>box[i];

        int ans=0;
        int n1=0,n2=0;
        ans+=box[6];
        ans+=box[5];
        n1+=box[5]*11;
        ans+=box[4];
        n2+=box[4]*5;
        ans+=box[3]/4;
        box[3]%=4;
        if(box[3]>0) ans++;
        if(box[3]==1){
            n1+=7;
            n2+=5;
        }else if(box[3]==2){
            n1+=6;
            n2+=3;
        }else if(box[3]==3){
            n1+=5;
            n2+=1;
        }
        box[1]-=n1;
        box[2]-=n2;
        if(box[2]<0) box[1]-=(-1)*box[2]*4;

        if(box[2]>0){
            ans+=(box[2]+8)/9;
            box[2]%=9;
            if(box[2]>0){
                n1=36-4*box[2];
                box[1]-=n1;
            }
        }
        if(box[1]>0) ans+=(box[1]+35)/36;
        cout<<ans<<endl;
        t--;
    }
}
