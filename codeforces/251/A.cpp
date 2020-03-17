#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n, d;
    cin>>n>>d;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll ans = 0;
    ll l=0, r=1;
    
    while(l<n){
        while(r<n && arr[r]<=(arr[l]+d))
            r++;
        ans += ((r-l-1)*(r-l-2))/2;
        l++;
    }
    cout<<ans<<endl;
    return 0;
}