#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int const maxn=2e5;
int ide[maxn];

struct Stk{
    int head,a[maxn];
    Stk(): head(0) {}
    int top(){
        return a[head-1];
    }
    void push(int ind){
        a[head++]=ind;
    }
    void pop(){
        head--;
    }
    int Size(){
        return head;
    }
};

struct Que{
    int head,tail,a[maxn];
    Que(): head(0),tail(0){}
    int frnt(){
        return a[head];
    }
    void push(int ind){
        a[tail++]=ind;
        if(tail==maxn) tail=0;
    }
    void pop(){
        head++;
        if(head==maxn) head=0;
    }
    int Size(){
        return (tail-head+maxn)%maxn;
    }
};

signed main(){
    TDDY
    int t,n;
    cin>>t;
    while(t>0){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>ide[i];
        Stk stk;
        Que que;
        for(int i=1;i<=n;i++) que.push(i);
        int flag=1;
        int now=1;
        while(now<=n){
            if(que.Size()!=0 && que.frnt()==ide[now]){
                que.pop();
                now++;
            }else if(stk.Size()!= 0 && stk.top()==ide[now]){
                stk.pop();
                now++;
            }else{
                stk.push(que.frnt());
                que.pop();
            }
            if(stk.Size()!=0 && stk.top()!=ide[now] && que.Size()==0){
                flag=0;
                break;
            }
            //cout<<stk.top()<<" "<<que.frnt()<<endl;
        }
        if(flag==0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;

        t--;
    }
    return 0;
}
