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
    
    if(n==1 || n==2){
        cout<<"No"<<endl;
    } else {
        cout<<"Yes"<<endl;
        cout<<n-1<<" ";
        for(ll i=1;i<n;i++)
            cout<<i<<" ";
        cout<<endl;
        cout<<1<<" "<<n<<endl;
    }
    
    return 0;
}