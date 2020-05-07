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
        ll n;
        cin>>n;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        set<ll> s;
        
        for(ll i=0;i<n;i++){
            ll temp = i + arr[i]%n;
            temp = (temp + n)%n;
            s.insert(temp);
        }
        
        ll sz = s.size();
        
        cout<< (sz==n ? "YES": "NO") <<endl;
    }
    
    return 0;
}