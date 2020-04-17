#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        
        ll n,k;
        cin>>n>>k;
        
        string s;
        cin>>s;
        
        ll ans = 0;
        ll temp = n/k;
        
        for(ll i=0;i<k/2;i++){
            map<char,ll> mp;
            
            for(ll j=i;j<n;j+=k)
                mp[s[j]]++;

            for(ll j=k-i-1;j<n;j+=k)
                mp[s[j]]++;
            
            ll mx = -1;
            for(auto u: mp)
                mx = max(mx, u.second);
            
            ans += (2*temp - mx);
        }
        
        if(k%2){
            map<char,ll> mp;
            for(ll i=k/2;i<n;i+=k)
                mp[s[i]]++;
            
            ll mx = -1;
            for(auto u: mp)
                mx = max(mx, u.second);
            
            ans += (temp - mx);
            
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}