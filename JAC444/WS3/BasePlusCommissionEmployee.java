package noston;

public class BasePlusCommissionEmployee extends CommissionEmployee implements Payable{
    private double baseSalary; // >0
    private static final double BONUS = 1.1;

    @Override
    public String toString() {
        return "EmployeeType:  "+getClass().getName() + getBar()+
                "\nfirstName: "+ getFirst()+ getBar()+
                "lastName: "+ getLast()+
                "\nssn: : "+ getSsn()+
                "\ngrossSales=  $" + getGrossSales() +
                "\ncommissionRate=  " + getCommissionRate()+
                "\nbase Salary(with 10%% bonus)= $"+ getBaseSalary(); // %f only works within sout !!

    }

    public BasePlusCommissionEmployee(String first, String last, String ssn, double sales, double rate, double baseSalary) {
        super(first, last, ssn, sales, rate);
        setBaseSalary(baseSalary);
    }

    public double getBaseSalary() {
        return baseSalary*BONUS;
    }

    public void setBaseSalary(double baseSalary)  {
        if ( baseSalary <= 0) {
            this.baseSalary = 0;
            throw new IllegalArgumentException(this.getFirst()+ "'s Base Salary should be larger than zero");
        }
        else {
            this.baseSalary = baseSalary;}
    }

    @Override
    public void getPaymentAmount() {
        System.out.printf( getClass().getName()+" " + getFirst()+
                "\nPayment(with 10%% bonus):$"+" %11.2f", (getBaseSalary()+ (getCommissionRate()*getGrossSales())  )
        );
    }
}
