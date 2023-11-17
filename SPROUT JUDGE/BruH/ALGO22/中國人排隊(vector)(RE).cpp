#include <bits/stdc++.h>
#define PB push_back
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int t,n,m;
vector <int> grp[2000];
vector <vector<int> > lin;
int rec[2000];

int srch(int ind){
    for(int i=1;i<=n;i++){
        for(int j:grp[i]){
            if(ind==j) return i;
        }
    }
    return 0;
}

int main(){
    cin>>t;
    int cnt=1;
    while(t>0){
        fill(rec,rec+2000,-1);
        for(int i=0;i<lin.size();i++) lin[i].clear();
        for(int i=0;i<2000;i++) grp[i].clear();

        cout<<"Line #"<<cnt<<endl;
        cin>>n;
        for(int i=1;i<=n;i++){
            int num;
            cin>>num;
            for(int j=0;j<num;j++){
                int temp;
                cin>>temp;
                grp[i].PB(temp);
            }
        }

        string q;
        int x;
        int jian=0;
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>q;
            if(q=="ENQUEUE"){
                cin>>x;
                if(srch(x)==0 || rec[srch(x)-jian]==-1){
                    lin.PB({});
                    lin[lin.size()-1].PB(x);
                    if(srch(x)!=0) rec[srch(x)-jian]=lin.size()-1;
                }else{
                    lin[rec[srch(x)-jian]].PB(x);
                }
            }else{
                int temp=srch(lin.front().front());
                if(temp!=0&&lin.front().size()==1){
                    rec[temp-jian]=-1;
                    jian++;
                }
                cout<<lin.front().front()<<endl;
                if(lin.front().size()>0) lin.front().erase(lin.front().begin());
                if(lin.front().size()==0)lin.erase(lin.begin());
            }
            /*for(int i=0;i<lin.size();i++){
                for(int j=0;j<lin[i].size();j++) cout<<lin[i][j]<<" ";
                cout<<endl;
            }*/
        }
        cnt++;
        t--;
    }

}
