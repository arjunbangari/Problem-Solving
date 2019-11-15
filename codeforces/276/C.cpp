#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll n,q;
    cin>>n>>q;
    ll arr[n];
    ll count[n] = {0};
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    while(q--){
        ll l,r;
        cin>>l>>r;
        count[l-1]++;
        if(r<n)
            count[r]--;
    }
    
    for(ll i=1;i<n;i++)
        count[i]+=count[i-1];
        
    sort(arr,arr+n);
    sort(count, count+n);
    
    ll ans = 0;
    for(ll i=0;i<n;i++)
        ans += arr[i]*count[i];
    
    cout<<ans<<"\n";
    return 0;
}
