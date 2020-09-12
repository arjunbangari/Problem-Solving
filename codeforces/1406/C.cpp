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
ll n;
vector<ll> v[maxn], sz(maxn), dp(maxn);

void dfs(ll i, ll p =0){
    ll mx = 0;
    sz[i] = 1;
    for(auto u: v[i]){
        if(u==p)
            continue;
        dfs(u, i);
        sz[i] += sz[u];
        mx = max(mx, sz[u]);
    }
    
    mx = max(mx, n - sz[i]);
    dp[i] = mx;
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        cin>>n;
        
        for(ll i=0;i<=n;i++){
            v[i].clear();
            sz[i] = 0;
            dp[i] = 0;
        }
        
        for(ll i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        dfs(1);
        
        ll mn = *min_element(dp.begin()+1, dp.begin()+n+1);
        // cout<<mn<<endl;
        
        vector<ll> nodes;
        for(ll i=1;i<=n;i++){
            if(dp[i]==mn)
                nodes.push_back(i);
        }
        
        // for(auto u: nodes){
        //     cout<<u<<" ";
        // }
        // cout<<endl;
        
        ll sz = nodes.size();
        
        if(sz==1){
            cout<<v[nodes[0]][0]<<" "<<nodes[0]<<endl;
            cout<<v[nodes[0]][0]<<" "<<nodes[0]<<endl;
        } else {
            ll val;
            
            for(auto u: v[nodes[0]]){
                if(u!=nodes[1]){
                    val = u;
                    break;
                }
            }
            
            cout<<val<<" "<<nodes[0]<<endl;
            cout<<val<<" "<<nodes[1]<<endl;
        }
    }
    
    return 0;
}