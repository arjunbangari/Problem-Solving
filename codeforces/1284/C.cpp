#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    vector<ll> fact(n+5, 1);
    
    for(ll i=2;i<n+5;i++)
        fact[i] = (i*fact[i-1])%m;
    
    ll ans = 0;
    
    for(ll i=0;i<n;i++){
        ll tmp = (fact[n-i]*fact[i+1])%m;
        tmp = ( tmp *(n-i))%m;
        ans = ( ans + tmp )%m;
    }
    
    cout<<ans<<endl;
    
    return 0;
}