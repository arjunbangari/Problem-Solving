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
        ll n;
        cin>>n;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
        
        ll ans = -inf;
        
        vector<ll> neg, pos;
        for(auto u: arr){
            if(u>=0)
                pos.push_back(u);
            else
                neg.push_back(u);
        }
        
        sort(rall(pos));
        sort(all(neg));
        
        ll szn = neg.size();
        ll szp = pos.size();
        
        for(ll i=0;i<=5;i++){
            ll prod = 1;
            
            if(szp<i || szn<(5-i))
                continue;
            
            for(ll j=0;j<i;j++)
                prod *= pos[j];
            
            if((5-i)%2!=0){
                for(ll j=0;j<5-i;j++){
                    prod *= neg[szn-j-1];
                }
            } else {
                for(ll j=0;j<5-i;j++)
                    prod *= neg[j];
            }
            
            ans = max(ans ,prod);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}