/**
 * @author Jorg de Bont en Zakaria el Barnoussi
 * @version 0.1
 * @date 11-05-2015
 */

public class ArraySorter {
	
	/**
	 * @name sortArray
	 * @param arrayToSort - the array that should be sorted
	 * @param startPosition - the position to start to sort
	 * @brief this function sorts an array of integers from the last element to the first element in a ascending order
	 */
	public void simpleBubbleSort(int arrayToSort[], int startPosition){
		int newStartPosition = startPosition;
		boolean isArraySorted = false;
		while(!isArraySorted){
			isArraySorted = true;						//set value to check wheter array is sorted
			for(int i=newStartPosition; i>0; i--){		
				if(arrayToSort[i]<arrayToSort[i-1]){	//if the left value is smaller than the right value
					isArraySorted = false;				//set to false to make it loop again thru the array
					int temp = arrayToSort[i-1];		//store the value in a temp int
					arrayToSort[i-1] = arrayToSort[i];	//swap elements
					arrayToSort[i] = temp;				//swap elements
				}
			}
			newStartPosition -= 1;	//The last element does not have to be checked
		}
	}
	
	/**
	 * @name 
	 * @param arrayToSort
	 * @param startPosition
	 */
	public void insertionSort(int arrayToSort[], int startPosition){
		int newStartPosition = startPosition;
		while(newStartPosition != 0){
			int largestValueIndex = 0;
			for(int i=newStartPosition; i>=0; i--){
				if(arrayToSort[i]>arrayToSort[largestValueIndex]) largestValueIndex = i;
			}
			
			int temp = arrayToSort[newStartPosition];
			arrayToSort[newStartPosition] = arrayToSort[largestValueIndex];
			arrayToSort[largestValueIndex] = temp;
			
			newStartPosition--;
		}
	}
}
