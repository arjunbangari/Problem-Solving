#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 998244353;

// code begins here
ll n,m, flag=0, a=0, b=0, cnt=0;
vector<ll> v[maxn], vis(maxn), color(maxn);

void dfs(ll i, ll c=0){
    vis[i] = 1;
    color[i] = c;
    a += c;
    b += !c;
    cnt++;
    for(auto u: v[i]){
        if(vis[u]){
            if(color[u]==color[i])
                flag = 1;
            continue;
        }
        dfs(u, !c);
    }
}

ll binpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        cin>>n>>m;
        
        for(ll i=1;i<=n;i++){
            v[i].clear();
            vis[i] = 0;
        }
        flag = 0;
        
        for(ll i=0;i<m;i++){
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        ll ans = 1;
        
        for(ll i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i);
                ll temp;
                if(cnt==0)
                    temp = 3;
                else 
                    temp = (binpow(2,a) + binpow(2,b))%mod;
                
                ans = (ans*temp)%mod;
                
                a = 0; b = 0; cnt = 0;
            }
        }
        
        if(flag){
            cout<<0<<endl;
            continue;
        }
        
        cout<<ans%mod<<endl;
        
    }
    
    return 0;
}