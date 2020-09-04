#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,s;
        cin>>n>>s;
        
        ll insum = 0;
        ll x = n;
        while(x>0){
            insum += x%10;
            x /= 10;
        }
        
        if(insum<=s){
            cout<<0<<endl;
            continue;
        }
        
        ll ans = inf;
        ll prod = 1;
        
        x = n;
        while(x>0){
            ll rem = x%10;
            if(rem!=9){
                x++;
                ll y = x;
                ll tmp_sum = 0;
                
                while(y>0){
                    tmp_sum += y%10;;
                    y /= 10;
                }
                
                if((s-tmp_sum)>=0){
                    ll val = x*prod;
                    ans = min(ans, val - n);
                }
            }
            
            x /= 10;
            prod *= 10;
                
        }
        
        ans = min(ans, prod - n);
        
        cout<<ans<<endl;
    }
    
    return 0;
}