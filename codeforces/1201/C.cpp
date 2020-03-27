#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    sort(arr,arr+n);
    
    ll l=arr[n/2], r = 1e10, ans=l;
    
    while(l<=r){
        ll median = (l+r)/2;
        ll operations = 0;
        for(ll i=n/2;i<n;i++)
            operations += max(0LL, median - arr[i]);
        
        if(operations<=k){
            ans = median;
            l = median + 1;
        } else {
            r = median - 1;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}