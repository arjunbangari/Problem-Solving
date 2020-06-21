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
        ll n, x;
        cin>>n;
        
        ll e = 0 ,o=0;
        vector<ll> even, odd;
        
        for(ll i=0;i<2*n;i++){
            cin>>x;
            if(x%2){
                o++;
                odd.push_back(i+1);
            } else {
                e++;
                even.push_back(i+1);
            }
        }
        
        vector<pll> ans;
        
        for(ll i=0;i<e-1;i+=2)
            ans.push_back({even[i], even[i+1]});
        
        for(ll i=0;i<o-1;i+=2)
            ans.push_back({odd[i], odd[i+1]});
        
        for(ll i=0;i<n-1;i++)
            cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    
    return 0;
}