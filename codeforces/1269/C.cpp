#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    string s;
    cin>>s;
    
    string t(s);
    
    for(ll i=0;i<k;i++)
        for(ll j=i+k;j<n;j+=k)
            s[j] = s[i];
    
    cout<<n<<endl;
    
    if(s>=t){
        cout<<s<<endl;
        return 0;
    }
    
    ll x = k-1;
    
    while(x>=0 && s[x]=='9')
        x--;
    
    s[x]++;
    
    for(ll i=x+1;i<k;i++)
        s[i] = '0';
    
    for(ll i=0;i<k;i++)
        for(ll j=i+k;j<n;j+=k)
            s[j] = s[i];
    
    cout<<s<<endl;
    
    return 0;
}