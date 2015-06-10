
public class CustomerLink {
	Customer curr;
	CustomerLink next;
	
	public CustomerLink(){
		curr = null;
		next = null;
	}
	
	public CustomerLink(Customer curr){
		this.curr = curr; 
		next = null;
	}
	
	public Customer getCurr() {
		return curr;
	}
	
	public void setCurr(Customer curr) {
		this.curr = curr;
	}
	
	public CustomerLink getNext() {
		return next;
	}
	
	public void setNext(CustomerLink next) {
		this.next = next;
	}
	
}
