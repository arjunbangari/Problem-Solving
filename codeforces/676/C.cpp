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
    
    ll l=0,r=0,ans = 0,curr=k;
    while(l<n && r<n){
        if(s[r]=='a')
            r++;
        else{
            if(curr==0){
                if(s[l]=='b'){
                    curr++;
                }
                l++;
            } else {
                r++;
                curr--;
            }
        }
        ans = max(ans,r-l);
    }
    
    l = 0, r = 0, curr=k;
    while(l<n && r<n){
        if(s[r]=='b')
            r++;
        else{
            if(curr==0){
                if(s[l]=='a'){
                    curr++;
                }
                l++;
            } else {
                r++;
                curr--;
            }
        }
        ans = max(ans,r-l);
    }
    
    cout<<ans<<endl;
    
    return 0;
}