#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[],int i, int mid, int j){
    int aux_arr[20]; // change size if arr length > 20
    int a = i, b = mid+1;
    int x = i;
    while(a<mid+1 && b<j+1){
        if(arr[a]<arr[b]){
            aux_arr[x] = arr[a];
            a++;
            x++;
        }
        else{
            aux_arr[x] = arr[b];
            b++;
            x++;
        }
    }
    while(a<mid+1){
        aux_arr[x] = arr[a];
        a++;
        x++;
    }
    while(b<j+1){
        aux_arr[x] = arr[b];
        b++;
        x++;
    }
    x = i;
    for(;x<=j;x++){
        arr[x]=aux_arr[x];
    }
}

void mergesort(int arr[],int i, int j){
    if(i<j){
        int mid = (i+j)/2;
        mergesort(arr,i,mid);
        mergesort(arr,mid+1,j);
        
        merge(arr,i,mid,j);
    }
}

int main() {
    int arr[10] = {3,2,4,5,-1,9,1,6,0,7}; // for arr length 10
    mergesort(arr,0,9);
    for(int i = 0; i<10; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
