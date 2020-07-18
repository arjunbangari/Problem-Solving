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

ll n;
string s;
ll cnt[maxn][26];

void preprocess(){
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<26;j++)
            cnt[i][j] = 0;
        
    for(ll i=1;i<=n;i++){
        cnt[i][s[i]-'a']++;
        for(ll j=0;j<26;j++)
            cnt[i][j] += cnt[i-1][j];
    }
}

ll solve(ll l, ll r, char c){
    if(l==r)
        return ( s[l]==c ? 0 : 1 );
    
    ll m = (l+r)/2;
    ll len = (r-l+1)/2;
    
    ll ans1 = len - cnt[m][c-'a'] + cnt[l-1][c-'a'] + solve(m+1, r, char(c+1));
    ll ans2 = len - cnt[r][c-'a'] + cnt[m][c-'a'] + solve(l, m, char(c+1));
    return min(ans1, ans2);
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        cin>>n;
        cin>>s;
        s = "#" + s;
        
        preprocess();
        ll ans = solve(1, n, 'a');
        cout<<ans<<endl;
    }
    
    return 0;
}