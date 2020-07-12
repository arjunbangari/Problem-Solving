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
    
    ll t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        ll n = s.length();
        
        map<char, ll> mp;
        ll mx = -1;
        char ch;
        
        for(ll i=0;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]>mx)
                ch = s[i];
            mx = max(mx, mp[s[i]]);
        }
            
        char ans;
        if(ch=='R')
            ans = 'P';
        if(ch=='P')
            ans = 'S';
        if(ch=='S')
            ans = 'R';
        
        for(ll i=0;i<n;i++)
            cout<<ans;
        cout<<endl;
    }
    
    return 0;
}