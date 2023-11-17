#include <bits/stdc++.h>
#include <vector>
#include <cstring>
#define TDDY ::ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define PB push_back
using namespace std;
int const maxn=1200;

struct ptr{
    int fmr;
    int ltr;
    int ths;
};

int t,n,m;
vector <int> v[maxn];
vector <ptr> ll;

int srch(int ind){
    for(int i=1;i<=n;i++){
        for(int j:v[i]){
            if(ind==j) return i;
        }
    }
    return -1;
}

int main(){
    TDDY
    cin>>t;
    int cnt=1;

    while(t>0){
        for(int i=0;i<maxn;i++) v[i].clear();
        ll.clear();

        cout<<"Line #"<<cnt<<endl;
        cin>>n;
        int num,k;
        for(int i=1;i<=n;i++){
            cin>>num;
            for(int j=0;j<num;j++){
                cin>>k;
                v[i].PB(k);
            }
        }

        cin>>m;
        string q;
        int mmin[n+50];
        memset(mmin,-1,sizeof(mmin));
        int frnt=0,bck=0,x,grp;

        cin>>q>>x;
        ptr temp;
        temp.ths=x;temp.fmr=-1;temp.ltr=-1;
        ll.PB(temp);
        frnt=ll.size()-1;
        bck=ll.size()-1;
        if(srch(x)!=-1) mmin[srch(x)]=0;
        //cout<<ll[ll.size()-1].fmr<<" "<<ll[ll.size()-1].ths<<" "<<ll[ll.size()-1].ltr<<endl;

        for(int i=0;i<m-1;i++){
            cin>>q;
            if(q=="ENQUEUE"){
                cin>>x;
                grp=srch(x);
                if(grp==-1 || mmin[grp]==-1){
                    ll[bck].ltr=ll.size();
                    temp.fmr=bck;
                    temp.ths=x;
                    temp.ltr=-1;
                    ll.PB(temp);
                    bck=ll.size()-1;
                    if(mmin[grp]==-1){
                        mmin[grp]=ll.size()-1;
                    }
                }else{
                    temp.fmr=mmin[grp];
                    temp.ths=x;
                    temp.ltr=ll[mmin[grp]].ltr;
                    ll[mmin[grp]].ltr=ll.size();
                    mmin[grp]=ll.size();
                    ll.PB(temp);
                }
            }else{
                cout<<ll[frnt].ths<<endl;
                frnt=ll[frnt].ltr;
            }
            //cout<<ll[ll.size()-1].fmr<<" "<<ll[ll.size()-1].ths<<" "<<ll[ll.size()-1].ltr<<endl;
        }
        t--;
        cnt++;
    }
    return 0;
}
