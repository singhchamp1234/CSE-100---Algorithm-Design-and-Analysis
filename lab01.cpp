//
//  main.cpp
//  insertionsorrt
//
//  Created by Harman CS on 9/10/19.
//  Copyright © 2019 Harman CS. All rights reserved.
//

#include <iostream>

using namespace std;
// This is the pseudocode from page 18 of the textbook 3rd edition introduction to algorithms

void insertionSort(int magnitude, int arr[])
{
    int j = 0;                                  // declare our j int to be 0
    
    int temp;                                   // intialize a temporary value
    
    for(int i=1; i<magnitude; i++) {  // for loop that makes our i value start at index postion 1 and increments by 1
        temp = arr[i];             // our temporary value will be the array of i, so to start with we have temp = arr[1]
        j = i - 1;                  // and we are comparing it to the left value which in this case is arr[0] to start
        
        while(j >= 0 && arr[j] >= temp ) // do this while loop, when our arr[j] is greater than our temp, and j not -1
        {
            arr[j+1]=arr[j];            // now we have the shifting occuring
            j = j-1;
        }
        arr[j+1]= temp;             // and shift our temporary value as well
    }
    
}


int main()
{
    int magnitude; // declare our magnitude value as a integer
    
    // already acknowledge that i will be a integer no need to declare the int,  int i;

   
    cin >> magnitude;    // the user input our magnitude
    
    int *arr = new int[magnitude];    // pointer vaue for arr
    
    
    for (int a = 0; a < magnitude; a++) {      // start at zero as long as less than the magnitude implement 1 by 1
        
        cin >> arr[a];
        
        if ( a != NULL)   // does not equal zero than implement the insertion sort, do not implement for negative number
        {
            insertionSort(a + 1, arr);
            
            int i = 0;
            
            while(i < a+1) {
                cout << arr[i] << ";";
                i++;
            }
            
            
            
            cout << endl;
        }
        
    }
    return 0;
    
}

