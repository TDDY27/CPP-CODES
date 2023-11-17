#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int const maxn=2e5;

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


int main(){
    int t;
    cin>>t;
    Stk stk;
    while(t>0){
        int q;
        cin>>q;
        if(q==1){
            int n;
            cin>>n;
            stk.push(n);
        }else{
            if(stk.Size()==0){
                cout<<"empty!"<<endl;
                t--;
                continue;
            }
            cout<<stk.top()<<endl;
            stk.pop();
        }

        t--;
    }

}
