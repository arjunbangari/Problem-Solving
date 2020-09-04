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
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        
        vector<ll> ans(n);
        ll cur_min = inf;
        
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                if((y-x)%(j-i)!=0)
                    continue;
                
                ll d = (y-x)/(j-i);
                
                if((x-i*d)<=0)
                    continue;
                
                ll num = (n-1) - j;
                
                if((y+d*num)<cur_min){
                    ll start = x - i*d;
                    for(ll k=0;k<n;k++){
                        ans[k] = start;
                        start += d;
                    }
                    cur_min = y + d*num;
                }
            }
        }
        
        for(ll i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    
    return 0;
}