#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back
using namespace std;

int t,n,m;
vector <int> v;

signed main(){
    TDDY
    cin>>t;
    while(t>0){
        v.clear();
        cin>>n>>m;

        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            if(temp*2>=m) v.PB(temp*2);
            if(temp>=m) v.PB(temp);
        }
        int len=v.size();
        if(len==0){ cout<<0<<endl; t--; continue;}

        vector <int> lis;
        lis.PB(v[0]);
        for(int i=1;i<len;i++){
            if(v[i]>=lis.back()){
                lis.PB(v[i]);
            }else{
                int ind=upper_bound(lis.begin(),lis.end(),v[i])-lis.begin();
                lis[ind]=v[i];
            }
        }
        cout<<lis.size()<<endl;
        t--;
    }
}
