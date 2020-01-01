//
//  main.cpp
//  quicksort
//
//  Created by herman rai on 10/7/19.
//  Copyright © 2019 herman rai. All rights reserved.
//

#include <iostream>
using namespace std;

//taken from introduction to algorthims 3rd edition THOMAS H. CORMEN, CHARLES E. LEISERSON, RONALD L.RIVEST, AND CLIFFORD STEIN.



//QUICKSORT.A; p; r/

//1 ifp<r

//2 q D PARTITION.A; p; r/

//3 QUICKSORT.A; p; q 􏰃 1/

//4 QUICKSORT.A; q C 1; r/

//PARTITION.A; p; r/

//1 xDAŒr􏰌 2iDp􏰃1

//3 4 5 6 7 8

//forjDptor􏰃1 if AŒj 􏰌 􏰀 x

//iDiC1

//exchange AŒi 􏰌 with AŒj 􏰌 exchange AŒi C 1􏰌 with AŒr􏰌

//returniC1










int partition (int *a, int start, int end) { // our partition, is taking in array starting and ending
    
    int i=start-1; // i is initialized to start - 1
    int j=start;   // and j is initialized to the start
    int pivot = a[end];
    
    for (;j<end;j++) {
        if(a[j] <= pivot) { // if it is located a value that is less than the pivot element.
            i++;
            swap(a[i],a[j]); // adding to region 1 and then swapping
            
        }
    }
    // now all that is happening is that it will bring the pivot element to the sorted position.
    swap(a[i+1],a[end]);
    return i+1;
    
}

void quick_Sort(int *a, int start, int end) {
    if(start>=end) {
        return;
    }
    
    int p = partition(a,start,end); // here we need to locate our pivot element index using the partition method it takes in our array, start, and ending.
    
    quick_Sort(a,start,p-1);
    
    quick_Sort(a,p+1,end);
}

int main() {
    int size;
    int arr[50000];
    int i;
    
    cin>>size;
    
    for (i=0; i < size; i++) {
        cin>>arr[i];
    }
    
    quick_Sort(arr,0,size-1);
    
    for (i=0; i<size; ++i) {
        cout<<arr[i]<<";";
    }
    
    
    
    
    
    
}











