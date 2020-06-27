#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 998244353;
 
// code begins here

int main(){
    fast;
    
    ll n,t;
    cin>>n>>t;
    
    string s1, s2;
    cin>>s1>>s2;

    vector<ll> ind;
    ll cnt = 0;
    
    for(ll i=0;i<n;i++){
        if(s1[i]!=s2[i]){
            ind.push_back(i);
            cnt++;
        }
    }
    
    if(cnt<=t){
        string ans(s1);
        for(auto u: ind){
            for(char ch='a';ch<='z';ch++){
                if(s1[u]!=ch && s2[u]!=ch){
                    ans[u] = ch;
                    break;
                }
            }
        }
        
        t -= cnt;
        
        for(ll i=0;i<n && t>0;i++){
            if(s1[i]==s2[i]){
                t--;
                ans[i] = ( s1[i]=='a' ? 'b' : 'a');
            }
        }
        
        cout<<ans<<endl;
        return 0;
    } 
    
    if(cnt<=2*t){
        string ans(s1);
        
        for(ll i=0;i<2*(cnt-t);i+=2){
            ans[ind[i]] = s1[ind[i]];
            ans[ind[i+1]] = s2[ind[i+1]];
        }    
        
        for(ll i=2*(cnt-t);i<cnt;i++){
            for(char ch='a';ch<='z';ch++){
                if(s1[ind[i]]!=ch && s2[ind[i]]!=ch){
                    ans[ind[i]] = ch;
                    break;
                }
            }
        }
        
        cout<<ans<<endl;
        return 0;
    }
    
    cout<<-1<<endl;
    
    return 0;
}