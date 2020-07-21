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
    
    ll n,m,w;
    cin>>n>>m>>w;
    
    vector<ll> arr(maxn);
    for(auto &u: arr)
        cin>>u;
    
    ll l = 1, r = 1e15, ans ;
    
    while(l<=r){
        ll v = (l+r)/2;
        
        vector<ll> brr(arr);
        vector<ll> inc(maxn);
        
        ll cnt = 0;
        for(ll i=0;i<n;i++){
            if(i!=0)
                inc[i] += inc[i-1];
            brr[i] += inc[i];
            if(brr[i]<v){
                ll dif = v - brr[i];
                cnt += dif;
                inc[i] += dif;
                inc[i+w] -= dif;
                
            }
            if(cnt>m)
                break;
        }
        
        if(cnt<=m){
            ans = v;
            l = v+1;
        } else 
            r = v-1;
    }
    
    cout<<ans<<endl;
    
    return 0;
}