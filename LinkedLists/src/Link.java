
public class Link {
	private String carBrand;
	private String carModel;
	private int year;
	Link next;
	Link prev;
	public Link(String carBrand, String carModel, int year) {
		next=null;
		this.carBrand = carBrand;
		this.carModel = carModel;
		this.year = year;
	}
	public void display() {
		System.out.println(carBrand+" | "+carModel+" | "+year);
	}
	public String getCarBrand() {
		return carBrand;
	}
	public void setCarBrand(String carBrand) {
		this.carBrand = carBrand;
	}
	public String getCarModel() {
		return carModel;
	}
	public void setCarModel(String carModel) {
		this.carModel = carModel;
	}
	public int getYear() {
		return year;
	}
	public void setYear(int year) {
		this.year = year;
	}

}
