import java.io.*;

public class BracketsApp {
	
	public static String getString() throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		String s = br.readLine();
		return s;
	}
	
	public static void main(String[] args) throws IOException {
		String input;
		while (true) {
			System.out.print("Enter string containing delimiters:");
			System.out.flush();
			input = getString();
			
			if (input.equals(""))
				break;
			// make a BracketChecker
			BracketsChecker theChecker = new BracketsChecker(input);
			theChecker.check2(); // check brackets
		} // end while
	} // end main()
}