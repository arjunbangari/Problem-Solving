#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    string res;
    ll ans = 0, l=0, r=n-1, mx=-1;
    
    while(l<r){
        if(arr[l]<=mx && arr[r]<=mx)
            break;
        
        if(arr[l]==arr[r]){
            
            ll mx1 = mx;
            
            string temp1;
            ll ans1 = 0;
            
            ll i=l;
            while(i<r){
                if(arr[i]>mx1){
                    temp1.push_back('L');
                    ans1++;
                    mx1 = arr[i];
                    i++;
                } 
                else break;
            }
            
            ll ans2 = 0;
            string temp2;
            i = r;
            mx1 = mx;
            
            while(i>l){
                if(arr[i]>mx1){
                    temp2.push_back('R');
                    ans2++;
                    mx1 = arr[i];
                    i--;
                }
                else break;
            }
            
            if(ans1>ans2){
                ans += ans1;
                res += temp1;
            } else {
                ans += ans2;
                res += temp2;
            }
            break;
        }
        if(arr[l]<arr[r]){
            if(arr[l]>mx){
                res.push_back('L');
                mx = arr[l];
                l++;
            } 
            else if(arr[r]>mx){
                res.push_back('R');
                mx = arr[r];
                r--;
            }
        }
        else {
            if(arr[r]>mx){
                res.push_back('R');
                mx = arr[r];
                r--;
            }
            else if(arr[l]>mx){
                res.push_back('L');
                mx = arr[l];
                l++;
            }
        }

        ans++;
    }
    
    if(l==r){
        if(arr[l]>mx){
            ans++;
            res.push_back('L');
        }
    }
    
    cout<<ans<<endl;
    cout<<res<<endl;
    
    return 0;
}