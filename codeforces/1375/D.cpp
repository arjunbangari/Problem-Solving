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
            
        vector<ll> ans;    
            
        while(1){
            vector<ll> cnt(n+1);
            for(auto u: arr)
                cnt[u]++;
            
            ll mex;
            for(ll i=0;i<=n;i++){
                if(!cnt[i]){
                    mex = i;
                    break;
                }
            }
            
            if(mex!=n){
                arr[mex] = mex;
                ans.push_back(mex);
            } else {
                ll ind  = -1;
                for(ll i=0;i<n;i++){
                    if(arr[i]!=i){
                        ind = i;
                        break;
                    }
                }
                
                if(ind==-1)
                    break;
                
                arr[ind] = n;
                ans.push_back(ind);
            }
        }
        
        ll k = ans.size();
        
        cout<<k<<endl;
        for(auto u: ans)
            cout<<u+1<<" ";
        cout<<endl;
    }
    
    return 0;
}