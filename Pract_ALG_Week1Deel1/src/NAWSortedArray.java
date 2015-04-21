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
}
