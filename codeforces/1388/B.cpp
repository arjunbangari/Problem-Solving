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
        
        vector<ll> ans(n);
        for(ll i=0;i<n;i++)
            ans[i] = 9;
        
        if(n%4==0){
            ll x = n/4;
            for(ll i=n-1;i>n-1-x;i--){
                ans[i] = 8;
            }
        } else {
                ll x = n/4;
                for(ll i=n-1;i>=n-1-x;i--){
                    ans[i] = 8;
                 }
        }
        
        for(ll i=0;i<n;i++)
            cout<<ans[i];
        cout<<endl;
    }
    
    return 0;
}