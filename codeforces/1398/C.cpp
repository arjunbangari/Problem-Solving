#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
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
        ll n;
        cin>>n;
        
        string s;
        cin>>s;
        
        vector<ll> arr(n);
        for(ll i=0;i<n;i++){
            ll x = s[i]-'0';
            arr[i] = x-1;
        }
        
        for(ll i=1;i<n;i++)
            arr[i] += arr[i-1];
        
        map<ll, ll> mp;
        
        ll ans = 0;
        
        for(ll i=0;i<n;i++){
            ans += mp[arr[i]];
            if(!arr[i])
                ans++;
            mp[arr[i]]++;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}