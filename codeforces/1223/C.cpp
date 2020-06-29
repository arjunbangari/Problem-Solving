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
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> prices(n+1);
        for(ll i=1;i<=n;i++)
            cin>>prices[i];
            
        prices[0] = inf;
        sort(prices.rbegin(), prices.rend());
        prices[0] = 0;
        for(ll i=1;i<=n;i++)
            prices[i] += prices[i-1];
        
        ll x,a,y,b,k;
        cin>>x>>a>>y>>b>>k;
        
        ll l = 1, r = n, ans = -1;
        
        if(x<y){
            swap(x,y);
            swap(a,b);
        }
        
        while(l<=r){
            ll mid = (l+r)/2;
            
            ll lc = lcm(a,b);
            ll both = mid/lc;
            ll oa = mid/a - both;
            ll ob = mid/b - both;
            
            ll profit = 0;
            profit += (x+y)*(prices[both])/100;
            profit += x*(prices[both+oa] - prices[both])/100;
            profit += y*(prices[both+oa+ob] - prices[both+oa])/100;
            
            if(profit>=k){
                ans = mid;
                r = mid-1;
            } else 
                l = mid + 1;
        }
        
        cout<< ans<<endl;
    }
    
    return 0;
}