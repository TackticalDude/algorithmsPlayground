
public class xml_main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		XML_validate test = new XML_validate("<persoon><naam>Donald Duck</naam><adres>Eendenplein 17</adres><woonplaats>Duckstad</woonplaats></persoon>");
		if(test.validXml())
			System.out.println("ja");
		else
			System.out.println("nee");
	}

}
