/*
********************************************
 Workshop 2
 Course:<JAC444NCC> - 4th Semester
 Last Name: Liu
 First Name: Yu-Che
 ID:134379189
 Section:NCC
 This assignment represents my own work in accordance with Seneca Academic Policy. Signature
 Date:2020/10/02
 **********************************************/

package com.company;

public class IncomeTax {
    private static int filingStatus;
    private static final int SINGLE_FILER = 0;
    private static final int MARRIED_JOINTLY_OR_QUALIFYING_WIDOWER = 1;
    private static final int  MARRIED_SEPARATELY = 2;
    private static final int  HEAD_OF_HOUSEHOLD  = 3;
    private static final int  INTERVAL  = 1000;
    private static int  rowLength;
    private static double[] rates;
    private static double taxableIncome;
    private static double start_taxableIncome;
    private static double end_taxableIncome;



    public IncomeTax(){

    }



    public static int getFilingStatus() {
        return filingStatus;
    }

    public static void setFilingStatus(int filing_Status) {
        boolean flag = true;
        while(flag){
            if (filing_Status > HEAD_OF_HOUSEHOLD || filing_Status < SINGLE_FILER ){
                System.out.println("You are only allowed to enter 0-3");
            }
            else{
                IncomeTax.filingStatus = filing_Status;
                System.out.println("you enter: "+ getFilingStatus() );
                flag = false;
            }
        }

    }


    public static double getTaxableIncome() {
        return taxableIncome; }



    public static double getTaxableIncome(double taxable_Income, int status ) { // 2009 table
        final double LARGEST = 6007123514299L;
        double[] single={8350,33950,82250,171550,372950,LARGEST};
        double[] widow={16700,67900,137_050,208850,372950,LARGEST};
        double[] separately={8350,33950,68225,104425,186475,LARGEST};
        double[] head={11950,45500,117450,190200,372950,LARGEST};
        double[] rates = {0.1,0.15,0.25,0.28,0.33,0.35};
        double sum = 0;
        boolean flag = true;
        int pos =0;

        switch (status) {
            case SINGLE_FILER -> {
                for (int i = 0; i < single.length && flag; i++) {
                    if (taxable_Income < single[i]) {
                        pos = i; // mark the pos
                        sum += (taxable_Income - single[pos - 1]) * rates[pos]; //50_000-33950*0.25
                        flag = false;
                    }
                }
                for (int i = 0; i < pos; i++) {
                    sum += single[i] * rates[i]; // 8350*0.1 + 33950*0.15
                }
                return sum;
            }
            case MARRIED_JOINTLY_OR_QUALIFYING_WIDOWER -> {
                for (int i = 0; i < widow.length && flag; i++) {
                    if (taxable_Income < widow[i]) {
                        pos = i; // mark the pos
                        sum += (taxable_Income - widow[pos - 1]) * rates[pos];
                        flag = false;
                    }
                }
                for (int i = 0; i < pos; i++) {
                    sum += widow[i] * rates[i];
                }
                return sum;
            }
            case MARRIED_SEPARATELY -> {
                for (int i = 0; i < separately.length && flag; i++) {
                    if (taxable_Income < separately[i]) {
                        pos = i; // mark the pos
                        sum += (taxable_Income - separately[pos - 1]) * rates[pos];
                        flag = false;
                    }
                }
                for (int i = 0; i < pos; i++) {
                    sum += separately[i] * rates[i];
                }
                return sum;
            }
            case HEAD_OF_HOUSEHOLD -> {
                for (int i = 0; i < head.length && flag; i++) {
                    if (taxable_Income < head[i]) {
                        pos = i; // mark the pos
                        sum += (taxable_Income - head[pos - 1]) * rates[pos];
                        flag = false;
                    }
                }
                for (int i = 0; i < pos; i++) {
                    sum += head[i] * rates[i];
                }
                return sum;
            }
            default -> throw new IllegalStateException("Unexpected value: " + getFilingStatus());
        }
    }

    public static void setTaxableIncome(double taxableIncome) {
        boolean flag = true;
        while (flag){
            if (taxableIncome < 0 ){
                System.out.println("You are only allowed to enter positive numbers");
            }
            else {
                IncomeTax.taxableIncome = taxableIncome;
                System.out.println("you enter: "+ IncomeTax.taxableIncome );
                flag = false;
            }
        }
    }


    public static double getStart_taxableIncome() {
        return start_taxableIncome;
    }

    public static double getEnd_taxableIncome() {
        return end_taxableIncome;
    }

    public static void setStart_taxableIncome(double start_taxableIncome) {
        IncomeTax.start_taxableIncome = start_taxableIncome;
    }

    public static void setEnd_taxableIncome(double end_taxableIncome) {
        IncomeTax.end_taxableIncome = end_taxableIncome;
    }


