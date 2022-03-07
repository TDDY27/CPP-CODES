#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int const maxn=2e5;

struct Que{
    int head,tail,a[maxn];
    Que(): head(0),tail(0) {}
    int frnt(){
        return a[head];
    }
    void push(int ind){
        a[tail++]=ind;
        if(tail==maxn) tail=0;
    }
    void pop(){
        head++;
        if(head==maxn)head=0;
    }
    int Size(){
        return (tail-head+maxn)%maxn;
    }
} ;

int main(){
    TDDY
    int t;
    cin>>t;
    Que que;
    while(t>0){
        int q;
        cin>>q;
        if(q==1){
            int n;
            cin>>n;
            que.push(n);
        }else{
            if(que.Size()==0){
                cout<<"empty!"<<endl;
                t--;
                continue;
            }
            cout<<que.frnt()<<endl;
            que.pop();
        }
        t--;
    }
}
