public class main {

	public static int findNumber(int a[], int number, int startIndex){
		int reverse = 1;
		if(startIndex < 0) reverse = -1;
		
		for(int i=(startIndex*reverse); i<a.length*reverse;i+=reverse)
			if(a[i]==number) return i;
		return -1;
	}
	
	public static int getIndex(int a[], int number){
		int half_size = (0 + a.length) / 2;
		int prev_half_size = half_size;
		while(true){
			System.out.println(half_size);
			int compValue = 0;
			if(number < a[half_size]) compValue = -1;
			else if(number > a[half_size]) compValue = 1;

			if (compValue < 0) half_size /= 2;
			else if (compValue > 0) half_size = half_size + (half_size / 2);
			else return half_size;
			
			if(half_size == prev_half_size) return 0-half_size;
			prev_half_size = half_size;
		}
	}
	
	public static void main(String[] args) {
		int a[] = new int[100];
		for(int i=0;i<100;i++){
			a[i] = i+1;
		}
		for(int i=0;i<100;i++){
			getIndex(a,98);
		}
		/*System.out.println("----------------------------");
		for(int i=0;i<100;i++){
			System.out.println(getIndex(a,89));
		}*/
		/*String test1 = "abce";
		String test2 = "bbcd";
		
		System.out.println(test1.compareTo(test2));*/
		
		/*NAW intstance1 = new NAW();
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
		array.printArray();*/
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
