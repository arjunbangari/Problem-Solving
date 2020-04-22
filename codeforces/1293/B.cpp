#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ld n;
    cin>>n;
    
    ld ans = 0;
    
    while(n>0){
        ans += 1/n;
        n--;
    }
    
    cout<<fixed<<setprecision(6)<<ans<<endl;
    
    return 0;
}