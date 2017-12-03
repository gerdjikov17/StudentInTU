
public class LinkedList {
	Link firstLink;
	Link lastLink;

	public LinkedList() {
		firstLink = null;
	}

	public void insertFirstLink(String brand, String model, int year) {
		Link newLink = new Link(brand, model, year);
		if (isEmpty()) {
			lastLink = newLink;
		}
		newLink.next = firstLink;
		firstLink = newLink;

	}

	public void insertLast(String brand, String model, int year) {
		Link newLink = new Link(brand, model, year);
		if (isEmpty()) {
			firstLink = newLink;
		} else {
			newLink.prev = lastLink;
			lastLink.next = newLink;
		}
		lastLink = newLink;

	}

	private boolean isEmpty() {
		if (firstLink == null)
			return true;
		else
			return false;
	}

	public void display() {
		Link a = firstLink;
		if (a == null) {
			System.out.println("Linked List is empty");
		} else {
			while (a != null) {
				System.out.println(a.getCarBrand() + " | " + a.getCarModel() + " | " + a.getYear());
				a = a.next;
			}
		}
	}

	public void findModel(String model) {
		Link a = firstLink;
		if (a == null) {
			System.out.println("Linked List is empty");
		} else {
			while (a != null) {
				if (a.getCarModel() == model) {
					a.display();
				}
				a = a.next;
			}
		}
	}

	public void findYear(int year) {
		Link a = firstLink;
		if (a == null) {
			System.out.println("Linked List is empty");
		} else {
			while (a != null) {
				if (a.getYear() == year) {
					a.display();
				}
				a = a.next;
			}
		}
	}

	public void remove(String model) {
		Link current = firstLink;
		Link previous = firstLink;
		if (current == null) {
			System.out.println("Linked List is empty");
		} else {
			while (current != null) {
				boolean middleDelete=false;
				if (current.getCarModel() == model) {
					if (current == firstLink) {
						firstLink = firstLink.next;
						firstLink.prev = null;
					}
					if (current == lastLink) {
						lastLink = lastLink.prev;
						lastLink.next = null;
					} else {
						previous.next = current.next;
						current.next.prev = previous;
						middleDelete=true;
					}

				}
				if(!middleDelete)
				previous = current;
				current = current.next;
			}
		}
	}
}
