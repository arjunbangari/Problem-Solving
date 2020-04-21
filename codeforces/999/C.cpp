#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    string s;
    cin>>s;
    
    map<char, ll> mp;
    
    for(ll i=0;i<n;i++)
        mp[s[i]]++;
    
    ll temp = 0;
    char pos;
    for(char j='a';j<='z';j++){
        if((mp[j]+temp)<k)
            temp += mp[j];
        else {
            pos = j;
            break;
        }
    }
        
    ll cnt = k - temp;
    string ans;
    
    for(ll i=0;i<n;i++){
        if(s[i]<pos)
            continue;
        if(s[i]==pos && cnt>0)
            cnt--;
        else
            ans.push_back(s[i]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}