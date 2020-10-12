package noston;

public class SalariedEmployee extends  Employee{
    private double weeklysalary; // > 0
    public SalariedEmployee(String first, String last, String ssn,double salary) {
        super(first, last, ssn);
        setWeeklysalary(salary);
    }

    public double getWeeklysalary() {
        return weeklysalary;
    }

    public void setWeeklysalary(double weeklysalary) {
        if ( weeklysalary > 0)
            this.weeklysalary = weeklysalary;
        else {
            throw new IllegalArgumentException( this.getFirst()+ "'s Weeklysalary should be greater than zero");
        }
    }

    @Override
    public String toString() {
        return "EmployeeType:  "+getClass().getName() + getBar()+
                "\nfirstName: "+ getFirst()+ getBar()+
                "lastName: "+ getLast()+
                "\nssn: : "+ getSsn()+
                "\nweeklysalary=" + getWeeklysalary();

    }

    @Override
    public void getPaymentAmount() {
        System.out.printf( getClass().getName()+ " " + getFirst()+
                "\nPayment: $%11.2f", getWeeklysalary());;
    }



}

