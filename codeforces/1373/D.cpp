#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;
 
// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        ll ans1 = 0, ans2 = 0, sum = 0;
        
        for(ll i=1;i<n;i+=2){
            sum += arr[i]-arr[i-1];
            if(sum<0)
                sum = 0;
            ans1 = max(ans1, sum);
        }
        
        sum = 0;
        for(ll i=1;i<n-1;i+=2){
            sum += arr[i]-arr[i+1];
            if(sum<0)
                sum = 0;
            ans2 = max(ans2, sum);
        }
        
        sum = 0;
        for(ll i=0;i<n;i+=2)
            sum += arr[i];
        
        sum += max(ans1, ans2);
        
        cout<<sum<<endl;
        
    }
    
    return 0;
}