#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 998244353;

// code begins here

int main(){
    fast;
    
    ll n, sum=0;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    map<ll,ll> mp;
    for(auto u: arr){
        mp[u]++;
        sum += u;
    }
    
    ll q;
    cin>>q;
    
    while(q--){
        ll b,c;
        cin>>b>>c;
        
        sum += mp[b]*(c-b);
        mp[c] += mp[b];
        mp[b] = 0;
        
        cout<<sum<<endl;
    }
    
    return 0;
}