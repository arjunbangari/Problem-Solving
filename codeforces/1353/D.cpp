#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ll,pair<ll,ll>> ppll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

struct classcomp {
  bool operator() (const ppll& lhs, const ppll& rhs) const {
      if(lhs.first==rhs.first){
          if(lhs.second.first==rhs.second.first){
              return lhs.second.second<rhs.second.second;
          } else {
              return lhs.second.first<rhs.second.first;
          }
      } else {
          return lhs.first>rhs.first;
      }
  }
};

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> arr(n+1,0);
        
        multiset<ppll, classcomp> ms;
        
        ms.insert({n,{1,n}});
        
        for(ll i=1;i<=n;i++){
            ppll u = *ms.begin();
            ms.erase(ms.begin());
            
            ll l = u.second.first, r = u.second.second;
            
            // cout<<i<<" "<<l<<" "<<r<<endl;
            
            if(u.first%2){
                ll mid = (l+r)/2;
                arr[mid] = i;
                
                ms.insert( {mid-l, {l, mid-1 }});
                ms.insert( {r-mid, {mid+1, r}});
            } else {
                ll mid = (l+r-1)/2;
                arr[mid] = i;
                
                ms.insert( {mid-l, {l, mid-1 }});
                ms.insert( {r-mid, {mid+1, r}});
            }
        }
        
        for(ll i=1;i<=n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        
    }
    
    return 0;
}