#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back

using namespace std;

int n;
int const maxn=2e5+500;
int ind[maxn];

unordered_map<int ,int> pos;


signed main(){
    TDDY
    memset(ind,0,sizeof ind);
    pos.clear();

    cin>>n;
    for(int i=1;i<=n;i++) cin>>ind[i];
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        pos[tmp]=i;
    }
    for(int j=1;j<=n;j++) cout<<ind[j]<<" \n"[j==n];
    for(int j=1;j<=n;j++) cout<<pos[ind[j]]<<" \n"[j==n];

    vector <int> lis;
    vector <int> rec;
    vector <int> res;

    lis.PB(pos[ind[1]]);
    rec.PB(ind[1]);
    res.PB(ind[1]);
    for(int i=2;i<=n;i++){
        if(pos[ind[i]]>lis.back()){
            lis.PB(pos[ind[i]]);
            rec.PB(ind[i]);
            res.clear();
            for(int j=0;j<rec.size();j++) res.PB(rec[j]);
        }else{
            int tmp=lower_bound(lis.begin(),lis.end(),pos[ind[i]])-lis.begin();
            lis[tmp]=pos[ind[i]];
            rec[tmp]=ind[i];
            if(tmp==lis.size()-1){
                int flag=0;
                for(int j=0;j<res.size();j++){
                    if(rec[j]>res[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                    res.clear();
                    for(int j=0;j<rec.size();j++) res.PB(rec[j]);
                }
            }
        }
        for(int j=0;j<rec.size();j++) cout<<rec[j]<<" \n"[j==res.size()-1];
        for(int j=0;j<res.size();j++) cout<<res[j]<<" \n"[j==res.size()-1];
    }

    for(int i=0;i<res.size();i++) cout<<res[i]<<" \n"[i==res.size()-1];

}

