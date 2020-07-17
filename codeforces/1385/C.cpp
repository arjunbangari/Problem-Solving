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
        ll n;
        cin>>n;
        
        vector<ll> arr(n);
        for(auto &u: arr)
            cin>>u;
            
        vector<ll> pre(n), suf(n);
        for(ll i=0;i<n;i++){
            pre[i] = arr[i];
            if(i!=0)
                pre[i] = max(pre[i], pre[i-1]);
        }
        
        for(ll i=n-1;i>=0;i--){
            suf[i] = arr[i];
            if(i!=(n-1))
                suf[i] = max(suf[i], suf[i+1]);
        }
        
        ll i = n-1;
        for(;i>0;i--){
            if(pre[i]>arr[i] && suf[i]>arr[i])
                break;
        }
        
        while(i>0 && arr[i]>=arr[i-1])
            i--;
        
        cout<<i<<endl;
        
    }
    
    return 0;
}