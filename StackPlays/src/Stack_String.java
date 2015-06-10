
public class Stack_String {
	private String[] stack;
	private int maxSize;
	private int top;
	
	public Stack_String(int maxSize)
	{
		this.maxSize = maxSize;
		stack = new String[maxSize];
		top = -1;
	}
	
	public void push(String toPush)
	{
		if(top == maxSize)
		{
			System.out.println("Stack is full");
			return;
		}
		stack[++top] = toPush;
	}
	
	public String pop()
	{
		return stack[top--];
	}
	
	public String peek()
	{
		return stack[top];
	}
	
	public boolean isEmpty()
	{
		return (top == -1);
	}
	
}
