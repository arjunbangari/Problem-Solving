#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 1e5+5;
ll const mod = 1e9+7;
 
// code begins here
vector<ll> divi[maxn];

void compute(ll i){
    for(ll j=2;j<=sqrt(i);j++){
        if(i%j==0){
            divi[i].push_back(j);
            if(j!=i/j)
                divi[i].push_back(i/j);
        }
    }
}

int main(){
    fast;
    
    ll n, ans = 1;
    cin>>n;
    
    vector<ll> arr(n), dp(maxn);
    for(auto &u: arr)
        cin>>u;
    
    sort(arr.begin(), arr.end());
    
    for(auto u: arr){
        compute(u);
        for(auto v: divi[u])
            dp[u] = max(dp[u], dp[v]);
        dp[u]++;
        ans = max(dp[u], ans);
        for(auto v: divi[u])
            dp[v] = dp[u];
    }
    
    cout<<ans<<endl;
    
    return 0;
}