#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll id[500005],sz[500005];

void initialise(ll n){
    for(ll i=0;i<=n;i++){
        id[i] = i;
        sz[i] = 1;
   }
}

ll root(ll i){
    while(i!=id[i]){
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void connect(ll p, ll q){
    ll proot = root(p);
    ll qroot = root(q);
    if(proot==qroot)
        return;
    if(sz[proot]>sz[qroot]){
        id[qroot] = proot;
        sz[proot] += sz[qroot];
    } else {
        id[proot] = qroot;
        sz[qroot] += sz[proot];
    }
}

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    
    initialise(n);

    while(m--){
        ll k, first,temp;
        cin>>k;
        if(k==1)
            cin>>first;
        if(k>1){
            cin>>first;
            
            for(ll i=1;i<k;i++){
                cin>>temp;
                connect(first,temp);
            }
        }
    }
    
    for(ll i=1;i<=n;i++){
        ll iroot = root(i);
        cout<<sz[iroot]<<" ";
    }
    
    return 0;
}