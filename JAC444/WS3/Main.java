/**********************************************
 Workshop 3
 Course:<JAC444NCC> - 4th Semester
 Last Name: Liu
 First Name: Yu-Che
 ID:134379189
 Section:NCC
 This assignment represents my own work in accordance with Seneca Academic Policy. Signature
 Date:2020/10/10
 **********************************************/
package noston;

public class Main {
    public static void main(String[] args) {
        final int INDEX = 100;
        Employee[] staff = new Employee[INDEX];
        try {
            staff[0] = new BasePlusCommissionEmployee("First", "Guy", "123-123-123", 30_000, 10, 50);
            staff[1] = new BasePlusCommissionEmployee("Noston", "Liu", "123-123-123", 200_000, 2.2, 40_000);
            staff[2] = new BasePlusCommissionEmployee("Noston", "Liu", "123-123-123", 210_000, 10, 40_000);
            staff[3] = new BasePlusCommissionEmployee("Noston", "Liu", "123-123-123", 202_000, 10, 40_000);
            staff[4] = new BasePlusCommissionEmployee("Noston", "Liu", "123-123-123", 203_000, 10, 40_000);
            staff[5] = new BasePlusCommissionEmployee("Noston", "Liu", "123-123-123", 200_500, 10, 40_000);
            staff[7] = new BasePlusCommissionEmployee("Noston", "Liu", "123-123-123", 200_400, 10, 40_000);
            staff[6] = new BasePlusCommissionEmployee("Noston", "Liu", "123-123-123", 200_030, 10, 40_000);
            staff[11] = new CommissionEmployee("John", "Hudson", "111-123-123", 60_000, 1.22);
            staff[12] = new CommissionEmployee("John", "Hudson", "111-123-123", 55_000, 1.2);
            staff[13] = new CommissionEmployee("John", "Hudson", "111-123-123", 50_000, 1.2);
            staff[14] = new CommissionEmployee("John", "Hudson", "111-123-123", 20_000, 1.2);
            staff[15] = new CommissionEmployee("John", "Hudson", "111-123-123", 10_000, 1.2);
            staff[16] = new CommissionEmployee("John", "Hudson", "111-123-123", 13_123, 1.2);
            staff[17] = new CommissionEmployee("John", "Hudson", "111-123-123", 60_000, 1.3);
            staff[21] = new HourlyEmployee("Snow", "John", "123-123-111", 5, 41);
            staff[22] = new HourlyEmployee("Snow", "John", "123-123-111", 25, 44);
            staff[23] = new HourlyEmployee("Snow", "John", "123-123-111", 25, 45);
            staff[24] = new HourlyEmployee("Snow", "John", "123-123-111", 25, 46);
            staff[25] = new HourlyEmployee("Snow", "John", "123-123-111", 25, 47);
            staff[26] = new HourlyEmployee("Snow", "John", "123-123-111", 27, 41);
            staff[27] = new HourlyEmployee("Snow", "John", "123-123-111", 26, 42);
            staff[51] = new SalariedEmployee("Sarah", "Guan", "222-222-333", 60_000);
            staff[52] = new SalariedEmployee("Sarah", "Guan", "222-222-333", 60_000);
            staff[53] = new SalariedEmployee("Sarah", "Guan", "222-222-333", 60_000);
            staff[54] = new SalariedEmployee("Sarah", "Guan", "222-222-333", 60_000);
            staff[55] = new SalariedEmployee("Sarah", "Guan", "222-222-333", 60_000);
            staff[56] = new SalariedEmployee("Sarah", "Guan", "222-222-333", 12_123);
            staff[57] = new SalariedEmployee("Last" , "Last", "222-222-333", 2.312312313123123);
            Invoice I1 = new Invoice("1234D", "Tire", 5, 40);
        }catch (IllegalArgumentException err){
            System.out.printf(  "!!!!!\n"+ err.getMessage() +"\nPlease fix the issue and rerun this\n!!!!!");
        }finally {
            for (int i = 0 ; i < staff.length ; i++){
                if ( staff[i] instanceof Employee  ){
                    System.out.printf(staff[i].toString()+"\n" );
                    staff[i].getPaymentAmount();
                    System.out.printf("\n-------\n");
                }
            }
        }
    }
}
