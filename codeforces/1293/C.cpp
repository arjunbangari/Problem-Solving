#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll n;
bool valid(ll x,ll y){
    return (x>=1 && x<=2 && y>=1 && y<=n);
}

int main(){
    fast;
    ll q,r,c,count=0;
    cin>>n>>q;
    ll arr[3][n+1];
    memset(arr,0,sizeof(arr));
    while(q--){
        cin>>r>>c;
        string ans;
        
        if(arr[r][c]==0){
            arr[r][c] = 1;
            if(r==1){
                if(valid(r+1,c) && arr[r+1][c]==1)
                    count++;
                if(valid(r+1,c-1) && arr[r+1][c-1]==1)
                    count++;
                if(valid(r+1,c+1) && arr[r+1][c+1]==1)
                    count++;
            }
            else{
                if(valid(r-1,c) && arr[r-1][c]==1)
                    count++;
                if(valid(r-1,c-1) && arr[r-1][c-1]==1)
                    count++;
                if(valid(r-1,c+1) && arr[r-1][c+1]==1)
                    count++;
            }
        }
        else{
            arr[r][c]=0;
            if(r==1){
                if(valid(r+1,c) && arr[r+1][c]==1)
                    count--;
                if(valid(r+1,c-1) && arr[r+1][c-1]==1)
                    count--;
                if(valid(r+1,c+1) && arr[r+1][c+1]==1)
                    count--;
            }
            else{
                if(valid(r-1,c) && arr[r-1][c]==1)
                    count--;
                if(valid(r-1,c-1) && arr[r-1][c-1]==1)
                    count--;
                if(valid(r-1,c+1) && arr[r-1][c+1]==1)
                    count--;
            }
        }
        ans = (count>0 ? "No":"Yes");
        cout<<ans<<endl;
    }
    return 0;
}