#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll next(ll i){
    ll count=0;
    while(i>0){
        i/=2;
        count++;
    }
    return 1<<count;
}

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll ans = 0;
    map<ll,ll> mp;
    sort(arr,arr+n);
    
    for(ll i=0;i<n;i++){
        ll val = next(arr[i]) - arr[i];
        ans += mp[val];
        mp[arr[i]]++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}