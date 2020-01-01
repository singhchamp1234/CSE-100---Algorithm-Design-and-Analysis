#include <iostream>
using namespace std;


// function to calculate the maximum subarray sum
int FIND_MAXIMUM_SUBARRAY(int A[], int low, int high);
//Implementation of function 'FIND_MAX_CROSSING_SUBARRAY'
int FIND_MAX_CROSSING_SUBARRAY(int A[], int low, int mid, int high);


int main()
{
    //declaring the variables
    int n;
    int sum;
    //initialize array
    int A[600000];
    cin >> n;
    //input taken by the user
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    //calling function to find max sub array
    cout<< FIND_MAXIMUM_SUBARRAY(A, 0, n-1);
    return 0;
}
// base case: only one element
//FIND-MAXIMUM-SUBARRAY.A; low; mid/ .right-low; right-high; right-sum/ D
//FIND-MAXIMUM-SUBARRAY.A; mid C 1; high/ .cross-low; cross-high; cross-sum/ D
//FIND-MAX-CROSSING-SUBARRAY .A; low; mid; high/ if left-sum 􏰄 right-sum and left-sum 􏰄 cross-sum
//return .left-low; left-high; left-sum/
//elseif right-sum 􏰄 left-sum and right-sum 􏰄 cross-sum
//return .right-low; right-high; right-sum/ else return .cross-low; cross-high; cross-sum/
// function to calculate the maximum subarray sum
int FIND_MAXIMUM_SUBARRAY(int A[], int low, int high)
{
    if (high == low) // base case
    {
        return A[high];
    }
    
    else
    {
        int mid, maxLeftSubArray, maxRightSubArray, maxCrossingSubArray;
        
        //calculate mid
        mid = (high + low) / 2;
        
        //find left max
        maxLeftSubArray = FIND_MAXIMUM_SUBARRAY(A, low, mid);
        
        //find right max
        maxRightSubArray = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high);
        
        //find cross max
        maxCrossingSubArray = FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high);
        
        //check max sum
        if (maxLeftSubArray >= maxRightSubArray && maxLeftSubArray >= maxCrossingSubArray)
            return maxLeftSubArray;
        else if (maxRightSubArray >= maxLeftSubArray && maxRightSubArray >= maxCrossingSubArray)
            return maxRightSubArray;
        return maxCrossingSubArray;   //return max sum
    }
}

//Implementation of function 'FIND_MAX_CROSSING_SUBARRAY'
int FIND_MAX_CROSSING_SUBARRAY(int A[], int low, int mid, int high)
{
    //declare and initialize variables
    int leftArraySum = -600000;
    int rightArraySum = leftArraySum;
    int sum = 0;
    
    //loop for start to mid
    for (int i = mid; i >= low; i--)
    {
        sum = sum + A[i];
        if (sum > leftArraySum)
        {
            leftArraySum = sum;
        }
    }
    sum = 0;
    
    //loop for mid to end
    for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + A[i];
        if (sum > rightArraySum)
        {
            rightArraySum = sum;
        }
        
    }
    
    //calculate total sum
    sum = leftArraySum + rightArraySum;
    return sum;     //return sum
}
