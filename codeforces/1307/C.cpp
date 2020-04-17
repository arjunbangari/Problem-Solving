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

int main(){
    fast;
    
    string s;
    cin>>s;
    
    ll n = s.length();
    
    map<string,ll> mp1;
    map<char,ll> mp2;
    
    ll ans = -1;
    
    for(ll i=0;i<n;i++){
        for(char j='a';j<='z';j++){
            string temp;
            temp.push_back(j);
            temp.push_back(s[i]);
            mp1[temp] += mp2[j];
            ans = max(ans, mp1[temp]);
        }
        mp2[s[i]]++;
        ans = max(ans, mp2[s[i]]);
    }
    
    cout<<ans<<endl;
        
    return 0;
}