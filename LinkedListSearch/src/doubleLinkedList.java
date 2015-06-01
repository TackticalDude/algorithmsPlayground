
public class doubleLinkedList {
	private doubleLink begin;
	private doubleLink end;
	private int listLength;
	
	public doubleLinkedList(doubleLink begin)
	{
		this.begin = begin;
		this.end = begin;
		this.listLength = 1;
	}
	
	public doubleLink getBegin() {
		return begin;
	}

	public doubleLink getEnd() {
		return end;
	}

	public void addLinkToStart(doubleLink toAdd)
	{
		this.begin.setPrev(toAdd);
		if(this.begin != null)
		{
			toAdd.setNext(this.begin);
		}
		this.begin = toAdd;
		this.listLength++;
	}
	
	public void addLinkToEnd(doubleLink toAdd)
	{
		if(this.end == null)
		{
			this.begin = toAdd;
			this.end = toAdd;
		}
		
		toAdd.setPrev(this.end);
		this.end.setNext(toAdd);
		this.end = toAdd;
		this.listLength++;
	}
	
	public void removeLink(doubleLink toRemove)
	{
		if(toRemove == null) return;
		
		if(toRemove == this.begin)
		{
			begin = begin.getNext();
			this.listLength--;
			return;
		}
		toRemove.getNext().setPrev(toRemove.getPrev());
		toRemove.getPrev().setNext(toRemove.getNext());
		this.listLength--;
	}
	
	public doubleLink getLinkAt(int index){
		int indexCounter = 0;
		for(doubleLink i=begin; i!=null; i=i.getNext()){
			if(indexCounter==index) return i;
			indexCounter++;
		}
		return null;
	}
	
	public void bubbleSortList()
	{
		int counter = listLength;
		int tempVal;
		doubleLink first, second;
		boolean isArraySorted  = false;
		while(!isArraySorted)
		{
			isArraySorted = true;
			first = begin;
			second = begin.getNext();
			for(int i = 0; i < counter; i++)
			{
				if(first == null || second == null)
				{
					
				}
				else
				{
					if(first.getCurrent() > second.getCurrent())
					{
						isArraySorted = false;
//						second.setPrev(first.getPrev());
//						first.setPrev(second);
//						first.setNext(second.getNext());
//						second.setNext(first);
						tempVal = first.getCurrent();
						first.setCurrent(second.getCurrent());
						second.setCurrent(tempVal);
						
					}				
					first = second;
					second = first.getNext();
				}
			}
			counter--;
		}		
	}
	
	public void printList()
	{
		doubleLink toPrint;
		toPrint = this.begin;
		while(toPrint != null)
		{
			System.out.println(toPrint.getCurrent());
			toPrint = toPrint.getNext();
		}
	}
	
}
