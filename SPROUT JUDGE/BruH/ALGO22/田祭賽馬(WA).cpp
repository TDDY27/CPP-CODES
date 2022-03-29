#include <bits/stdc++.h>
#define TDDY ::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
#define PB push_back

using namespace std;

int t,n,k,a,b,c;
int const maxn=1e4+500;
int my[maxn];
int temp[maxn];
int grow[maxn];
int op[maxn];

signed main(){
    TDDY
	cin>>t;
	while(t>0){
		memset(my,0,sizeof(my));
		memset(grow,0,sizeof(grow));
		memset(op,0,sizeof(op));

		cin>>n>>k;
		for(int i=0;i<n;i++) cin>>my[i]>>grow[i];
		for(int i=0;i<n;i++) cin>>op[i];
		sort(my,my+n);
		sort(op,op+n);

		int flag=1;
		for(int i=0;i<k;i++){
            if(my[n-1-i]<=op[k-1-i]){
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout<<0<<endl;
            t--;
            continue;
        }

		int l,r,mid;
		l=0;
		r=1e8;
		mid=(l+r)/2;
		int win=0;
		while(r-l>1){
			for(int i=0;i<n;i++) temp[i]=my[i]+mid*grow[i];
			sort(temp,temp+n);
			flag=1;
			for(int i=0;i<k;i++){
				if(temp[n-1-i]<=op[k-1-i]){
					flag=0;
					break;
				}
			}
			if(flag==1){ r=mid; win=1;}
			else l=mid;
			mid=(l+r)/2;
		}

		if(win==0) cout<<-1<<endl;
		else cout<<r<<endl;
		t--;
	}
}
