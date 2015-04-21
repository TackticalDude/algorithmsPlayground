/**
 * 
 * @author Jorg de Bont en Zakaria el Barnoussi
 * @version 0.1
 * @date 20-04-2015
 */

public class NAWSortedArray extends NAWarray{
	
	/**
	 * @name getIndexByNAW
	 * @param toSearch - the object that needs to be found
	 * @return a positive index number when the object is found. A negative object number when the object is not found
	 * 			the negative number is the last place the function searched (can be used to add a NAW object)
	 */
	int getIndexByNAW(NAW toSearch){
		int half_size = (0 + arraynaw_size) / 2;
		int prev_half_size = half_size;
		while(true){
			int compValue = toSearch.compareTo(arrayNaw[half_size]);
			if (compValue < 0) half_size /= 2;
			else if (compValue > 0) half_size = half_size + (half_size / 2);
			else return half_size;
			
			if(half_size == prev_half_size) return 0-half_size;
			prev_half_size = half_size;
		}
	}
	
	/**
	 * @name clearIndex
	 * @param index - the index that should be cleared
	 * @return the cleared array position or -1 when the array is full or -1 when the function failed
	 * @brief Clear the position in the array by moving the other object one position
	 */
	int clearIndex(int index){
		if(index+1>arraynaw_size || index<0) return -1;
		for(int i=arraynaw_size; i>index; i--){
			arrayNaw[i] = arrayNaw[i-1];
			if(i-1==index) return i;
		}
		return -1;
	}
	
	/**
	 * @name addNAWSorted
	 * @param toAdd - the naw object that should be added to the array
	 * @return a negative index number if the list already contains a object like the toAdd parameter
	 * 			a positive index number if the object is succesfully added to the list
	 */
	int addNAWSorted(NAW toAdd){
		int index = getIndexByNAW(toAdd);
		if(index < 0) index*=-1;
		else return index;
		
		if(index == clearIndex(index)) addNAWToArrayInPos(toAdd, index);
		return index;
	}
	
	/**
	 * @name removeNAWByValues
	 * @param woonplaats - woonplaats in string format
	 * @param adres - adres in string format
	 * @param name - name in string format
	 * @return -1 when the object is not found, a positive index number when the object is removed succesfully
	 */
	int removeNAWByValues(String woonplaats, String adres, String name){
		NAW toRemove = new NAW();
		toRemove.setWoonplaats(woonplaats);
		toRemove.setAdres(adres);
		toRemove.setName(name);
		
		int index = getIndexByNAW(toRemove);
		if(removeNAWByIndex(index)) return index;
		else return -1;
	}
	
	/**
	 * @name removeNAWByIndex
	 * @brief replaces the object on de index of the arraynaw by the last instance of array
	 * @param index - index of instance that should be deleted
	 * @return true when completed the replacement
	 * @brief deletes object from array and moves all the other objects
	 */
	boolean removeNAWByIndex(int index){
		if(index<0||index>arraynaw_size) return false;
		
		if(arrayNaw[index].getName().isEmpty() 
				&& arrayNaw[index].getAdres().isEmpty() 
				&& arrayNaw[index].getWoonplaats().isEmpty()) return false;
		
		for(int i=index; i<arraynaw_size; i++){
			arrayNaw[index] = arrayNaw[index+1];
		}
		arraynaw_size--;
		return true;
	}
}
