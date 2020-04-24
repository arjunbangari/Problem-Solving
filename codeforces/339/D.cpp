#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

// code begins here

vector<ll> arr(maxn), t(maxn);

void build( ll v, ll tl, ll tr, ll decide) {
    if (tl == tr) {
        t[v] = arr[tl];
    } else {
        ll tm = (tl + tr) / 2;
        build( v*2, tl, tm, !decide );
        build( v*2+1, tm+1, tr, !decide );
        
        if(decide)
            t[v] = t[v*2] | t[v*2+1];
        else
            t[v] = t[v*2] ^ t[v*2+1];
    }
}

void update( ll v, ll tl, ll tr, ll pos, ll new_val, ll decide) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        ll tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val, !decide);
        else
            update(v*2+1, tm+1, tr, pos, new_val, !decide);
            
        if(decide)
            t[v] = t[v*2] | t[v*2+1];
        else
            t[v] = t[v*2] ^ t[v*2+1];
    }
}

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    ll total = binpow(2,n);
    
    for(ll i=0;i<total;i++)
        cin>>arr[i];
    
    build(1, 0, total-1, n%2 );
    
    while(m--){
        ll p,b;
        cin>>p>>b;
        
        update(1, 0, total-1, p-1, b, n%2);
        
        // for(ll i=1;i<8;i++)
        //     cout<<t[i]<<" ";
        // cout<<endl;
        
        cout<<t[1]<<endl;
    }
    
    return 0;
}