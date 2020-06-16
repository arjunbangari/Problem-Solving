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

int main(){
    fast;

    ll n, m;
    cin>>n>>m;
    
    vector<set<ll>> v(m);
    
    for(ll i=0;i<n;i++){
        string s;
        cin>>s;
        
        for(ll j=0;j<m;j++)
            v[j].insert(s[j]);
    }
    
    ll ans = 1;
    for(auto u: v){
        ll sz = u.size();
        ans = (ans*sz)%mod;
    }
    
    cout<<ans%mod<<endl;
    
    return 0;
}
