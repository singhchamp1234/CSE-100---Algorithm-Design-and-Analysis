//
//  yourid.cpp
//  ghghghghg
//
//  Created by herman rai on 10/1/19.
//  Copyright © 2019 herman rai. All rights reserved.
//

//
//  main.cpp
//  gggggg
//
//  Created by herman rai on 9/29/19.
//  Copyright © 2019 herman rai. All rights reserved.
//

#include<iostream>

using namespace std;


//MAX-HEAPIFY.A;i/
// 1 2 3 4 5 6 7 8 9
//10
//l D LEFT.i/
//r D RIGHT.i/
//if l 􏰑 A:heap-size and AŒl􏰄 > AŒi􏰄
//largest D l else largest D i
//if r 􏰑 A:heap-size and AŒr􏰄 > AŒlargest􏰄 largest D r
//if largest ¤ i
//exchange AŒi􏰄 with AŒlargest􏰄 MAX-HEAPIFY.A;largest/


// pseudocode from page 150-155 of introduction to algorithms 3rd edition


void maxHeap(int array[], int n, int i) { // taking in - array, int n, and variable i
    int largest = i; // declaring our largest variable to be equal to i
    // now we need to calculate the left and right child of our largest value
    
    int right = 2 * i+ 2; // this is how we would get our right value
    
    int k;   // this declaring the temporary value of k
    
    int left = 2 * i + 1; // this is how we would get our left value
    
    while (left < n && array[left] > array[largest]) { // if l is greater then its the largest
        largest = left;
    }
    while (right < n && array[right] > array[largest]) { // if r is greater than its the largest
        largest = right;
    }
    if (largest != i) {
        // swapping begins
            k = array[i];
        
            array[i] = array[largest];
        
            array[largest] = k;
        
            maxHeap(array, n, largest);
        }
    }
    
   
void heapSort(int array[], int size) {    // we are passing in the array and the total number of elements
   int temp;
    
   for (int i = size / 2 - 1; i >= 0; i--)  // This step for the building process of maxheap
       
      maxHeap(array, size, i);
    
   for (int i = size - 1; i >= 0; i--) {   // This step is for deleting element from max heap
       // swapping below
      temp = array[0];
       
      array[0] = array[i];
       
      array[i] = temp;
       
      maxHeap(array, i, 0);
   }
}
int main() {
   int size;     // declares size to be an integer

   int arr[50000];  // declares and allow maximum value
    
   int i;    // declares i to be an integer
    
    cin>>size;   // takes input for size
   
    for (i = 0; i < size; i++){  // increments one by one based upon the size
        cin>>arr[i];
    }
       heapSort(arr, size);   // calls heapSort function
      
       for (i = 0; i < size; ++i)
          cout<<arr[i]<<";";   // prints out the sorted array
    }


