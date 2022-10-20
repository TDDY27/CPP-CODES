#include <bits/stdc++.h>

using namespace std;

map <int,int> mp;
int num[5500];

signed main(){
    int n,x;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        mp.insert({x-num[i],i});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp.count(num[i]+num[j]) && i!=j ){
                int tmp=mp[num[i]+num[j]];
                if( tmp!=i && tmp!=j ){
                    cout<<i<<" "<<j<<" "<<tmp<<"\n";
                    return 0;
                }
            }

        }
    }
    cout<<"IMPOSSIBLE"<<endl;

}
