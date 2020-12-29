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
        ll n,m, sum = 0;
        cin>>n>>m;
        
        vector<ll> arr(m);
        for(auto &u: arr){
            cin>>u;
            sum += u;
        }
        
        if(sum<n){
            cout<<-1<<endl;
            continue;
        }
            
        vector<ll> cnt(100);
        for(auto u: arr){
            bitset<64> x(u);
            for(ll i=0;i<64;i++)
                if(x[i])
                    cnt[i]++;
        }
        
        bitset<64> num(n);
        
        ll ans = 0;
        for(ll i=0;i<64;i++){
            if(num[i]){
                if(!cnt[i]) {
                    for(ll j=i+1;j<64;j++){
                        if(cnt[j]){
                            for(ll k=j;k>i;k--){
                                cnt[k]--;
                                cnt[k-1] += 2;
                                ans++;
                            }
                            break;
                        }
                    }
                }
                
                cnt[i]--;
            }
            cnt[i+1] += cnt[i]/2;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}