#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll n,k, ans=0;
string s;

void solve(){
    ll mn1 = 0, mn2 = 0;
    char cur1 = 'A', cur2 = 'B';
    
    string t1, t2;
    for(ll i=0;i<n;i++){
        t1.push_back(cur1);
        t2.push_back(cur2);
        swap(cur1, cur2);
    }
    
    for(ll i=0;i<n;i++){
        if(t1[i]!=s[i])
            mn1++;
        if(t2[i]!=s[i])
            mn2++;
    }
    
    if(mn1<mn2){
        cout<<mn1<<endl;
        cout<<t1<<endl;
    } else {
        cout<<mn2<<endl;
        cout<<t2<<endl;
    }
}

int main(){
    fast;

    cin>>n>>k;
    cin>>s;
    string alpha("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    
    if(k==2){
        solve();
        return 0;
    } else {
        for(ll i=1;i<n-1;i++){
            if(s[i]==s[i-1] && s[i]==s[i+1]){
                for(ll j=0;j<k;j++){
                    if(alpha[j]!=s[i]){
                        s[i] = alpha[j];
                        break;
                    }
                }
                ans++;
            } else if(s[i]==s[i-1]){
                for(ll j=0;j<k;j++){
                    if(alpha[j]!=s[i-1] && alpha[j]!=s[i+1]){
                        s[i] = alpha[j];
                        break;
                    }
                }
                ans++;
            }
        }
        
        if(s[n-1]==s[n-2]){
            for(ll j=0;j<k;j++){
                if(alpha[j]!=s[n-2])
                    s[n-1] = alpha[j];
            }
            ans++;
        }
        
        cout<<ans<<endl;
        cout<<s<<endl;
    }
    return 0;
}