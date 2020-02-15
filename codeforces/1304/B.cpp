#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

bool pal(string str) 
{ 
    // Start from leftmost and rightmost corners of str 
    int l = 0; 
    int h = str.length()-1; 
  
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            return false; 
        } 
    } 
    return true;
} 

int main(){
    fast;
    ll n,m;
    cin>>n>>m;
    unordered_set<string> us;
    string arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        us.insert(arr[i]);
    }
    string ans;
    for(ll i=0;i<n;i++){
        if(!pal(arr[i])){
            string temp(arr[i]);
            reverse(temp.begin(),temp.end());
            if(us.find(temp)!=us.end()){
                ans += arr[i];
                us.erase(temp);
                us.erase(arr[i]);
            }
        }
    }
    ll mx=0;
    string p;
    for(string u: us){
        if(pal(u)){
            if(u.length()>mx){
                mx = u.length();
                p = u;
            }
        }
    }
    
    cout<<2*ans.length() + mx<<endl;
    cout<<ans;
    if(mx!=0)
        cout<<p;
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    
    return 0;
}