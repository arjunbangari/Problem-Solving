#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll k;
    cin>>k;
    
    vector<ll> ans(10);
    
    ll cur = 1;
    
    while(1){
        ll tmp = 1;
        for(ll i=0;i<10;i++)
            tmp *= cur;
        
        if(tmp>=k)
            break;
        
        cur++;
    }
    
    for(ll i=0;i<10;i++)
        ans[i] = cur-1;
    
    for(ll i=0;i<10;i++){
        ans[i] = cur;
        ll tmp = 1;
        for(ll j=0;j<10;j++)
            tmp *= ans[j];
        
        if(tmp>=k)
            break;
    }
    
    string s("codeforces");
    
    for(ll i=0;i<10;i++){
        for(ll j=0;j<ans[i];j++)
            cout<<s[i];
    }
    
    return 0;
}