
public class IntLinkedList {
	private IntLink begin;
	private int length;
	
	/**
	 * @name LinkedList
	 * @param first - first element of list
	 */
	public IntLinkedList(IntLink first){
		begin = first;
		length = 1;
	}
	
	/**
	 * @name addLinkAtStart
	 * @param toAdd - Link to add to beginning of the linked list
	 */
	public void addLinkAtStart(IntLink toAdd){
		toAdd.setNext(begin);
		begin = toAdd;
		length++;
	}
	
	/**
	 * @name addLinkAtEnd
	 * @param toAdd - Link to add at end of the linked list
	 */
	public void addLinkAtEnd(IntLink toAdd){
		for(IntLink i=begin; i!=null; i=i.getNext()){
			if(i.getNext()==null){
				i.setNext(toAdd);
				length++;
				return;
			}
		}
	}
	
	/**
	 * @name removeLinkFromList
	 * @param toRemove - link to remove from linked list
	 */
	public void removeLinkFromList(IntLink toRemove){
		if(toRemove == null) return;
		
		if(toRemove == begin){
			begin = begin.getNext();
			length--;
			return;
		}
		
		for(IntLink i=begin; i!=null; i=i.getNext()){
			if(i.getNext()==toRemove){		//no need to check whether next is null
				i.setNext(i.getNext().getNext());
				length--;
			}
		}
	}
	
	/**
	 * @name setLinkAt
	 * @param index - the index on which the element must be placed
	 * @param toSet - link object to place on de index place
	 * @warning Will overwrite object that already is in the list
	 */
	public void setIntLinkAt(int index, IntLink toSet){
		if(index==0){
			toSet.setNext(begin.getNext());
			begin.setNext(null);
			begin = toSet;
			return;
		}
		
		int indexCounter = 0;
		for(IntLink i=begin; i!=null; i=i.getNext(), indexCounter++){
			if(indexCounter+1==index){
				if(i.getNext()==null){
					toSet.setNext(null);
					i.setNext(toSet);
				}else{
					IntLink temp= i.getNext().getNext();
					i.getNext().setNext(null); //disconnect object from list by setting next to null
					toSet.setNext(temp);
				}
				return;
			}
		}
	}
	
	public void insertIntLinkAt(int index, IntLink toSet){
		if(index==0){
			addLinkAtStart(toSet);
			return;
		}
		
		int indexCounter=0;
		for(IntLink i=begin; i!=null; i=i.getNext(), indexCounter++){
			if(indexCounter+1==index){
				if(i.getNext()==null){
					toSet.setNext(null);
				}else{
					IntLink temp=i.getNext();
					toSet.setNext(temp);
					length++;
				}
				i.setNext(toSet);
				return;
			}
		}
	}
	
	/**
	 * @name getLinkAt
	 * @param index - index of the Link object you are looking for
	 * @return A Link object that on the index element of the linked List, null when index is out of bound
	 */
	public IntLink getIntLinkAt(int index){
		int indexCounter = 0;
		for(IntLink i=begin; i!=null; i=i.getNext()){
			if(indexCounter==index) return i;
			indexCounter++;
		}
		return null;
	}
	
	/**
	 * @name begin
	 * @return the first element of the Linked list
	 */
	public IntLink begin(){
		return begin;
	}
	
	/**
	 * @name length1
	 * @return length of the linked list
	 */
	public int length1(){
		int tempLength = 0;
		for(IntLink i=begin; i!=null; i=i.getNext()){
			tempLength++;
		}
		return tempLength;
	}
	
	/**
	 * @name length2
	 * @return length of the linked list
	 */
	public int length2(){
		return length;
	}
	
	/**
	 * @name bubbleSortLinkedList
	 */
	public void bubbleSortLinkedList(){
		int counter = 0;
		boolean isArraySorted  = false;
		while(!isArraySorted){
			isArraySorted = true;
			for (int i = 0; i < length-counter; i++) {
				IntLink temp = getIntLinkAt(i);
				IntLink temp2 = getIntLinkAt(i + 1);
				if (temp == null || temp2 == null) {

				} else {
					if (temp.getCurr() > temp2.getCurr()) {
						isArraySorted = false;
						setIntLinkAt(i + 1, temp);
						insertIntLinkAt(i, temp2);
					}
				}
			}
			counter++;
		}
		
	}
	
	public void printIntList(){
		for(int i=0; i<length2();i++){
			IntLink temp = getIntLinkAt(i);
			if(temp!=null){
				System.out.println(+i +":" +temp.getCurr());
			}else{
				break;
			}
		}
		System.out.println("----------------------------------------");
	}
}
