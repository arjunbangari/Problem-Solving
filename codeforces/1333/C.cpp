#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    for(ll i=1;i<n;i++)
        arr[i]+=arr[i-1];
    
    map<ll,ll> mp;
    mp[0] = -1;
    ll last=-1, ans=0;
    
    for(ll i=0;i<n;i++){
        if(mp.find(arr[i])!=mp.end())
            last = max(last, mp[arr[i]]+1);
        //cout<<i<<" "<<last<<endl;
        ans += max(i - last, 0LL);
        mp[arr[i]] = i;
    }
    
    cout<<ans<<endl;
    
    return 0;
}