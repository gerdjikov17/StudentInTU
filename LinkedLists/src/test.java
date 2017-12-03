
public class test {
	public static void main (String[] args) {
		LinkedList a = new LinkedList();
		a.insertFirstLink("Mercedes", "S350", 2015);
		a.insertLast("Mercedes", "E220", 2005);
		a.insertFirstLink("Mercedes", "S350", 2005);
		a.insertFirstLink("Mercedes", "S500", 2004);
		a.insertLast("Mercedes", "S63", 2008);
		a.insertFirstLink("Mercedes", "S350", 2015);
		a.insertFirstLink("Mercedes", "S350", 2015);
		a.insertFirstLink("Mercedes", "S63", 2017);
		a.insertFirstLink("Mercedes", "S63", 2017);
		a.insertFirstLink("Mercedes", "S350", 2015);
		a.insertFirstLink("Mercedes", "S350", 2015);
		a.display();
		a.remove("S350");
		System.out.println("\n");
		a.display();

	}
}
