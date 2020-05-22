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

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n), brr(n);
    for(auto &u: arr)
        cin>>u;
    
    for(auto &u: brr)
        cin>>u;
    
    sort(arr.rbegin(), arr.rend());
    sort(brr.rbegin(), brr.rend());
    
    ll a = 0, b = 0, score_a=0, score_b=0, cur=1;
    
    while(1){
        if(a==n && b==n)
            break;
        
        if(cur){
            if(a==n){
                b++;
            }
            else if(b==n){
                score_a += arr[a];
                a++;
            }
            else{
                if(brr[b]>arr[a]){
                    b++;
                } else {
                    score_a += arr[a];
                    a++;
                }
            }
        } else {
            if(b==n){
                a++;
            } else if(a==n) {
                score_b += brr[b];
                b++;
            } 
            else {
                if(arr[a]>brr[b]){
                    a++;
                } else {
                    score_b += brr[b];
                    b++;
                }
            }
        }
        cur = !cur;
    }
    
    cout<<score_a - score_b<<endl;
    
    return 0;
}