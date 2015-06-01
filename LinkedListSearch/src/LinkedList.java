
public class LinkedList {
	private Link begin;
	private int length;
	
	/**
	 * @name LinkedList
	 * @param first - first element of list
	 */
	public LinkedList(Link first){
		begin = first;
		length = 1;
	}
	
	/**
	 * @name addLinkAtStart
	 * @param toAdd - Link to add to beginning of the linked list
	 */
	public void addLinkAtStart(Link toAdd){
		toAdd.setNext(begin);
		begin = toAdd;
		length++;
	}
	
	/**
	 * @name addNAWAtStart
	 * @param toAdd - NAW to add at start of the linked list
	 */
	public void addNAWAtStart(NAW toAdd){
		Link linkToAdd = new Link(toAdd);
		addLinkAtStart(linkToAdd);
	}
	
	/**
	 * @name addNAWAtEnd	
	 * @param toAdd - NAW to add at end of the linked list
	 */
	public void addNAWAtEnd(NAW toAdd){
		Link linkToAdd = new Link(toAdd);
		addLinkAtEnd(linkToAdd);
	}
	
	/**
	 * @name addLinkAtEnd
	 * @param toAdd - Link to add at end of the linked list
	 */
	public void addLinkAtEnd(Link toAdd){
		for(Link i=begin; i!=null; i=i.getNext()){
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
	public void removeLinkFromList(Link toRemove){
		if(toRemove == null) return;
		
		if(toRemove == begin){
			begin = begin.getNext();
			length--;
			return;
		}
		
		for(Link i=begin; i!=null; i=i.getNext()){
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
	public void setLinkAt(int index, Link toSet){
		if(index==0){
			toSet.setNext(begin.getNext());
			begin.setNext(null);
			begin = toSet;
			return;
		}
		
		int indexCounter = 0;
		for(Link i=begin; i!=null; i=i.getNext()){
			if(indexCounter+1==index){
				if(i.getNext()==null){
					toSet.setNext(null);
				}else{
					toSet.setNext(i.getNext().getNext());
					i.getNext().setNext(null);
				}
				i.setNext(toSet);
			}
		}
	}
	
	/**
	 * @name getLinkAt
	 * @param index - index of the Link object you are looking for
	 * @return A Link object that on the index element of the linked List, null when index is out of bound
	 */
	public Link getLinkAt(int index){
		int indexCounter = 0;
		for(Link i=begin; i!=null; i=i.getNext()){
			if(indexCounter==index) return i;
			indexCounter++;
		}
		return null;
	}
	
	/**
	 * @name getLinkByNAW
	 * @param toSearch - NAW object to search
	 * @return Link which contains the NAW object, null when the NAW is not found in the Linked List
	 */
	public Link getLinkByNAW(NAW toSearch){
		for(Link i=begin; i!=null; i=i.getNext()){
			if(i.getCurr()==toSearch){
				return i;
			}
		}
		return null;
	}
	
	/**
	 * @name getNAWByLink
	 * @param toSearch - Link object
	 * @return NAW object within the Link object, null when the Link object is not found
	 */
	public NAW getNAWByLink(Link toSearch){
		for(Link i=begin; i!=null; i=i.getNext()){
			if(i==toSearch){
				return i.getCurr();
			}
		}
		return null;
	}
	
	/**
	 * @name getNAWByAddress
	 * @param address - address you are looking for
	 * @return first NAW object found in the linked list, null when address is not found
	 */
	public NAW getNAWByAddress(String address){
		for(Link i=begin; i!=null; i=i.getNext()){
			if(i.getCurr().getAdres().equals(address)){
				return i.getCurr();
			}
		}
		return null;
	}
	
	/**
	 * @name getNAWByName
	 * @param name - name you are looking for
	 * @return first NAW object found in the linked list, null when name is not found
	 */
	public NAW getNAWByName(String name){
		for(Link i=begin; i!=null; i=i.getNext()){
			if(i.getCurr().getName().equals(name)){
				return i.getCurr();
			}
		}
		return null;
	}
	
	/**
	 * @name getNameByWp
	 * @param wp - woonplaat you are looking for
	 * @return first NAW object found in the linked list, null when woonplaats is not found
	 */
	public NAW getNAWByWp(String wp){
		for(Link i=begin; i!=null; i=i.getNext()){
			if(i.getCurr().getWoonplaats().equals(wp)){
				return i.getCurr();
			}
		}
		return null;
	}
	
	/**
	 * @name begin
	 * @return the first element of the Linked list
	 */
	public Link begin(){
		return begin;
	}
	
	/**
	 * @name length1
	 * @return length of the linked list
	 */
	public int length1(){
		int tempLength = 0;
		for(Link i=begin; i!=null; i=i.getNext()){
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
}
