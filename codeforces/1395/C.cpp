#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    vector<ll> arr(n), brr(m);
    for(auto &u: arr)
        cin>>u;
        
    for(auto &u: brr)
        cin>>u;
    
    ll c;
    
    for(c=0;c<1024;c++){
        ll cnt = 0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                ll x = arr[i] & brr[j];
                ll y = x | c;
                
                if(y==c){
                    cnt++;
                    break;
                }
            }
        }
        if(cnt==n)
            break;
    }
    
    cout<<c<<endl;
    return 0;
}