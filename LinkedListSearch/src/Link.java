
public class Link {
	private NAW curr;
	private Link next;
	
	public Link(NAW obj){
		curr = obj;
		next = null;
	}
	
	public NAW getCurr() {
		return curr;
	}
	
	public void setCurr(NAW curr) {
		this.curr = curr;
	}
	
	public Link getNext() {
		return next;
	}
	
	public void setNext(Link next) {
		this.next = next;
	}
}
