package noston;

public class Invoice implements Payable {
    private static String partNumber;// – the part number
    private static String description;
    private static double price;
    private static int quantity;


    public Invoice(){
        System.out.println("Invoice no-arg constructor");
    }
    public Invoice(String partNumber, String description, int count, double price){
        setDescription(description);
        setPartNumber(partNumber);
        setPrice(price);
        setQuantity(count);
    }

    @Override
    public String toString() {
        return "Invoice{" +
                "partNumber: "+ getPartNumber()+
                ", description: "+getDescription()+
                ", price: " +getPrice()+
                ", quantity: "+getQuantity()+
                "}";
    }

    @Override
    public void getPaymentAmount(){

    }


    public static String getPartNumber() {
        return partNumber;
    }

    public static void setPartNumber(String partNumber) {
        Invoice.partNumber = partNumber;
    }

    public static String getDescription() {
        return description;
    }

    public static void setDescription(String description) {
        Invoice.description = description;
    }

    public static double getPrice() {
        return price;
    }

    public static void setPrice(double price) {
        Invoice.price = price;
    }

    public static int getQuantity() {
        return quantity;
    }

    public static void setQuantity(int quantity) {
        Invoice.quantity = quantity;
    }
}
