
public class main {

	public static void main(String[] args) {
		/*NAW obj1 = new NAW();
		NAW obj2 = new NAW();
		NAW obj3 = new NAW();
		NAW obj4 = new NAW();
		
		Link a = new Link(obj1);
		Link b = new Link(obj2);
		Link c = new Link(obj3);
		Link d = new Link(obj4);
		
		LinkedList list = new LinkedList(a);
		list.addLinkAtStart(b);
		list.addLinkAtEnd(c);
		list.addLinkAtStart(d);*/
//		int omg = 10000;
//		
//		IntLinkedList list = new IntLinkedList(new IntLink(0));
//		
//		for(int i=0; i<omg; i++){
//			double random = Math.random()*omg*10;
//			IntLink add = new IntLink((int)random);
//			list.addLinkAtStart(add);
//		}
//		list.printIntList();
//		
//		long startTimeBubbleSort = System.nanoTime();
//		list.bubbleSortLinkedList();
//		startTimeBubbleSort = System.nanoTime()-startTimeBubbleSort;
//		
//		list.printIntList();
//		System.out.println(startTimeBubbleSort/1000 +"us");
		
		doubleLink test1 = new doubleLink(6);
		doubleLink test2 = new doubleLink(5);
		doubleLink test3 = new doubleLink(4);
		doubleLink test4 = new doubleLink(1);
		doubleLink test5 = new doubleLink(2);
		doubleLink test6 = new doubleLink(3);
		
		doubleLinkedList test = new doubleLinkedList(test1);
		
		test.addLinkToEnd(test2);
		test.addLinkToEnd(test3);
		test.addLinkToEnd(test4);
		test.addLinkToEnd(test5);
		test.addLinkToEnd(test6);
		
		test.printList();
		test.bubbleSortList();
		System.out.println("-----------");
		test.printList();
		
		
	}

}
