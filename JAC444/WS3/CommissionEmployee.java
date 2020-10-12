package noston;

public class CommissionEmployee extends Employee{

    private double grossSales; // >0
    private double commissionRate; // 0-1

    public double getCommissionRate() {
        return commissionRate;
    }


    @Override
    public String toString() {
        return "EmployeeType: "+getClass().getName()+ getBar()+
                "\nfirstName: "+ getFirst()+ getBar()+
                "lastName: "+ getLast()+
                "\nssn: : "+ getSsn()+
                "\ngrossSales=  $" + getGrossSales() +
                "\ncommissionRate=  " + getCommissionRate();
    }

    @Override
    public void getPaymentAmount() {
        double sum= getGrossSales()*getCommissionRate();
        System.out.printf( "CommissionEmployee: "+ getFirst()+ " " +getLast()+
                "\t|| Payment: %11.2f", sum);
    }

    public CommissionEmployee(String first, String last, String ssn, double sales, double rate){
        super(first, last, ssn);
        setCommissionRate(rate);
        setGrossSales(sales);
    }

    public double getGrossSales() { return grossSales; }

    public void setGrossSales(double grossSales) {
        if (grossSales>0)
            this.grossSales = grossSales;
        else
            throw new IllegalArgumentException(this.getFirst()+ "'s grossSale should be greater than zero");
    }
    public void setCommissionRate(double commissionRate) {
        if (commissionRate >= 0 || commissionRate <= 1) this.commissionRate = commissionRate;
        else throw new IllegalArgumentException(this.getFirst()+ "'s commission is in range 0 to 1");
    }
}
