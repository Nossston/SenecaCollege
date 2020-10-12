package noston;

public abstract class Employee implements Payable {
    private String first;   // NO Static HERE
    private String last;    // Otherwise, our last value in array will always replace Name,ssn
    private String ssn;     //

    private static final String bar = "  |  ";

    public Employee(String first, String last, String ssn){
        setFirst(first);
        setLast(last);
        setSsn(ssn);
    }

    public static String getBar() {
        return bar;
    }

    public String toString() {
        return "EmployeeType:  "+ getBar()+
                "firstName: "+ getFirst()+ getBar()+
                "lastName: "+ getLast()+
                "\nssn: : "+ getSsn();
    }

    public  String getFirst() {
        return first;
    }

    public  void setFirst(String first) {
        this.first = first; // current Obj, not Employee.first.
    }

    public  String getLast() {
        return last;
    }

    public  void setLast(String last) {
        this.last = last;
    }

    public  String getSsn() {
        return ssn;
    }

    public  void setSsn(String ssn) {
        this.ssn = ssn;
    }
}
