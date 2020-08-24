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
    
    ll n, k;
    cin>>n>>k;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    vector<ll> dp(k+1);
    
    for(ll i=0;i<=k;i++){
        for(auto u: arr){
            if( i>=u && !dp[i-u] )
                dp[i] = 1;
        }
    }
    
    cout<< ( dp[k] ? "First" : "Second" ) <<endl;
    
    return 0;
}