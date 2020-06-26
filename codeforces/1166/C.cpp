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

ll solve(vector<ll> brr){
    sort(brr.begin(), brr.end());
    
    ll sz = brr.size();
    ll ans = 0;
    
    for(ll i=1;i<sz;i++){
        ll l = 0, r = i-1, ind = i;
        while(l<=r){
            ll mid = (l+r)/2;
            ll x = abs(brr[i]-brr[mid]);
            ll y = abs(brr[i]+brr[mid]);
            if(x<=brr[mid] && y>=brr[i]){
                ind = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        ans += i-ind;
    }
    return ans;
    
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    vector<ll> brr;
    for(auto &u: arr){
        if(u!=0)
            brr.push_back(abs(u));
    }
    
    ll ans = solve(brr);
    
    cout<<ans<<endl;
    
    return 0;
}