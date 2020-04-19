#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    map<ll,ll> mp;
    for(ll i=0;i<n;i++)
        mp[arr[i]]++;
    
    sort(arr, arr + n);
    
    unordered_set<ll> vis;
    
    ll ans = 0;
    
    if(k==1){
        ans = (ll)mp.size();
    }
    else {
    
        for(ll i=0;i<n;i++){
            if(vis.find(arr[i])==vis.end()){
                vector<ll> v;
                ll num = arr[i];
                while(1){
                    if(mp.find(num)!=mp.end()){
                        v.push_back(mp[num]);
                        vis.insert(num);
                        num *= k;
                    } else 
                        break;
                }
                ll mx1 = 0, mx2 = 0;
                ll sz = v.size();
                for(ll j=0;j<sz;j+=2)
                    mx1 += v[j];
                for(ll j=1;j<sz;j+=2)
                    mx2 += v[j];
                ans += max(mx1, mx2);
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}