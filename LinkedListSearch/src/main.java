
public class main {

	public static void main(String[] args) {
		NAW obj1 = new NAW();
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
		list.addLinkAtStart(d);
	}

}
