#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n];
    cin>>arr[0];
    ll num = arr[0];
    
    for(ll i=1;i<n;i++){
        cin>>arr[i];
        num = __gcd(num, arr[i]);
    }
    
    ll ans = 0;
    
    for (ll i=1; i<=sqrt(num); i++) { 
        if (num%i == 0) { 
            if (num/i == i) 
                ans++;
            else 
                ans += 2; 
        } 
    }

    cout<<ans<<endl;
    
    return 0;
}