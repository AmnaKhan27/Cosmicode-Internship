#include<iostream>
using namespace std;
int main(){

    int first = 0, second = 1, next;
    int n = 20;
    cout<<"first 20 fibonacci nmbers ";

    for(int i=0; i<n; i++){

        if(i<=1){cout<<next;}

        else{    
          next = first+second;
          first = second;
          second = next;
        }
         cout<<next<<" ";
    }
   
 return 0;
}