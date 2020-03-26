#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n,k,l=0;
        cin>>n>>k;
        
        ll pos = 0;
        ll sum=0, i=1;
        while(1){
            sum += (i++);
            pos++;
            if(k<=sum)
                break;
        }
        
        string ans;
        for(ll i=0;i<n-pos-1;i++){
            ans += 'a';
            l++;
        }
        ans += 'b';
        l++;
        
        for(ll i=0;i<(n-l);i++)
            ans += 'a';
        
        ans[n-1] = 'b';
        
        // cout<<ans<<endl;
        
        sum = (pos*(pos-1))/2;
        ll p = k-sum;
        
        i=n-1;
        while(p>1){
            swap(ans[i],ans[i-1]);
            i--;
            p--;
        }
        
        
        cout<<ans<<endl;
        
        
    }
    
    return 0;
}