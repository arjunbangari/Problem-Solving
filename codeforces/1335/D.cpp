#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

string sudoku[9];

void change(ll i, ll j){
    if(sudoku[i][j]=='1')
        sudoku[i][j] = '2';
    else
        sudoku[i][j] = '1';
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        for(ll i=0;i<9;i++)
            cin>>sudoku[i];
        
        change(0,0);
        change(1,3);
        change(2,6);
        change(3,1);
        change(4,4);
        change(5,7);
        change(6,2);
        change(7,5);
        change(8,8);
        
        for(ll i=0;i<9;i++)
            cout<<sudoku[i]<<endl;
        
    }
    
    return 0;
}