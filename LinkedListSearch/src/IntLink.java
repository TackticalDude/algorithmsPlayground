
public class IntLink {
	private int curr;
	private IntLink next;
	
	public IntLink(int number){
		curr = number;
		next = null;
	}

	public int getCurr() {
		return curr;
	}

	public void setCurr(int curr) {
		this.curr = curr;
	}

	public IntLink getNext() {
		return next;
	}

	public void setNext(IntLink next) {
		this.next = next;
	}
}
