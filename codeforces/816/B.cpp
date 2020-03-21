#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll k, sz=200005;
vector<ll> arr(sz,0), t(4*sz);

void build_tree(ll v, ll tl, ll tr){
    if(tl==tr)
        t[v] = ( arr[tl]>=k ? 1 : 0 );
    else{
        ll tm = (tl+tr)/2;
        build_tree(2*v, tl, tm);
        build_tree(2*v+1, tm+1, tr);
        t[v] = t[2*v] + t[2*v+1];
    }
}

ll queries(ll v, ll tl, ll tr, ll l, ll r){
    if(l>r)
        return 0;
    if(l==tl && r==tr)
        return t[v];
    else{
        ll tm = (tl+tr)/2;
        ll ans = queries(2*v, tl, tm, l, min(r,tm)) 
                 + queries(2*v+1, tm+1, tr, max(l,tm+1), r);
        return ans;
    }
}

int main(){
    fast;
    
    ll n,q,l,r;
    cin>>n>>k>>q;
    
    for(ll i=0;i<n;i++){
        cin>>l>>r;
        arr[l]++;
        arr[r+1]--;
    }
    
    for(ll i=1;i<=sz;i++)
        arr[i] += arr[i-1];
    
    build_tree(1, 1, sz);
    
    while(q--){
        cin>>l>>r;
        ll ans = queries(1, 1, sz, l, r);
        cout<<ans<<endl;
    }
    
    
    return 0;
}