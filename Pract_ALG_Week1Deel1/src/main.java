
public class main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		NAW intstance1 = new NAW();
		NAW intstance2 = new NAW();
		NAW intstance3 = new NAW();
		NAW intstance4 = new NAW();
		
		intstance1.setAdres("adres1");
		intstance1.setName("name1");
		intstance1.setWoonplaats("woonplaats1");
		
		intstance2.setAdres("adres2");
		intstance2.setName("name2");
		intstance2.setWoonplaats("woonplaats2");
		
		intstance3.setAdres("adres3");
		intstance3.setName("name3");
		intstance3.setWoonplaats("woonplaats3");
		
		intstance4.setAdres("adres3");
		intstance4.setName("name4");
		intstance4.setWoonplaats("woonplaats3");
		
		NAWarray array = new NAWarray();
		array.printArray();
		array.addNAWtoArray(intstance1);
		array.addNAWtoArray(intstance2);
		array.addNAWtoArray(intstance3);
		array.addNAWtoArray(intstance3);
		array.addNAWtoArray(intstance4);
		array.addNAWtoArray(intstance3);
		array.addNAWtoArray(intstance3);
		array.printArray();
		
		System.out.println("------------------------------------");
		array.removeFirstInstanceByName("name3");
		array.printArray();
		System.out.println("------------------------------------");
		array.removeLastInstanceByName("name3");
		array.printArray();
		System.out.println("------------------------------------");
		array.removeAllInstancesByName("name3");
		array.printArray();
		
		
	}

}
