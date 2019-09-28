/********************************************************************************* 
		*  WEB222 – Assignment 1 
		*  I declare that this assignment is my own work in accordance with Seneca Academic Policy. 
 		*  No part of this assignment has been copied manually or electronically from any other source  
		*  (including web sites) or distributed to other students. 
		*  Name: Liu,Yu-Che Student ID: 134379189 Date: 5/14
********************************************************************************/ 
  
/************  Task 1  ********************/

//Store my info to the variables
var studentName = "Liu,Yu-Che";
var numberOfCourses = 6;
var program = "CPA" ;
var havingaPartimejob = false ;

    if ( havingaPartimejob = false ){
    havingaPartimejob = "don't have";
    }
    else{
    havingaPartimejob = "have";
    }
console.log("My name is " + studentName + "and I’m in " + program  + " program. I’m taking "
+ numberOfCourses + " course  in this semester" + " and I " + havingaPartimejob +  " a part‐time job now.")

/************  Task 2  ********************/

var current = 2019;
var age = prompt("Please enter your age:");
// Do the calculation in the console.log
console.log("You were born in the year of " + (current-age) );
var expect = prompt("Enter the number of years you expect to study in the college:");
// The coversion function prevents the 
console.log("You will graduate from Seneca college in the year of " + (parseInt(expect)+current) );

/************  Task 3  ********************/

var celsius = 2;
var fahrenheit = (celsius * 5/9 + 32) ;
console.log(celsius+"°C is " + fahrenheit +"°F.");

var fahrenheit = 2;
var celsius = ( fahrenheit - 32) * 5/9 ;
console.log(fahrenheit +"°F is " + celsius+"°C.");

/************  Task 4  ********************/

for (var i =0 ; i <=10 ;i++){
    if(i % 2 == 0){ // Any integer that can be divided exactly by 2 is an even number.
    // Therefore, using modular is the best way to test it.
        console.log(i+" is even.");
    }
    else{
        console.log(i+" is odd.");
    }
}

/************  Task 5  ********************/

// Almost the same as we have in C.
function largerNum(num1,num2){
// To check which number is larger, using if statement is the easiest way.
    if (num1 > num2) {
        return num1;
    }
    else{
        return num2;
    }
}

    var num1 = 5;
    var num2 = 12;
    
console.log("The larger number of " + num1 + " and " + num2 + " is "+ largerNum(num1,num2) );

/************  Task 6  ********************/

function evaluator(){
    var sum = 0;
    var ave = 0;

    for (var i = 0; i < arguments.length; i++) { // From the notes, I learned that I can run this for loop, as we are requested, even I don't have any idea how many arguments are going to be.
	         sum += arguments[i];
    }
    // This special variable applies to the calculation as well.
    ave = sum / arguments.length;
    
    if (ave >= 50){
    // I prefer to output the string that begins with capital; I need to use double quotes.
        return "True";
    }
    else{
        return "False";
    }
}

console.log("The average is greater than or equal to 50: " + evaluator(250,500,220));

/************  Task 7 ********************/


// 
function Grader(mark){
    
    // I used multiple conditions. It looks long but straightforward.
    if(mark <= 100 && mark >= 80 ){
        return "A";
    }
    else if (mark < 80 && mark >= 70){
        return "B";
    }
    else if (mark < 70 && mark >= 60){
        return "C";
    }
    else if (mark < 60 && mark >= 50){
        return "D";
    }
    else if (mark > 100 || mark < 0){ //Even though we are not asked to have or test invaild input, still, I would like to check negative or huge numbers here.
        return "False input";
    }
    else{
        return "F";
    }
}
var mark1 = 99;
var mark2 = 50;
var mark3 = 3;
console.log("Mark "+ mark1 +" , the grade is " + Grader(mark1) );
console.log("Mark "+ mark2 +" , the grade is " + Grader(mark2) );
console.log("Mark "+ mark3 +" , the grade is " + Grader(mark3) );


/************  Task 8 ********************/

function showMultiples(num, numMultiples){
    var i = 0;
    for (i =1; i <= numMultiples; i++ ){ // Here I start i with 1, which is not a good way to do in a for-loop; however, this fits the outcome within a clean way. 
        console.log(num + " x " + i + " = " + (num*i) );
    }
}
showMultiples(2,5);
showMultiples(5,3);
showMultiples(11,4);