package noston;

public class HourlyEmployee  extends  Employee{
    private double wage; //>0
    private double hours; // 168 >hour>0

    public HourlyEmployee(String first, String last, String ssn,double hourlyWage, double hoursWorked) {
        super(first, last, ssn);
            setHours(hoursWorked);
            setWage(hourlyWage);
    }

    @Override
    public String toString() {
        return "EmployeeType:  "+getClass().getName()+ getBar()+
                "\nfirstName: "+ getFirst()+ getBar()+
                "lastName: "+ getLast()+
                "\nssn: : "+ getSsn()+
                "\nwage= " + wage +
                ", hours= " + hours
                ;
    }

    public double getWage() {
        return wage;
    }

    public void setWage(double wage) {
        if(wage>0)
            this.wage = wage;
        else{
            throw new IllegalArgumentException( this.getFirst()+ "'s Wage should be greater than zero");
        }
    }

    public double getHours() {
        return hours;
    }

    public void setHours(double hours) {
        if (hours < 168 || hours > 0)
            this.hours = hours;
        else{
            throw new IllegalArgumentException("HoursWorked should be greater than zero and less than 168 hours");

        }
    }

    @Override
    public void getPaymentAmount() {
        double sum= getHours()*getWage();
        System.out.printf( getClass().getName()+ ": " + getFirst()+
                "\nPayment: $%11.2f", sum);;
    }



}
