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
    
    vector<ll> arr(26);
    for(auto &u: arr)
        cin>>u;
    
    string s;
    cin>>s;
    
    ll n = s.length();
    
    map<ll, ll> mp[26];

    vector<ll> brr(n);
    for(ll i=0;i<n;i++){
        brr[i] = arr[s[i]-'a'];
        if(i!=0)
            brr[i] += brr[i-1];
    }
    
    ll ans = 0;
    
    mp[s[0]-'a'][brr[0]]++;
    
    for(ll i=1;i<n;i++){
        ans += mp[s[i]-'a'][brr[i-1]];
        mp[s[i]-'a'][brr[i]]++;
    }

    cout<<ans<<endl;
    
    return 0;
}