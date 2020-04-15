#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll cost[n+1];
    for(ll i=1;i<=n;i++)
        cin>>cost[i];
    
    ll next_house[n+1];
    for(ll i=1;i<=n;i++)
        cin>>next_house[i];
    
    ll ans = 0, t=0;
    ll vis[n+1] = {0};
    map<ll,ll> mp;
    
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            t++;
            ll j = i, val=-1;
            vector<ll> v;
            
            while(1){
                if(!vis[j])
                    vis[j] = t;
                else{
                    if(vis[j]==t)
                        val = j;
                    break;
                }
                j = next_house[j];
            }
            
            if(val==-1)
                continue;
            else{
                ll mn = cost[val];
                j = next_house[val];
                v.push_back(val);
                while(j!=val){
                    mn = min(mn, cost[j]);
                    j = next_house[j];
                }
                
                ans += mn;
                for(auto u: v)
                    mp[u] = mn;
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}