
public class doubleLink {
	private doubleLink prev;
	private doubleLink next;
	private int current;
	
	public doubleLink(int data)
	{
		this.current = data;
		this.prev = null;
		this.next = null;
	}

	public doubleLink getPrev() {
		return prev;
	}

	public void setPrev(doubleLink prev) {
		this.prev = prev;
	}

	public doubleLink getNext() {
		return next;
	}

	public void setNext(doubleLink next) {
		this.next = next;
	}

	public int getCurrent() {
		return current;
	}

	public void setCurrent(int current) {
		this.current = current;
	}

}
