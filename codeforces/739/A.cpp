#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m, mn = inf;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        ll l,r;
        cin>>l>>r;
        mn = min(mn, r-l+1);
    }
    
    cout<<mn<<endl;
    for(ll i=0;i<n;i++)
        cout<<i%mn<<" ";
    
    return 0;
}