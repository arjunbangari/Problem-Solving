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
    
    ll t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        ll n = s.length();
        
        map<pair<ll,ll>, set<pair<ll,ll>>> mp;
        
        ll x=0, y=0, ans=0;
        
        for(ll i=0;i<n;i++){
            ll curx = x, cury = y;
            
            if(s[i]=='N')
                cury++;
            if(s[i]=='S')
                cury--;
            if(s[i]=='W')
                curx--;
            if(s[i]=='E')
                curx++;
            
            if(mp[{x,y}].find({curx,cury})!=mp[{x,y}].end())
                ans++;
            else if(mp[{curx,cury}].find({x,y})!=mp[{curx,cury}].end())
                ans++;
            else
                ans += 5;
                
            mp[{x,y}].insert({curx,cury});
            mp[{curx,cury}].insert({x,y});
            
            x = curx;
            y = cury;
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}