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
        ll n,m;
        cin>>n>>m;
        
        vector<pll> arr(m);
        for(ll i=0;i<m;i++)
            cin>>arr[i].first>>arr[i].second;
        
        sort(arr.begin(), arr.end());
        
        vector<ll> sum(m);
        for(ll i=0;i<m;i++){
            sum[i] = arr[i].first;
            if(i!=0)
                sum[i] += sum[i-1];
        }
        
        ll ans = 0;
        
        for(ll i=0;i<m;i++){
            ll tmp = arr[i].first;
            
            pll x = make_pair(arr[i].second, 0);
            
            auto it = lower_bound(arr.begin(), arr.end(), x);
            ll it1 = arr.end() - it;
            
            ll k = min(it1, n-1);
            if((m-1-k)<0)
                tmp += sum[m-1];
            else
                tmp += sum[m-1] - sum[m-1-k];
            
            ll val = n - 1 - k;
            
            if(i>=(m-k)){
                tmp -= arr[i].first;
                val++;
            }
            
            tmp += val*arr[i].second;
            ans = max(ans, tmp);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}