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
        ll n,k,z;
        cin>>n>>k>>z;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
            
        vector<ll> sum(n);
        for(ll i=0;i<n;i++){
            sum[i] = arr[i];
            if(i!=0)
                sum[i] += sum[i-1];
        }
        
        ll ans = 0;
        
        for(ll i=1;i<n;i++){
            if(i>k)
                break;
            ll tmp = sum[i], x = k-i, cur = i, y = z;
            
            while(x>0 && y>0){
                if(cur==i){
                    cur--;
                    tmp += arr[cur];
                    y--;
                } else {
                    cur++;
                    tmp += arr[cur];
                }
                x--;
            }
            
            tmp += sum[cur+x] - sum[cur];
            ans = max(ans, tmp);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}