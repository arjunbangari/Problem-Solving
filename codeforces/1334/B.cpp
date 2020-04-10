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
        ll n,x;
        cin>>n>>x;
        
        vector<ll> arr(n);
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        
        ll ans = 0, sum = 0, i;
        
        sort(arr.rbegin(), arr.rend());
        
        for(i=0;i<n;i++){
            sum += arr[i];
            if(sum/(i+1)>=x)
                ans++;
            else
                break;
        }
        
        for(ll j=i;j<n;j++){
            if(arr[j]>=x)
                ans++;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}