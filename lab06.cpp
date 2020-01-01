#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

// psucode taken from pages 190-200
// collaborated with jesus vera
// of introduction to algorthims 3rd edition

//This is the function used for taking input from user, so we are able to set up our arrays and get the size/values


// RADIX-SORT.A;d/ 1 foriD1tod
//2 use a stable sort to sort array A on digit i


//letBŒ0::n􏰐1􏰃beanewarray n D A: length foriD0ton􏰐1
//make BŒi􏰃 an empty list foriD1ton
//insert AŒi􏰃 into list BŒbnAŒi􏰃c􏰃 foriD0ton􏰐1
//sort list BŒi􏰃 with insertion sort
//concatenate the lists B Œ0􏰃; B Œ1􏰃; : : : ; B Œn 􏰐 1􏰃 together in order





void takingInputFromUser(vector<int> arrayOfVectors[], int SIZE)
{
	int curentColumns;             //variables for storage value of current columns
	for (int i = 0; i < SIZE; i++) // increments each time, for less than size
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> curentColumns;
			arrayOfVectors[i].push_back(curentColumns);//store values
		}
	}
}



void sortingArray(int low, int high, vector<int> arrayOfVectors[])
{
	int tempArray[10] = { 0 };   //temporary array, that is being held
	vector<int>* arr = new vector<int>[low];   

	for (int i = 0; i < low; i++)  // increment one by one for less than our array
	{
		//initialize array
		tempArray[arrayOfVectors[i][high] % 10]++;
	}

	for (int i = 1; i < 10; i++)
	{
		//update array
		tempArray[i] = tempArray[i] + tempArray[i - 1]; // i - 1 then update
	}

	for (int i = low - 1; i >= 0; i--)
	{
		//update each array of vectors
		arr[tempArray[arrayOfVectors[i][high] % 10] - 1] = arrayOfVectors[i];
		tempArray[arrayOfVectors[i][high] % 10]--;
	}

	for (int i = 0; i < low; i++)
	{

		//store value to vectors array
		arrayOfVectors[i] = arr[i];
	}


}

//Function of Radix sort
void sort(vector<int> sortArray[], int value)
{
	for (int i = 10 - 1; i >= 0; i--)
		sortingArray(value, i, sortArray); //functin call
}



//This is the function used for display values
void displayValues(vector<int> arrayOfVectors[], int SIZE)
{

	//display each values
	for (int i = 0; i < SIZE; i++)
	{
		for (vector<int>::iterator itr = arrayOfVectors[i].begin(); itr != arrayOfVectors[i].end(); itr++)
		{
			cout << *itr << ";";
		}
		cout << endl;
	}

}


//Driver Function
int main()
{
	int size;     //variables for storing vales
	cin >> size;    
	vector<int>* v = new vector<int>[size];
	takingInputFromUser(v, size);
	sort(v, size);    //sort values
	displayValues(v, size);   //function call
	return 0;
}


