/**
 * 
 * @author Jorg de Bont en Zakaria el Barnoussi
 * @version 0.1
 * @date 20-04-2015
 */

public class NAWarray {
	protected NAW arrayNaw[] = new NAW[20];
	protected int arraynaw_size = 0;
	
	/**
	 * @name addNAWtoArray
	 * @param naw - NAW object that should be added to the array
	 */
	void addNAWtoArray(NAW naw){
		arrayNaw[arraynaw_size++] = naw;
	}
	
	/**
	 * @name addNAWToArrayInPos
	 * @param naw - NAW object that should be added to the array
	 * @param index - the position of the added object in the array
	 */
	void addNAWToArrayInPos(NAW naw, int index){
		arrayNaw[index] = naw;
		arraynaw_size++;
	}
	
	/**
	 * @name getIndexByName
	 * @param nameInput - name of the instance in String format
	 * @param startIndex - the index on wich to start to search (give a negative number to apply reverse search)
	 * @return -1 when instance is not found, returns index when of adres is found
	 */
	int getIndexByName(String nameInput, int startIndex){
		int reverse = 1;
		if(startIndex < 0) reverse = -1;
		
		for(int i=(startIndex*reverse); i<arraynaw_size;i+=reverse)
			if(arrayNaw[i].getName().equals(nameInput)) return i;
		return -1;
	}
	
	/**
	 * @name getIndexByAdres
	 * @param adresInput - adres in string format
	 * @param startIndex - the index on wich to start to search (give a negative number to apply reverse search)
	 * @return -1 when instance is not found, returns index when of adres is found
	 */
	int getIndexByAdres(String adresInput, int startIndex){
		int reverse = 1;
		if(startIndex < 0) reverse = -1;
		
		for(int i=(startIndex*reverse); i<arraynaw_size;i+=reverse)
			if(arrayNaw[i].getAdres().equals(adresInput)) return i;
		return -1;
	}
	
	/**
	 * @name getIndexByWoonplaats
	 * @param woonplaatsInput - woonplaats in string format
	 * @param startIndex - the index on wich to start to search (give a negative number to apply reverse search)
	 * @return -1 when instance is not found, returns index when of woonplaats is found
	 */
	int getIndexByWoonplaats(String woonplaatsInput, int startIndex){
		int reverse = 1;
		if(startIndex < 0) reverse = -1;
		
		for(int i=(startIndex*reverse); i<arraynaw_size;i+=reverse)
			if(arrayNaw[i].getWoonplaats().equals(woonplaatsInput)) return i;
		return -1;
	}
	
	/**
	 * @name getIndexByWpAdress
	 * @param adresInput - adres in string format
	 * @param woonplaatsInput - woonplaats in string format
	 * @param startIndex - the index on wich to start to search (give a negative number to apply reverse search)
	 * @return -1 when instance is not found, returns index when of adres is found
	 */
	int getIndexByWpAdress(String adresInput, String woonplaatsInput, int startIndex){
		int reverse = 1;
		if(startIndex < 0) reverse = -1;
		
		for(int i=(startIndex*reverse); i<arraynaw_size;i+=reverse)
			if(arrayNaw[i].getAdres().equals(adresInput) 
					&& arrayNaw[i].getWoonplaats().equals(woonplaatsInput)) return i;
		return -1;
	}
	
	/**
	 * @name removeNAWByIndex
	 * @brief replaces the object on de index of the arraynaw by the last instance of array
	 * @param index - index of instance that should be deleted
	 * @return true when completed the replacement
	 */
	boolean removeNAWByIndex(int index){
		if(arrayNaw[index].getName().isEmpty() 
				&& arrayNaw[index].getAdres().isEmpty() 
				&& arrayNaw[index].getWoonplaats().isEmpty()) return false;
		
		if(index == arraynaw_size-1) arrayNaw[index] = null;
		else arrayNaw[index] = arrayNaw[arraynaw_size-1];
		
		arraynaw_size--;
		return true;
	}
	
	/**
	 * @name removeFirstInstanceByName
	 * @param nameInput - name of the instance in String format
	 * @return true when deletion is completed and -1 when name is not in list
	 */
	boolean removeFirstInstanceByName(String nameInput){
		int index = getIndexByName(nameInput, 0);
		if(index == -1) return false;
		else removeNAWByIndex(index);
		
		return true;
	}
	
	/**
	 * @name removeLastInstanceByName
	 * @param nameInput - name of the instance in String format
	 * @return true when deletion is completed and -1 when name is not in list
	 */
	boolean removeLastInstanceByName(String nameInput){
		int index = getIndexByName(nameInput, 1-arraynaw_size);
		if(index == -1) return false;
		else removeNAWByIndex(index);
		
		return true;
	}
	
	/**
	 * @name removeAllInstancesByName
	 * @param nameInput - name of the instance in String format
	 */
	void removeAllInstancesByName(String nameInput){
		for(int i=0; i<arraynaw_size;i++){
			int index = getIndexByName(nameInput, 0);
			if(index == -1) break;
			removeNAWByIndex(index);
		}
	}
	
	/**
	 * @name removeInstanceByWpAdres
	 * @param adresInput - adres of instance adres in string format
	 * @param woonplaatsInput - woonplaats of instance in string format
	 * @return true when deletion is completed and -1 when name is not in list
	 */
	boolean removeInstanceByWpAdres(String adresInput, String woonplaatsInput){
		int index = getIndexByWpAdress(adresInput, woonplaatsInput, 0);
		if(index == -1) return false;
		else removeNAWByIndex(index);
		
		return true;
	}
	
	/**
	 * @name removeAllInstancesByWpAdres
	 * @param adresInput - adres of instance adres in string format
	 * @param woonplaatsInput - woonplaats of instance adres in string format
	 */
	void removeAllInstancesByWpAdres(String adresInput, String woonplaatsInput){
		for(int i=0; i<arraynaw_size;i++){
			int index = getIndexByWpAdress(adresInput, woonplaatsInput, 0);
			if(index == -1) break;
			removeNAWByIndex(index);
		}
	}
	
	/**
	 * @name printArray
	 * @brief prints the arraynaw array to the console
	 */
	void printArray(){
		for(int i=0; i<arraynaw_size; i++){
			System.out.print(arrayNaw[i].getName());
			System.out.print(arrayNaw[i].getAdres());
			System.out.println(arrayNaw[i].getWoonplaats());
		}
	}
}
