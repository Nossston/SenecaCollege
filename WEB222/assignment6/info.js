function formValidation(){
    clearerrors();
    return validation();
}

function validation() {
    var input = document.form1.uname.value;
    var input2 = document.form1.pd.value;
    var input3 = document.form1.age.value;
    var input4 =document.form1.fname.value;
    var input5 =document.form1.lname.value;

    var ferr = document.querySelector("#ferr");
    var lerr = document.querySelector("#lerr");
    var uerrors = document.querySelector("#uerr");
    var perrors = document.querySelector("#perr");
    var edulverr = document.querySelector("#edulverr");
    var agerr = document.querySelector("#agerr");
    var flag = true;

    if ( (input4[0] < 'A' || input4[0] > 'Z' || input4.length == 0 )&& flag ){
        ferr.innerHTML = "<span>* First char must be uppercase.</span>";
        flag=false;
    }

    if ( (input5[0] < 'A' || input5[0] > 'Z' || input5.length == 0 )&& flag){
        lerr.innerHTML = "<span>* First char must be uppercase.</span>";
        flag=false;
    }

    if (input.length < 6 && flag) { 
           uerrors.innerHTML = "<span>* For UserName, Please enter at least 6 chars.</span>";
           document.form1.uname.focus();
            flag=false;
    }
    
    if (input2.length !=6 && flag ) {
           perr.innerHTML = "<span>* For Password, Please enter exactly 6 chars.</span>";
           flag=false;
    }
    
    if( input2[0] > '0' && input2[0] < '9' && flag){
             perr.innerHTML = "<span>* For Password, it must start with a character. </span>";
             flag= false; 
    }
     
    var capflag = false;
    for(var i = 0; i < input2.length && flag ; i++){
        if(input2[i] >= 'A' && input2[i] <= 'Z' ){
            capflag = true;
        }
    }
    if(!capflag && flag ){
      perr.innerHTML = "<span>* For Password, it must have at least 1 uppercase</span>";
      flag=false;
    }
     
    var numflag = false;
    for(var i = 0; i < input2.length && flag ; i++){
      if(input2[i] >= 0 && input2[i] <= 9 ){
        numflag = true;
       }
    }
    if(!numflag && flag ){
        perr.innerHTML = "<span>* For Password, it must have at least 1 digits</span>";
        flag=false;
    }
     if( (input3 < '18' || input3 > '60') && flag){
      agerr.innerHTML = "<span>* For Age, it must be between 18 to 60</span>";
      flag=false;
    }

    return flag; 

}  

function clearerrors() {
 document.querySelector("#uerr").innerHTML = "";
 document.querySelector("#perr").innerHTML = "";
 document.querySelector("#edulverr").innerHTML = "";
 document.querySelector("#agerr").innerHTML = "";
 document.querySelector("#ferr").innerHTML = "";
 document.querySelector("#lerr").innerHTML = "";

}
