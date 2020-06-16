#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;

    ll n,k;
    cin>>n>>k;
    
    vector<ll> arr(n+1), pre(n+1);
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    arr[0] = -inf;
    
    sort(arr.begin(), arr.end());
    
    pre[0] = 0;
    for(ll i=1;i<=n;i++)
        pre[i] = pre[i-1] + arr[i];
        
    ll mx = -1, num;    
        
    for(ll i=1;i<=n;i++){
        
        ll l = 1, r = i, cur_mx = 1;
        
        while(l<=r){
            ll mid = (l+r)/2;
            ll req = arr[i]*mid - (pre[i] - pre[i-mid]);
            
            if(req<=k){
                cur_mx = mid;
                l = mid+1;
            } else {
                r = mid - 1;
            }
        }
        
        if(cur_mx>mx){
            mx = cur_mx;
            num = arr[i];
        }
            
    }
    
    cout<<mx<<" "<<num<<endl;
    
    return 0;
}
