#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n], brr[n];
    
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    for(ll i=0;i<n;i++)
        cin>>brr[i];
    
    ll ab[n], ba[n];
    for(ll i=0;i<n;i++){
        ab[i] = arr[i] - brr[i];
        ba[i] = brr[i] - arr[i];
    }

    sort(ba,ba+n);
    
    ll ans = 0;
    
    for(ll i=0;i<n;i++){
        ll val = ab[i];
        auto temp = upper_bound(ba,ba+n,val-1) - ba;
        if(ab[i]>0)
            temp--;
        ans += temp;
    }
    
    cout<<ans/2<<endl;
    
    return 0;
}