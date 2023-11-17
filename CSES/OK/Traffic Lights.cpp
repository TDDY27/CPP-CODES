#include <bits/stdc++.h>

using namespace std;

set <int> rd;
multiset <int> dis;

signed main(){
    int x,n,p,r,l;
    cin>>x>>n;
    rd.insert(0);
    rd.insert(x);
    dis.insert(x);
    for(int i=0;i<n;i++){
        cin>>p;
        auto tmp=rd.upper_bound(p);
        r= *tmp;
        l= *--tmp;
        dis.erase(dis.find(r-l));
        dis.insert(r-p);
        dis.insert(p-l);
        rd.insert(p);
        cout<<*--dis.end()<<" ";
        /* set.end() point to the "past-the-end" element,
        The past-the-end element is the theoretical element t
        hat would follow the last element in the set container.
        It does not point to any element, and thus shall not be dereferenced.*/
    }

}
