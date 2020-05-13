#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m,u,v;
    cin>>n>>m;
    
    vector<ll> p(n);
    
    for(auto &u: p)
        cin>>u;
    
    map<ll,ll> swap_with_nastya;
    
    vector<ll> can_swap[n+1];
    
    for(ll i=0;i<m;i++){
        cin>>u>>v;
        if(v==p[n-1])
            swap_with_nastya[u] = 1;
        can_swap[u].push_back(v);   
    }
    
    unordered_set<ll> us;
    ll ans=0, cnt=0;
    
    for(ll i=n-2;i>=0;i--){
        if(swap_with_nastya[p[i]]){
            
            ll total=0;
            
            for(auto u: can_swap[p[i]])
                if(us.find(u)!=us.end())
                    total++;
            
            if(total==cnt){
                ans++;
                continue;
            }
        
        } 
        us.insert(p[i]);
        cnt++;
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}