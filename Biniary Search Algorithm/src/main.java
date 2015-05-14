public class main {

	public static void main(String[] args) {
		/*String test1 = "abce";
		String test2 = "bbcd";
		
		System.out.println(test1.compareTo(test2));*/
		
		NAW intstance1 = new NAW();
		NAW intstance2 = new NAW();
		NAW intstance3 = new NAW();
		NAW intstance4 = new NAW();
		NAW intstance5 = new NAW();
		NAW intstance6 = new NAW();
		
		intstance1.setAdres("gadres");
		intstance1.setName("cname");
		intstance1.setWoonplaats("bwoonplaats");
		
		intstance2.setAdres("badres");
		intstance2.setName("aname");
		intstance2.setWoonplaats("cwoonplaats");
		
		intstance5.setAdres("aadres");
		intstance5.setName("vname");
		intstance5.setWoonplaats("gwoonplaats");
		
		intstance3.setAdres("cadres");
		intstance3.setName("bname");
		intstance3.setWoonplaats("vwoonplaats");
		
		intstance4.setAdres("aadres");
		intstance4.setName("cname");
		intstance4.setWoonplaats("gwoonplaats");
		
		intstance6.setAdres("gadres");
		intstance6.setName("bname");
		intstance6.setWoonplaats("vwoonplaats");
		
		NAWarray array = new NAWarray();
		array.printArray();
		array.addNAWtoArray(intstance1);
		array.addNAWtoArray(intstance2);
		array.addNAWtoArray(intstance3);
		array.addNAWtoArray(intstance4);
		array.addNAWtoArray(intstance5);
		array.addNAWtoArray(intstance6);
		array.printArray();
		
		ArraySorter ars = new ArraySorter();
		ars.bubbleSortNAWArray(array);
		System.out.println("---------------------------------");
		array.printArray();
		/*
		int lowerBound = 0 , nElems = 8;
		int upperBound = nElems-1;
		int curIn = 0;
		int searchKey = 39;
		int a[] = {1,3,6,10,15,21,28,0,0,0,0}; 
		
		while(true){
			curIn = (lowerBound + upperBound)/2;
			if(a[curIn]==searchKey){
				System.out.println("currIn: "+curIn);
				break;
			}else if(lowerBound > upperBound){
				System.out.println("nElems: "+nElems+" upperBound: "+upperBound+" lowerBound: "+lowerBound);
				break;
			}else{
				if(a[curIn] < searchKey)lowerBound = curIn + 1;
				else upperBound = curIn - 1; //
			}
		}*/
	}
}
