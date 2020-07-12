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
        ll n,x;
        cin>>n>>x;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        sort(arr.rbegin(), arr.rend());
        
        ll ans = 0, i = 0;
        while(i<n){
            ll j = i, cnt = 1;
            while(j<n && (arr[j]*cnt)<x){
                j++;
                cnt++;
            }
            if(j!=n)
                ans++;
            i = j+1;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}