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
    
    ll n,s;
    cin>>n>>s;
    
    ll a = n - 1;
    ll b = s - n  + 1;
    
    if((a+1)<b){
        cout<<"YES"<<endl;
        for(ll i=0;i<n-1;i++)
            cout<<1<<" ";
        cout<<b<<endl;
        cout<<n<<endl;
    } else {
        cout<<"NO"<<endl;
    }
    
    return 0;
}