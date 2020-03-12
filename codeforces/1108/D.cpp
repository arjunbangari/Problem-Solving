#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    s.push_back('P');
    ll ans=0;
    
    string temp("RGB");
    
    for(ll i=1;i<n;i++){
        if(s[i]==s[i-1]){
            ans++;
            for(ll j=0;j<3;j++){
                if(temp[j]!=s[i-1] && temp[j]!=s[i+1])
                    s[i] = temp[j];
            }
        }
    }
    
    s.pop_back();
    cout<<ans<<endl;
    cout<<s<<endl;
    
    return 0;
}