#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long

using namespace std;

struct info{
  int x;
  int y;
};

int n;

int operator ^ ( info const &a, info const &b){
  return a.x*b.y-a.y*b.x;
}

info operator - ( info const &a, info const &b){
  info tmp; tmp.x=a.x-b.x, tmp.y=a.y-b.y;
  return tmp;
}

int operator * ( info const &a, info const &b){
  return a.x*b.x+a.y*b.y;
}

int ori(const info &o, const info &a, const info &b){
  int cross=(a-o)^(b-o);
  if(cross>0) return 1;
  else if(cross==0) return 0;
  else return -1;
}

bool btw(info const &a, info const &b, info const &c){
  if(ori(a,b,c)!=0 ) return 0;
  return (a-c)*(b-c)<=0;
}

bool banana( const info &p1, const info &p2, const info &p3, const info &p4){
  int a123=ori(p1,p2,p3);
  int a124=ori(p1,p2,p4);
  int a341=ori(p3,p4,p1);
  int a342=ori(p3,p4,p2);
  
  if(a123==0 && a124==0)
    return btw(p1,p2,p3) || btw(p1,p2,p4) || btw(p3,p4,p1) || btw(p3,p4,p2) ;
  return a123*a124<=0 && a341*a342<=0;
}

signed main(){
  cin>>n;
  info p1,p2,q1,q2;
  for(int i=0;i<n;i++){
    cin>>p1.x>>p1.y>>p2.x>>p2.y>>q1.x>>q1.y>>q2.x>>q2.y;
    int ans=banana(p1,p2,q1,q2);
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }

}
