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
}
