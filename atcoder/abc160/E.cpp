#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    
    vector<ll> arr(a), brr(b), crr(c);
    for(ll i=0;i<a;i++)
        cin>>arr[i];
    for(ll i=0;i<b;i++)
        cin>>brr[i];
    for(ll i=0;i<c;i++)
        cin>>crr[i];
    
    sort(arr.rbegin(), arr.rend());
    sort(brr.rbegin(), brr.rend());
    sort(crr.rbegin(), crr.rend());
    
    vector<ll> final;
    for(ll i=0;i<x;i++)
        final.push_back(arr[i]);
    for(ll i=0;i<y;i++)
        final.push_back(brr[i]);
    for(ll i=0;i<min(x+y,c);i++)
        final.push_back(crr[i]);
    
    sort(final.rbegin(), final.rend());
    
    ll ans = 0;
    for(ll i=0;i<x+y;i++)
        ans += final[i];
    
    cout<<ans<<endl;
    
    return 0;
}