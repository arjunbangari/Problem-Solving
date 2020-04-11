#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n, ans=1e18;
        cin>>n;
        
        vector<ll> health(n), damage(n);
        for(ll i=0;i<n;i++)
            cin>>health[i]>>damage[i];
        
        ll arr[n], sum=0;
        for(ll i=0;i<n;i++){
            ll j = (i+1)%n;
            arr[j] = max(0LL,health[j] - damage[i]);
            sum += arr[j];
        }
        
        for(ll i=0;i<n;i++){
            ll temp = sum - arr[i] + health[i];
            ans = min(ans, temp);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}