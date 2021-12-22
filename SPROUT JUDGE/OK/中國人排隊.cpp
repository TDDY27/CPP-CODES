#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;
int n,m,k;
deque <int> dq[1000];
stack <int> stk;
/*
0 : (0) 1 2 3 ...k-1
1 : k k+1 k+2 ... 2k-1
2 :2k 2k+1 2k+2 ... 3k-1
.
.
.
n : nk nk+1 nk+2 ... nk-1
*/
void add(int pos,int val){
    int out=pos%k;
    for(int i=0;i<out;i++) {
        stk.push(dq[pos/k].front());
        dq[pos/k].pop_front();
    }
    dq[pos/k].push_front(val);
    for(int i=0;i<out;i++){
        dq[pos/k].push_front(stk.top());
        stk.pop();
    }
    for(int i=pos/k;i<=n/k;i++){
        if(dq[i].size()<=k) break;
        dq[i+1].push_front(dq[i].back());
        dq[i].pop_back();
    }
    n++;//must refresh
}
void leave(int pos){
    int out=pos%k;
    for(int i=0;i<out;i++) {
        stk.push(dq[pos/k].front());
        dq[pos/k].pop_front();
    }
    dq[pos/k].pop_front();
    for(int i=0;i<out;i++){
        dq[pos/k].push_front(stk.top());
        stk.pop();
    }
    for(int i=pos/k;i<=n/k;i++){
        if(dq[i+1].size()<=0) break;
        dq[i].push_back(dq[i+1].front());
        dq[i+1].pop_front();
    }
    n--;//must refresh
}
void qry(int pos){
    cout<<dq[pos/k][pos%k]<<endl;
}

signed main(){
    TDDY
    cin>>n>>m;
    k=sqrt(n);
    dq[0].push_front(0);
    for(int i=1;i<=n;i++) {
        int temp;
        cin>>temp;
        dq[i/k].push_back(temp);
    }
    for(int i=0;i<m;i++){
        string  qst;
        cin>>qst;
        int pos;
        if(qst=="ADD"){
            int val;
            cin>>pos>>val;
            add(pos,val);
        }else if(qst=="LEAVE"){
            cin>>pos;
            leave(pos);
        }else if(qst=="QUERY"){
            cin>>pos;
            qry(pos);
        }
    }
}
