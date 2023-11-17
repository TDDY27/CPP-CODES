#include <bits/stdc++.h>
#define PB push_back
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t,n,m,x;
int now1=0,now2=0;
string q;
int const maxn=1e7;
int grp[maxn];
vector <vector<int> > lin;
int rec[2000];

int main(){
    TDDY
    cin>>t;
    int cnt=1;
    while(t>0){
        fill(rec,rec+2000,-1);
        fill(grp,grp+maxn,-1);
        for(int i=0;i<lin.size();i++) lin[i].clear();
        //now1=0;now2=0;

        cout<<"Line #"<<cnt<<endl;
        cin>>n;
        for(int i=1;i<=n;i++){
            int num;
            cin>>num;
            for(int j=0;j<num;j++){
                int temp;
                cin>>temp;
                grp[temp]=i;
            }
        }

        cin>>m;
        for(int i=0;i<m;i++){
            cin>>q;
            if(q=="ENQUEUE"){
                cin>>x;
                if(grp[x]==-1 || rec[grp[x]]==-1){
                    lin.PB({});
                    lin[lin.size()-1].PB(x);
                    if(rec[grp[x]]==-1) rec[grp[x]]=lin.size()-1;
                }else{
                    lin[rec[grp[x]]].PB(x);
                }
            }else{
                if(now2==lin[now1].size()-1){
                    cout<<lin[now1][now2]<<endl;
                    rec[grp[ lin[now1][now2] ] ]=-1;
                    now1++;
                    now2=0;
                }else{
                    cout<<lin[now1][now2]<<endl;
                    now2++;
                }
            }
        }
        cnt++;
        t--;
    }

}
