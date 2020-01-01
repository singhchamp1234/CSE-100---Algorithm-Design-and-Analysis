//
//  hrai2.cpp
//  mersortboi
//
//  Created by Harman CS on 9/14/19.
//  Copyright © 2019 Harman CS. All rights reserved.
//

#include <iostream>
using namespace std;
#include<string>

void Merge(int a[], int start, int middle, int end) {   // pseudocode from pages 30 - 35 of introduction to algorithms 3rd edition
    int i;
    int j;
    int k;
    
    int n1 = middle-start+1;  // n1 size of L[]
    int n2 = end-middle;
    // n2 size of R[]
    int L[n1];
    int R[n2];
    
    for (i = 0; i < n1; i++) {
        L[i] = a[start + i];       // moves array elements into L[]
    }
    
    for(j = 0; j < n2; j++) {
        R[j] = a[middle+1+j];      // moves array elements into R[]
    }
    i = 0;
    
    j = 0;
     // here we are checking our elements from left array and right array and checking which one smaller and incrementing our k value each time, and also our left and right array
    for (k=start; i<n1 && j<n2; k++) {
        if (L[i] < R[j]) {
            a[k] = L[i++];
        }
        else {
            a[k] = R[j++];
        }
    }
   
    while (i<n1) {
        a[k++] = L[i++];
    }
    
    while (j<n2) {
        a[k++] = R[j++];
    }
}
    
     void merge_Sort(int a[], int start, int end) {   // pseudocode from pages 30 - 35 of introduction to algorithms 3rd edition
    if(start < end) {   // if our start value is less than the end then apply merge sort
        int middle = (start+end)/2;  // this is to locate our middle value in the array add start and end devide by 2.
        merge_Sort(a,start,middle);  // this is to indicate our left side of our array.
        merge_Sort(a,middle+1,end);  // this is to indicate our right side of our array.
        Merge(a, start, middle, end); // Merge the two halves that we have now.
        
    }
}

 int main() {
    int i;
    int n,a[1000];
     cin>>n;    // cin>>n; takes in the size of the array we will be inputting.
    
     for (int i=0; i<n; i++) {
         cin>>a[i];        // add the array values one by one for the size we have selected
     }
    merge_Sort(a, 0, n-1);  // merge_sort our array of values
     int checker = a[0];
     cout << a[0] << ";";
    for(i=1; i<n; i++) {
//       if(a[i] != checker) {      // removed this code, this code was added to check for duplicates in a sorted array
           cout<<a[i]<<";";
//           checker = a[i];
//    }
        
    }
     
}







