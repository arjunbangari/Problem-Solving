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
    
    ll n,m,d;
    cin>>n>>m>>d;
    
    vector<ll> arr(n), ans(n);
    map<ll,ll> mp;
    multiset<ll> ms;
    
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        mp[arr[i]] = i;
        ms.insert(arr[i]);
    }

    ll cur_day = 0;
    
    while(!ms.empty()){
        cur_day++;
        ll last = 0;
        while(1){
            auto it = ms.lower_bound(last);
            if(it==ms.end())
                break;
            
            ll val = *it;
            ans[mp[val]] = cur_day;
            ms.erase(it);
            
            last = val+d+1;
        }
    }    
    
    cout<<cur_day<<endl;
    for(auto u: ans)
        cout<<u<<" ";
    
    return 0;
}