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
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
        
    set<ll> s;
    for(auto u: arr)
        s.insert(u);
    
    vector<ll> p(33);
    p[0] = 1;
    for(ll i=1;i<33;i++)
        p[i] = 2*p[i-1];
    
    for(auto u: arr){
        for(ll j=0;j<33;j++){
            if(s.count(u+p[j]) && s.count(u-p[j])){
                cout<<3<<endl;
                cout<<u<<" "<<u-p[j]<<" "<<u+p[j]<<endl;
                return 0;
            }
        }
    }
    
    for(auto u: arr){
        for(ll j=0;j<33;j++){
            if(s.count(u+p[j])){
                cout<<2<<endl;
                cout<<u<<" "<<u+p[j]<<endl;
                return 0;
            }
        }
    }
    
    cout<<1<<endl;
    cout<<arr[0]<<endl;
    
    return 0;
}