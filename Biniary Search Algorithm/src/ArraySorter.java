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
			newStartPosition--;	//The last element does not have to be checked
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
	
	/**
	 * @name bubbleSortNAWArray
	 * @param nawArray - NAWarray object
	 */
	public void bubbleSortNAWArray(NAWarray nawArray){
		int outer, inner;
		for (outer = nawArray.getLength()-1; outer > 0; outer--) {
			for (inner = 0; inner < outer; inner++) {
				String name1 = nawArray.getNAWByIndex(inner).getName();
				String name2 = nawArray.getNAWByIndex(inner+1).getName();
				if (name2.compareToIgnoreCase(name1)>=0){				//problem first element does not get sorted??
					nawArray.switchTwoNAWs(inner, inner+1);
				}
			}
		}
		//sort woonplaats
		/*for (outer = nawArray.getLength()-1; outer > 0; outer--) {
			for (inner = 0; inner < outer; inner++) {
				String name1 = nawArray.getNAWByIndex(inner).getWoonplaats();
				String name2 = nawArray.getNAWByIndex(inner+1).getWoonplaats();
				if (name2.compareToIgnoreCase(name1)>=0){
					nawArray.switchTwoNAWs(inner, inner+1);
				}
			}
		}*/
	}
	
	public void insertionSortNAWArray(NAW nawArray[], int startPosition){
		
	}
}
