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
        
        vector<ll> cnt(3,0);
        
        ll i=0, j=0, ans=inf, l=0 , r=0;
        
        while(i<n){
            cnt[s[i]-'1']++;
            if(cnt[0] && cnt[1] && cnt[2]){
                while(j<n && cnt[0] && cnt[1] && cnt[2]){
                    cnt[s[j]-'1']--;
                    j++;
                }
                
                if((i-j+2)<ans){
                    l = j-1;
                    r = i;
                }
                ans = min(ans, i-j+2);
            }
            i++;
        }
        
        cout<< (ans==inf ? 0 : ans )<<endl;
    
    }
    
    return 0;
}