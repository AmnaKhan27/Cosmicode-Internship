#include<iostream>
using namespace std;
int main()
{
    int arr[] = {12, 56, 34, 78, 23, 91, 45, 67, 3, 9};
    int size = sizeof(arr);
    int largest = arr[0];
    int smallest = arr[0];

    for(int i=0; i<size; i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
         if(arr[i]<smallest){
            smallest=arr[i];
        }
    }
    cout<<"largest number: "<<largest<<endl;
    cout<<"smallest number: "<<smallest<<endl;
}