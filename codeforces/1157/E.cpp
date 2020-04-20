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
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n), brr(n);
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    for(ll i=0;i<n;i++)
        cin>>brr[i];
        
    multiset<ll> ms;
    for(ll i=0;i<n;i++)
        ms.insert(brr[i]);
    
    vector<ll> ans(n);
    
    for(ll i=0;i<n;i++){
        auto itr = ms.lower_bound(n - arr[i]);
        if(itr==ms.end())
            itr--;
        auto itr2 = ms.begin();
        
        ll x = (arr[i] + *itr)%n;
        ll y = (arr[i] + *itr2)%n;
        
        if(x<y){
            ans[i] = x;
            ms.erase(itr);
        } else {
            ans[i] = y;
            ms.erase(itr2);
        }
    }
    
    for(ll i=0;i<n;i++)
        cout<<ans[i]<<" ";
    
    return 0;
}