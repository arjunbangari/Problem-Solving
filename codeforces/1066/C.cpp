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
    
    ll q;
    cin>>q;

    ll l = 0, r = 0;
    
    map<ll,ll> mp;
    map<ll, ll> loc;
    
    while(q--){
        char ch;
        ll id;
        cin>>ch>>id;
        
        if(ch=='L'){
            loc[id] = 0;
            mp[id] = l;
            l++;
        } else if(ch=='R') {
            mp[id] = r;
            loc[id] = 1;
            r++;
        } else {
            ll ans;
            if(loc[id]){
                ll ans1 = r - mp[id] - 1;
                ll ans2 = l + mp[id];
                ans = min(ans1, ans2);
            } else {
                ll ans1 = l - mp[id] - 1;
                ll ans2 = r + mp[id];
                ans = min(ans1, ans2);
            }
            
            cout<<ans<<endl;
        }
        
    }
    
    return 0;
}