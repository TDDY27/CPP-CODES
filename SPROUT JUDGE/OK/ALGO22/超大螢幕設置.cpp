#include <bits/stdc++.h>
#define int long long
#define PB push_back
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int n;
priority_queue<int, vector<int>,less <int> >prior;

struct rec{
    int hei;
    int pos;
};
stack <rec> stk;

signed main(){
    TDDY
    cin>>n;

    int now=0;
    rec temp;
    for(int i=0;i<n;i++){
        cin>>temp.hei;
        temp.pos=now;
        int flag=1;
        while(stk.size()>0){
            if(temp.hei>stk.top().hei) break;
            else if(temp.hei==stk.top().hei){
                prior.push( temp.hei*(now-stk.top().pos+1) );
                flag=0;
                break;
            }else{
                prior.push( stk.top().hei*(now-stk.top().pos) );
                temp.pos=stk.top().pos;
                stk.pop();
            }
        }
        if(flag==1)stk.push(temp);
        now++;
    }

    while(stk.size()>0){
        prior.push( stk.top().hei*(now-stk.top().pos) );
        stk.pop();
    }

    cout<<prior.top()<<endl;
}
