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
    
    ll n,m;
    cin>>n>>m;
    
    string s;
    cin>>s;
    
    ll ans = 0, i=0;
    
    while(i<n){
        if(s[i]!='.')
            i++;
        else {
            ll j = i+1;
            while(j<n && s[j]=='.')
                j++;
            ans += j-i-1;
            i = j;
        }
    }
    
    while(m--){
        ll x;
        char c;
        cin>>x>>c;
        x--;
    
        if(s[x]=='.'){
            if((x-1)>=0 && s[x-1]=='.' && (x+1)<n && s[x+1]=='.')
                ans -= 2;
            else if((x-1)>=0 && s[x-1]=='.')
                ans--;
            else if((x+1)<n && s[x+1]=='.')
                ans--;
        }
        
        s[x] = c;
        
        if(c=='.'){
            if((x-1)>=0 && s[x-1]=='.' && (x+1)<n && s[x+1]=='.')
                ans += 2;
            else if((x-1)>=0 && s[x-1]=='.')
                ans++;
            else if((x+1)<n && s[x+1]=='.')
                ans++;
        }
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}