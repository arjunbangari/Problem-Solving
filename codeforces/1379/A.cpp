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
string s, tmp;
string alpha("abacaba");

bool issubstring(){
    ll cnt = 0;
    for(ll i=0;i<=n-7;i++){
        ll flag = 1;
        for(ll j=0;j<7;j++){
            if(tmp[i+j]!=alpha[j])
                flag = 0;
        }
        if(flag)
            cnt++;
    }
    return cnt==1;
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        cin>>n;
        cin>>s;
        
        string ans("No");
        
        for(ll i=0;i<=n-7;i++){
            ll flag = 1;
            for(ll j=0;j<7;j++){
                if(s[i+j]=='?' || s[i+j]==alpha[j])
                    continue;
                flag = 0;
            }
            
            if(flag){
                tmp = s;
                for(ll j=0;j<7;j++)
                    tmp[i+j] = alpha[j];
                
                if(issubstring()){
                    ans = "Yes";
                    break;
                }
                
                
            }
        }
        
        if(ans=="Yes"){
            s = tmp;
            for(ll i=0;i<n;i++)
                if(s[i]=='?')
                    s[i] = 'z';
                
            cout<<"Yes"<<endl;
            cout<<s<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}