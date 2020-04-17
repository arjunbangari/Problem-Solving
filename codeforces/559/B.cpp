#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

string s, t;

ll solve(ll a, ll b, ll len){
    if(len%2){
        if(s.substr(a,len)==t.substr(b,len))
            return 1;
        return 0;
    }
    
    ll ans;
    
    ans = solve(a, b + len/2, len/2) && solve(a + len/2, b, len/2);
    
    if(ans)
        return 1;

    ans = solve(a, b, len/2) && solve(a+len/2, b + len/2, len/2);
        
    return ans;
}

int main(){
    fast;
    
    cin>>s>>t;
    
    ll n = s.length();
    
    ll ans = solve(0,0, n);
    
    cout<< (ans ? "YES" : "NO")<<endl;
    
    return 0;
}