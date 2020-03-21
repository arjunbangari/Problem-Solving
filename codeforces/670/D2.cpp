#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,k;
    cin>>n>>k;
    
    ll arr[n],brr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
        
    for(ll i=0;i<n;i++)
        cin>>brr[i];
    
    ll l=0, r = 2e9;
    
    while(l<r){
        ll mid = (l+r+1)/2;
        ll extra = 0;
        
        for(ll i=0;i<n;i++){
            ll required = arr[i]*mid;
            if(required>brr[i])
                extra += (required-brr[i]);
            if(extra>k)
                break;
        }
        
        if(extra<=k)
            l = mid;
        else
            r = mid-1;
    }
    
    cout<<l<<endl;
    
    return 0;
}