    public static void setRates(double start,double end) { // ex: 60000 - 50000, in this one
        rowLength = (int) (Math.abs( end-start)/1000) +1 ; // rows = 10
        rates= new double[rowLength];
        for (int i = 0 ; i< rowLength ; i++){
            rates[i] = start + INTERVAL*i;
        }
    }
    public static void getTables(){
        System.out.println(
                "2001 tax tables for taxable income from $"+getStart_taxableIncome() +" to $"+getEnd_taxableIncome()
                        +"\n---------------------------------------------\n" +
                        "Taxable |  Single  | Married Joint  | Married  | Head of\n"+
                        "Income  |          | or widow(er)   | Separate | a House\n"+
                        "-------------------------------------------------"
        );
        setRates(getStart_taxableIncome(),getEnd_taxableIncome() );
        String  bar =" |   $";

        for (int i = 0 ; i < rowLength;i++){
            System.out.println(rates[i] +bar+ get2001TaxableIncome( rates[i],SINGLE_FILER )
                    +bar+ get2001TaxableIncome( rates[i],MARRIED_JOINTLY_OR_QUALIFYING_WIDOWER )
                    +bar+ get2001TaxableIncome( rates[i],MARRIED_SEPARATELY)
                    +bar+ get2001TaxableIncome( rates[i],HEAD_OF_HOUSEHOLD ));
        }

        System.out.println(
                "\n\n2009 tax tables for taxable income from $" +getStart_taxableIncome() +" to $"+getEnd_taxableIncome()
                        +"\n---------------------------------------------\n" +
                        "Taxable |  Single  | Married Joint  | Married  | Head of\n"+
                        "Income  |          | or widow(er)   | Separate | a House\n"+
                        "-------------------------------------------------"
        );
        for (int i = 0 ; i < rowLength;i++){
            System.out.println(rates[i] +bar+ getTaxableIncome( rates[i],SINGLE_FILER )
                    +bar+ getTaxableIncome( rates[i],MARRIED_JOINTLY_OR_QUALIFYING_WIDOWER )
                    +bar+ getTaxableIncome( rates[i],MARRIED_SEPARATELY)
                    +bar+ getTaxableIncome( rates[i],HEAD_OF_HOUSEHOLD ));
        }
    }



    public static double get2001TaxableIncome(double taxable_Income, int status ) {
        final double LARGEST = 6007123514299L;
        double[] single = new double[]   {27050,65550,136750,297350, LARGEST};
        double[] widow=  new double[]   {45200,109250,166500,297350,LARGEST};
        double[] separately=new double[]{22600,54625,83250,148675,LARGEST};
        double[] head=  new double[]    {36250,93650,151650,297350,LARGEST};
        double[] rates = new double[] {0.15,0.275,0.305,0.355,0.391};
        double sum = 0;
        boolean flag = true;
        int pos =0;

        switch (status) {
            case SINGLE_FILER -> {
                for (int i = 0; i < single.length && flag; i++) {
                    if (taxable_Income < single[i]) {
                        pos = i; // mark the pos
                        sum += (taxable_Income - single[pos - 1]) * rates[pos]; //50_000-33950*0.25
                        flag = false;
                    }
                }
                for (int i = 0; i < pos; i++) {
                    sum += single[i] * rates[i]; // 8350*0.1 + 33950*0.15
                }
                return sum;
            }
            case MARRIED_JOINTLY_OR_QUALIFYING_WIDOWER -> {
                for (int i = 0; i < widow.length && flag; i++) {
                    if (taxable_Income < widow[i]) {
                        pos = i; // mark the pos
                        sum += (taxable_Income - widow[pos - 1]) * rates[pos];
                        flag = false;
                    }
                }
                for (int i = 0; i < pos; i++) {
                    sum += widow[i] * rates[i];
                }
                return sum;
            }
            case MARRIED_SEPARATELY -> {
                for (int i = 0; i < separately.length && flag; i++) {
                    if (taxable_Income < separately[i]) {
                        pos = i; // mark the pos
                        sum += (taxable_Income - separately[pos - 1]) * rates[pos];
                        flag = false;
                    }
                }
                for (int i = 0; i < pos; i++) {
                    sum += separately[i] * rates[i];
                }
                return sum;
            }
            case HEAD_OF_HOUSEHOLD -> {
                for (int i = 0; i < head.length && flag; i++) {
                    if (taxable_Income < head[i]) {
                        pos = i; // mark the pos
                        sum += (taxable_Income - head[pos - 1]) * rates[pos];
                        flag = false;
                    }
                }
                for (int i = 0; i < pos; i++) {
                    sum += head[i] * rates[i];
                }
                return sum;
            }
            default -> throw new IllegalStateException("Unexpected value: " + getFilingStatus());
        }
    }

}
