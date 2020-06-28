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
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> power(n);
        for(auto &u: power)
            cin>>u;
            
        ll m;
        cin>>m;
        
        vector<pll> heroes(m);
        for(ll i=0;i<m;i++)
            cin>>heroes[i].first>>heroes[i].second;
        
        sort(heroes.begin(), heroes.end());
        
        ll max_power = *max_element(power.begin(), power.end());
        
        if(heroes[m-1].first<max_power){
            cout<<-1<<endl;
            continue;
        }
        
        vector<ll> mx(m);
        mx[m-1] = heroes[m-1].second;
        
        for(ll i=m-2;i>=0;i--)
            mx[i] = max(mx[i+1], heroes[i].second);
        
        ll i = 0, ans = 0;
        while(i<n){
            ll j = i+1, tmp = power[i];
            while(j<n){
                tmp = max(tmp, power[j]);
                pll x = {tmp, 0};
                auto it = lower_bound(heroes.begin(), heroes.end(),x) - heroes.begin();
                if(it==m)
                    break;
                
                if(mx[it]>=(j-i+1))
                    j++;
                else
                    break;
            }
            ans++;
            i = j;
        }
        
        cout<<ans<<endl;
    
    }
    return 0;
}