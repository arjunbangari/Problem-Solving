#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
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
        ll n,x;
        cin>>n>>x;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        ll even = 0, odd = 0, sum = 0;
        
        for(ll i=0;i<n;i++){
            if(arr[i]%2)
                odd++;
            else
                even++;
            sum += arr[i];
        }
        
        if(x==n){
            cout<< (sum%2 ? "Yes" : "No") <<endl;
            continue;
        }
        
        string ans;
        
        if(x%2==0){
            if(odd>0 && even>0)
                ans = "Yes";
            else
                ans = "No";
        } else {
            if(odd>0)
                ans = "Yes";
            else
                ans = "No";
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}