#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
    int t;
    cin>>t;

    while(t>0){
        int q;
        cin>>q;

        int tot=9,now=9,rem;
        for(int i=1,j=9; i<=18; i++,j*=10){
            if(q<tot){
                now-= (tot-q)/i;
                rem=(tot-q)%i+1;
                break;
            }

            tot+=j*10*(i+1);
            now+=j*10;
        }

        for(int i=1;i<rem;i++) now/=10;
        cout<<now%10<<endl;

        t--;
    }
}
