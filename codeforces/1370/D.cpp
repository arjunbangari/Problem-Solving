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
ll n, k;
vector<ll> arr(maxn);

bool checkodd(ll x){
    ll cur = 1, cnt = 0;
    
    for(ll i=0;i<n;i++){
        if(cur){
            if(arr[i]<=x){
                cur = !cur;
                cnt++;
            } 
        } else {
            cnt++;
            cur = !cur;
        }
    }
    
    return cnt>=k;
}

bool checkeven(ll x){
    ll cur = 0, cnt = 0;
    
    for(ll i=0;i<n;i++){
        if(cur){
            if(arr[i]<=x){
                cnt++;
                cur = !cur;
            }
        } else {
            cur = !cur;
            cnt++;
        }
    }
    
    return cnt>=k;
}

int main(){
    fast;
    
    cin>>n>>k;
    
    for(auto &u: arr)
        cin>>u;
    
    ll l = 1, r = 1e10, ans;
    
    while(l<=r){
        ll mid = (l+r)/2;
        
        if(checkodd(mid) || checkeven(mid)){
            r = mid-1;
            ans = mid;
        } else 
            l = mid+1;
    }
        
    cout<<ans<<endl;
    
    return 0;
}