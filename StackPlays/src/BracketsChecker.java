public class BracketsChecker {
	private String input;
	private BracketsStack theStack;

	public BracketsChecker(String in) {
		input = in;
		theStack = new BracketsStack(input.length());// create stack of input
														// string
	}

	public void check2() {
		for (int i = 0; i < input.length(); i++) {
			char ch = input.charAt(i);
			switch (ch) {
			case 'I':
				i = checkIf(i);
				break;
			case 'D':
				i = checkDo(i);
				break;
			case 'W':
				i = checkWhile(i);
				break;
			case 'E':
				System.out.println("No IF statement found for ELSE!");
			}
		}
	}

	public int checkIf(int index) {
		int i;
		for (i = index; i < input.length(); i++) {
			char ch = input.charAt(i);
			switch (ch) {
			case 'D':
				i = checkDo(i);
				break;
			case 'I':
			case '(':
			case '{':
				theStack.push(ch);
				i = checkIf(i+1);
				break;
			case '}':
			case ')':
			case 'E':
				if (!theStack.isEmpty()) {
					char chx = theStack.peek();
					if ((chx == 'I' && ch == 'E') || chx == '(' || chx == '{') {
						theStack.pop();
					} else {
						theStack.pop();
						return i-1;
					}
				}
				break;
			default:
				return i - 1;
			}
		}
		return i;
	}

	public int checkDo(int index) {
		int i;
		for (i = index; i < input.length(); i++) {
			char ch = input.charAt(i);
			switch (ch) {
			case 'D':
			case '(':
			case '{':
				theStack.push(ch);
				break;
			case '}':
			case ')':
			case 'W':
				if (!theStack.isEmpty()) {
					char chx = theStack.peek();
					if ((chx == 'D' && ch == 'W') || chx == '(' || chx == '{') {
						theStack.pop();
					} else {
						theStack.pop();
						return i-1;
					}
				}
				break;
			default:
				return i-1;	
			}
		}
		return i;
	}

	public int checkWhile(int index) {
		return index;
	}

	public void check() {
		for (int j = 0; j < input.length(); j++) // get chars in turn
		{
			char ch = input.charAt(j); // get char
			switch (ch) {
			case '{': // opening symbols
			case '[':
			case '(':
			case 'D':
			case 'I':
				theStack.push(ch); // push them
				break;
			case '}': // closing symbols
			case ']':
			case ')':
				if (!theStack.isEmpty()) // if stack not empty,
				{
					char chx = theStack.peek(); // pop and check
					if (!theStack.isEmpty()) {
						if ((chx == 'I' || chx == 'D')
								& (ch != 'E' || ch != 'W')) {
							theStack.pop();
						}
					}
				}
			case 'E':
			case 'W':
				if (!theStack.isEmpty()) // if stack not empty,
				{
					char chx = theStack.peek(); // pop and check

					chx = theStack.pop(); // pop and check
					System.out.println("Current char is " + ch
							+ " Last char is " + chx);
					if ((ch == '}' && chx != '{') || (ch == ']' && chx != '[')
							|| (ch == ')' && chx != '(')
							|| (ch == 'E' && chx != 'I')
							|| (ch == 'W' && chx != 'D'))
						System.out.println("Error: " + ch + " at " + j);

				} else
					// prematurely empty
					System.out.println("Error: " + ch + " at " + j);

				break;
			default: // no action on other characters
				break;
			} // end switch
		} // end for
			// at this point, all characters have been processed
		if (!theStack.isEmpty())
			System.out.println("Error: missing right delimiter");
	} // end check()
}
