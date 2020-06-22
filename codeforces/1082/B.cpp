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
    
    ll n;
    cin>>n;
    
    string s;
    cin>>s;
    
    ll ans = 0, gcnt=0;
    
    for(ll i=0;i<n;i++)
        if(s[i]=='G')
            gcnt++;
    
    for(ll i=1;i<n-1;i++){
        if(s[i]=='S' && s[i-1]=='G' && s[i+1]=='G'){
            ll j = i-1, cnt=0;
            
            while(j>=0 && s[j]=='G')
                j--;
            
            cnt += (i-j-1);
            
            j = i+1;
            while(j<n && s[j]=='G')
                j++;
            
            cnt += (j-i-1);
        
            if(cnt<gcnt)
                cnt++;
            
            ans = max(ans, cnt);
        }
    }
    
    ll i=0;
    while(i<n){
        if(s[i]=='G') {
            ll j = i+1;
            while(j<n && s[j]=='G')
                j++;
            
            if((j-i)<gcnt)
                i--;
            
            ans = max(ans, j-i);
            i = j;
        } else 
            i++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}