#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
string arr[505];
ll n,m;
bool valid(ll x, ll y){
    return (x>=0 && x<n && y>=0 && y<m);
}

void dfs(ll i, ll j){
    arr[i][j] = 'X';
    if(valid(i-1,j) && arr[i-1][j]!='X')
        dfs(i-1,j);
    if(valid(i+1,j) && arr[i+1][j]!='X')
        dfs(i+1,j);
    if(valid(i,j-1) && arr[i][j-1]!='X')
        dfs(i,j-1);
    if(valid(i,j+1) && arr[i][j+1]!='X')
        dfs(i,j+1);
}

int main(){
    string s;
    cin>>n>>m;
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll r1,c1,r2,c2;
    cin>>r1>>c1;
    cin>>r2>>c2;
    r1--;
    c1--;
    r2--;
    c2--;

    ll count=0;
    if(valid(r2-1,c2) && arr[r2-1][c2]!='X')
        count++;
    if(valid(r2+1,c2) && arr[r2+1][c2]!='X')
        count++;
    if(valid(r2,c2-1) && arr[r2][c2-1]!='X')
        count++;
    if(valid(r2,c2+1) && arr[r2][c2+1]!='X')
        count++;
    //cout<<count<<"\n";
    string ans;
    ll flag=0;
    
    if(r1==r2 && c1==c2) {
        ans = (count>0 ? "YES" : "NO");
    } else if((r2==(r1-1) && c2==c1) || (r2==(r1+1) && c1==c2) || (r2==r1 && c2==(c1-1)) || (r2==r1 && c2==(c1+1))){
        if(arr[r2][c2]=='X')
            ans="YES";
        else
            ans = (count>0 ? "YES":"NO");
    } else{ 
        if(arr[r2][c2]=='X'){
            arr[r2][c2]='.';
            flag = 1;
        }
        dfs(r1,c1);
        if(arr[r2][c2]=='X'){
            if(flag)
                ans = "YES";
            else{
                ans = (count>1 ? "YES" : "NO");
            }
        }
        else
            ans="NO";
    }
    //for(ll i=0;i<n;i++)
    //    cout<<arr[i]<<"\n";
    cout<<ans<<endl;
    return 0;
}