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
    
    string s, t;
    cin>>s>>t;
    
    ll n = s.length();
    ll m = t.length();
    
    ll ans = inf;
    
    for(ll i=0;i<=n-m;i++){
        ll cnt = 0;
        for(ll j=0;j<m;j++){
            if(s[i+j]!=t[j])
                cnt++;
        }
        
        ans = min(ans , cnt);
    }
    
    cout<<ans<<endl;
    
    return 0;
}