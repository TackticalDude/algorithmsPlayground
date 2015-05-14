/**
 * 
 * @author Jorg de Bont en Zakaria el Barnoussi
 * @version 0.1
 * @date 20-04-2015
 */

public class NAW {
	private String name;
	private String adres;
	private String woonplaats;
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getAdres() {
		return adres;
	}
	
	public void setAdres(String adres) {
		this.adres = adres;
	}
	
	public String getWoonplaats() {
		return woonplaats;
	}
	
	public void setWoonplaats(String woonplaats) {
		this.woonplaats = woonplaats;
	}
	
	public boolean hasName(){
		return !name.isEmpty();
	}
	
	public boolean hasAdres(){
		return !adres.isEmpty();
	}
	
	public boolean hasWoonplaats(){
		return !woonplaats.isEmpty();
	}
	/**
	 * @name compareTo
	 * @param anotherNaw - compare the object that calls the function with the object in the parameter.
	 * @return -3 when only the woonplaats is not the same. -2 when woonplaats is the same. 
	 * 			-1 when woonplaats and name are the same and 0 when the name,woonplaats and adres are the same.
	 */
	public int compareTo(NAW anotherNaw){
		int compareVal;
		compareVal = this.getWoonplaats().compareTo(anotherNaw.getWoonplaats());
		if(compareVal > 0) return 3;
		else if(compareVal < 0) return -3;
		
		compareVal = this.getName().compareTo(anotherNaw.getName());
		if(compareVal > 0) return 2;
		else if(compareVal < 0) return -2;
		
		compareVal = this.getAdres().compareTo(anotherNaw.getAdres());
		if(compareVal > 0) return 1;
		else if(compareVal < 0) return -1;
		
		return 0;
	}
}
