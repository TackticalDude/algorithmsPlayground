public class Queue {
	private int customerCount; // max amount of customers in queue
	private int customerProsSpeed;// prossecing speed of queue
									// customers/timestamp

	CustomerLink begin;
	CustomerLink end;

	public Queue(int custAmount, int custProsSpeed) {
		customerCount = 0;
		this.customerProsSpeed = custProsSpeed;

		begin = null;
		end = null;
	}

	public int getCount() {
		return customerCount;
	}

	public void push(Customer toPush) {
		CustomerLink toAdd = new CustomerLink(toPush);

		if (begin == null) {
			begin = toAdd;
			end = begin;
		} else {
			end.setNext(toAdd);
			end = toAdd;
		}
		customerCount++;
	}

	public boolean pop() {
		if (begin == null || end == null)
			return false;

		begin = begin.getNext();
		customerCount--;
		return true;
	}

	public CustomerLink peek() {
		return begin;
	}

	public void addCustomers(int amount) {
		for (int i = 0; i < amount; i++) {
			Customer toAdd = new Customer();
			push(toAdd);
		}
	}

	public void processCustomer() {
		for (int i = 0; i < customerProsSpeed; i++) {
			pop();
		}
	}

	public void printStatus() {
		for (int i = 0; i < customerCount; i++) {
			System.out.print("*");
		}
		System.out.println(";");
	}
}
