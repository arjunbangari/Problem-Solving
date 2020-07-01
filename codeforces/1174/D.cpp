#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
    fast;
    
    ll n,x;
    cin>>n>>x;
    
    ll mx = binpow(2, n);
    
    vector<ll> brr, arr;
    
    map<ll, ll> mp;
    
    for(ll i=1;i<mx;i++){
        if(i==x)
            continue;
        if(!mp[i]){
            brr.push_back(i);
            mp[i^x] = 1;
            mp[i] = 1;
        }
    }
    
    if(!brr.empty())
        arr.push_back(brr[0]);
    ll sz = brr.size();
    
    for(ll i=1;i<sz;i++)
        arr.push_back(brr[i]^brr[i-1]);
    
    cout<<sz<<endl;
    for(auto u: arr)
        cout<<u<<" ";
    
    return 0;
}