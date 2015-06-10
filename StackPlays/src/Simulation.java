public class Simulation {
	private int registerAmount; // amount of queues
	private int totalCustomerCount; // total amount of customers in simulation
	private int registerProssesing; // processing speed of queues
									// customers/timestamp
	private int timeStamp;

	QueueLink begin;
	QueueLink end;

	public Simulation() {
		registerAmount = 0;
		totalCustomerCount = 0;
		registerProssesing = 0;
		timeStamp = 0;
	}

	public void startSimulation(int regAmount, int maxCustomers,
			int maxRegPros, int simulationTime) {
		if (regAmount == 0) {
			System.exit(0);
		}
		QueueLink begin = new QueueLink(new Queue(maxCustomers, maxRegPros));
		this.begin = begin;
		end = begin;
		for (int i = 1; i < regAmount; i++) {
			QueueLink toAdd = new QueueLink(new Queue(maxCustomers, maxRegPros));
			end.setNext(toAdd);
			end = toAdd;
		}

		// loop for till simulationTime exceeded
		while (true) {
			if(timeStamp>simulationTime){
				System.exit(0);
			}
			sleep(1500);
			int counter = 0;
			for(QueueLink i=begin; i!=null; i=i.getNext(),counter++){
				i.getCurrent().addCustomers(maxCustomers);
				i.getCurrent().processCustomer();
				System.out.print("Queue " +counter +": ");
				i.getCurrent().printStatus();
			}
			timeStamp++;
		}
	}

	public void printSimulation() {
		int customerCount = 0;
		for (QueueLink i = begin; i.getNext() != null; i = i.getNext()) {
			customerCount = i.getCurrent().getCount();
		}
		System.out.println(customerCount);
	}

	public void addQueue(Queue toAdd) {
		QueueLink add = new QueueLink(toAdd);
		if (begin == null) {
			begin = add;
			end = begin;
		} else {
			end.setNext(add);
			end = add;
			add.setNext(null);
		}
	}

	void sleep(int ms) {
		try {
			Thread.sleep(ms);
		} catch (InterruptedException ex) {
			Thread.currentThread().interrupt();
		}
	}

	public int getRegisterProssesing() {
		return registerProssesing;
	}

	public void setRegisterProssesing(int registerProssesing) {
		this.registerProssesing = registerProssesing;
	}

	public int getTotalCustomerCount() {
		return totalCustomerCount;
	}

	public void setTotalCustomerCount(int totalCustomerCount) {
		this.totalCustomerCount = totalCustomerCount;
	}

	public int getRegisterAmount() {
		return registerAmount;
	}

	public void setRegisterAmount(int registerAmount) {
		this.registerAmount = registerAmount;
	}
}
