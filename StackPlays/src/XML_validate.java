
public class XML_validate {
	private String toValidate;
	private Stack_String stack;
	
	public XML_validate(String XML)
	{
		this.toValidate = new String(XML);
		this.stack = new Stack_String(this.toValidate.length()/3); //worst case <a></a>, so maximal to be pushed on stack is length/3
	}
	
	public boolean validXml()
	{
		int start, end;
		for(int index = 0; index < toValidate.length(); index++)
		{
			if(toValidate.charAt(index) == '<')
			{
				start = index + 1;
				end = start + 1;
				while(toValidate.charAt(end) != '>')
					end++;
				
				if(toValidate.charAt(start) == '/')
				{
					if(!stack.pop().equals(toValidate.substring(start+1, end)))
						return false;
				}
				else
				{
					stack.push(toValidate.substring(start, end));
				}
			}
		}
		if(stack.isEmpty())
			return true;
		else
			return false;
	}
	
}
