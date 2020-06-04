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

bool check(string s, ll n){
    ll cnt = 0;
    for(ll i=0;i<n-1;i++){
        if(s[i]=='(')
            cnt++;
        else
            cnt--;
        if(cnt<=0)
            return false;
    }
    
    if(s[n-1]==')')
        cnt--;
    else
        cnt++;
    
    return cnt==0;
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    string s;
    cin>>s;
    
    if(n%2){
        cout<<":("<<endl;
        return 0;
    }
    
    ll cnt[2] = {0};
    
    for(ll i=0;i<n;i++){
        if(s[i]=='(')
            cnt[0]++;
        else
            cnt[1]++;
    }
    
    ll x = n/2;
    
    cnt[0] = x-cnt[0];
    cnt[1] = x-cnt[1];

    for(ll i=0;i<n;i++){
        if(s[i]=='?'){
            if(cnt[0]>0){
                s[i] = '(';
                cnt[0]--;
            } else {
                s[i] = ')';
                cnt[1]--;
            }
        }
    }
    
    cout<< (check(s, n) ? s : ":(") <<endl;
    
    return 0;
}