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
        ll n,k;
        cin>>n>>k;
        
        vector<ll> divisors;
        
        for(ll i=1;i<=sqrt(n);i++){
            if(n%i==0){
                if(i==n/i)
                    divisors.push_back(i);
                else{
                    divisors.push_back(i);
                    divisors.push_back(n/i);
                }
            }
        }
        
        sort(divisors.begin(), divisors.end());
        
        ll ans = n + divisors[1] + 2*(k-1);
        
        cout<<ans<<endl;
    }
    
    return 0;
}