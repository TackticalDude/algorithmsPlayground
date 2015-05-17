/**
 * @author Jorg de Bont en Zakaria el Barnoussi
 * @version 0.1
 * @date 11-05-2015
 */

public class main {

	public static void main(String[] args) {
		int arrayToSort[] = {7,3,8,1,2,5,4,6,9,0};
		for(int i=0; i<10; i++) System.out.print(arrayToSort[i] + " "); System.out.println("");
		ArraySorter temp = new ArraySorter();
		temp.insertionSort(arrayToSort, 5);
		for(int i=0; i<10; i++) System.out.print(arrayToSort[i] + " ");
//		/* time stamp */
//		long startTimeBubbleSort = System.nanoTime();
//		//System.out.println(startTimeBubbleSort);
//		
//		temp.selectionSort(arrayToSort, arrayToSort.length-1);
//		/* 2nd time stamp */
//		startTimeBubbleSort = System.nanoTime()-startTimeBubbleSort;
//		System.out.println("Nano seconden?: " +startTimeBubbleSort/1000);
//		
//		for(int i=0; i<10; i++) System.out.print(arrayToSort[i] + " ");
	}

}
