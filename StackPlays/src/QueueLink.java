
public class QueueLink {
	private Queue q;
	private QueueLink next;
	
	public QueueLink(Queue in){
		q = in;
		next = null;
	}
	
	public void setNext(QueueLink n){
		this.next = n;
	}
	
	public void setCurrent(Queue curr){
		this.q = curr;
	}
	
	public Queue getCurrent(){
		return q;
	}
	
	public QueueLink getNext(){
		return next;
	}
}
