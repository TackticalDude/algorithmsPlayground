
public class history{
	doubleLinkedList list;
	doubleLink current;
	public history(doubleLinkedList list)
	{
		this.list = list;
		this.current = list.getEnd();
	}
	
	
	public void undo()
	{
		current = current.getPrev();
	}
	
	public void redo()
	{
		if(current.getNext() != null)
			current = current.getNext();
	}
	
	public void insert(doubleLink link)
	{
		doubleLink toRemove, nextLink;
		if(current != list.getEnd())
		{
			toRemove = current.getNext(); //still has link because we aint at the end yet
			while(toRemove.getNext() != null)
			{
				nextLink = toRemove.getNext();
				list.removeLink(toRemove);
				toRemove = nextLink;
			}
		}
		
		this.list.addLinkToEnd(link);
	}
	
	
	
	
}
