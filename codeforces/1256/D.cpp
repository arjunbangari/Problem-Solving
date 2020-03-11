#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll q;
    cin>>q;
    
    while(q--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        
        ll l=0,r=0;
        while(l<n){
            while(l<n && s[l]=='0')
                l++;
            r = max(r,l);
            while(r<n && s[r]=='1')
                r++;
            if(r==n)
                break;
            if((r-l)<=k){
                k -= (r-l);
                swap(s[l], s[r]);
            } else {
                while(k>0){
                    swap(s[r],s[r-1]);
                    r--;
                    k--;
                }
                break;
            }
            l++;
        }
        cout<<s<<endl;
        
    }
    
    return 0;
}