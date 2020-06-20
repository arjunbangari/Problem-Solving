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
    
   ll n,q;
   cin>>n>>q;
   
   vector<ll> arr, brr(maxn,-1);
   map<ll, ll> mp;
   
   ll last_t = 0, sz = 0;
   ll ans = 0;
   
    for(ll i=0;i<q;i++){
       ll type, x;
       cin>>type>>x;
       
      if(type==1){
          arr.push_back(x);
          sz++;
          mp[x]++;
          ans++;
      }
       
      if(type==2){
          ans -= mp[x];
          mp[x] = 0;
          brr[x] = sz-1;
      }
       
      if(type==3){
          for(ll j=last_t;j<x;j++){
              if(brr[arr[j]]<j){
                  ans--;
                  brr[arr[j]] = j;
                  mp[arr[j]]--;
              }
          }
          last_t = max(x, last_t);
      }
            
        cout<<ans<<endl;
   }
    
    return 0;
}