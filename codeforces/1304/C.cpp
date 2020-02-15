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
        ll n,m;
        cin>>n>>m;
        ll arr[n][3];
        for(ll i=0;i<n;i++)
            cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        
        ll flag=0,mx=m,mn=m,pt=0;

            for(ll i=0;i<n;i++){
                if(arr[i][1]<=mn && arr[i][2]>=mx){
                    mx = min(mx+(arr[i][0]-pt),arr[i][2]);
                    mn = max(arr[i][1], mn - (arr[i][0]-pt));
                    pt = arr[i][0];
                } 
                else if(arr[i][1]>=mn && arr[i][2]<=mx){
                    mn = arr[i][1];
                    mx = arr[i][2];
                    pt = arr[i][0];
                }
                else if(arr[i][1]>=mx && (mx+(arr[i][0]-pt))>=arr[i][1]){
                    mx = min(arr[i][2],mx + (arr[i][0]-pt));
                    mn = arr[i][1];
                    pt = arr[i][0];
                }
                else if(arr[i][2]<=mn && (mn-(arr[i][0]-pt))<=arr[i][2]){
                    mn = max(arr[i][1],mn-(arr[i][0]-pt));
                    mx = arr[i][2];
                    pt = arr[i][0];
                } 
                else if(arr[i][1]>=mn && arr[i][1]<=mx && arr[i][2]>=mx){
                    mn = arr[i][1];
                    mx = min(arr[i][2], mx + (arr[i][0]-pt));
                    pt = arr[i][0];
                }
                else if(arr[i][1]<=mn && arr[i][2]>=mn && arr[i][2]<=mx){
                    mx = arr[i][2];
                    mn = max(arr[i][1], mn-(arr[i][0]-pt));
                    pt = arr[i][0];
                }
                else{
                    flag = 1;
                    break;
                }
            }
            
        if(flag)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}