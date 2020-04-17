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

void solve(string s){
    ll n = s.length();
    
    ll ans = 0;
    
    ll i=0;
    while(i<n){
        if(s[i]=='1'){
            i++;
            continue;
        }
        
        ll j=i;
        while(j<n && s[j]=='0')
            j++;
        
        ans += ((j-i)*(j-i+1))/2;
        i = j;
    }
    
    cout<<ans<<endl;
}


int main(){
    fast;
    
    ll k;
    cin>>k;
    
    string s;
    cin>>s;
    
    if(k==0){
        solve(s);
        return 0;
    }
    
    ll n = s.length();
    
    vector<pair<ll,ll>> arr;
    
    ll i=0, j=0, cnt=0;
    while(i<n){
        if(s[i]=='0'){
            i++;
            continue;
        }
        
        j = max(j,i);
        
        while(j<n && cnt<k){
            if(s[j]=='1')
                cnt++;
            j++;
        }
        
        if(cnt==k)
            arr.push_back({i,j-1});
        else
            break;
        
        i++;
        cnt--;
    }
    
    ll ans=0;
    
    for(auto u: arr){
        ll l = u.first, r = u.second;
        l--; r++;
        while(l>=0 && s[l]=='0')
            l--;
        while(r<n && s[r]=='0')
            r++;
        
        ans += (u.first-l)*(r-u.second);
    }
    
    cout<<ans<<endl;
    
    return 0;
}