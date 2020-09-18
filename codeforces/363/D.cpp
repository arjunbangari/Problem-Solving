#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m,a;
    cin>>n>>m>>a;
    
    vector<ll> pmoney(n), price(m);
    for(auto &u: pmoney)    
        cin>>u;
    
    for(auto &u: price)
        cin>>u;
        
    sort(rall(pmoney));
    sort(all(price));
        
    ll l = 0, r = m, optr = 0, opts = 0 ;
    
    while(l<=r){
        ll mid = (l+r)/2;
        
        if(mid>n){
            r = mid-1;
            continue;
        }
        
        vector<ll> crr, drr;
        for(ll i=0;i<mid;i++){
            crr.push_back(pmoney[i]);
            drr.push_back(price[i]);
        }
        
        reverse(all(crr));
        
        ll sum = 0;
        for(ll i=0;i<mid;i++)
            sum += max(0LL,  drr[i] - crr[i] );
        
        if(sum<=a){
            optr = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    
    for(ll i=0;i<optr;i++)
        opts += price[i];
    
    opts = max(0LL, opts - a);
    
    cout<<optr<<" "<<opts<<endl;
    return 0;
}