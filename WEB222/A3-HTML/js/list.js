// Data for the "HTML Lists" Page

var fruits = [ "Apples","Oranges","Pears","Grapes","Pineapples","Mangos" ];
var directory = [
    {type: "file", name: "file1.txt"},
    {type: "file", name: "file2.txt"},
    {type: "directory", name: "HTML Files",files: [{type: "file", name: "file1.html"},{type: "file", name: "file2.html"}]},
    {type: "file", name: "file3.txt"},
    {type: "directory", name: "JavaScript Files", files: [{type: "file", name: "file1.js"},{type: "file", name: "file2.js"},{type: "file", name: "file3.js"}]}
];
window.onload = function() {
        var listTitle = "Fruit List";
        var myTitle = document.querySelector("#title");
        myTitle.innerHTML = "<h3>" + listTitle + "</h3>";
        var myContainer = document.querySelector("#output"); 
        var result ="";
        for (var i = 0; i < fruits.length; i++) {
            result +=  "<li>" + fruits[i] + "</li>" ;
        }
        myContainer.innerHTML += "<ol>"+ result +"</ol>";   



            var listTitle2 = "Directory and File";
            var myTitle2 = document.querySelector("#title2");
            myTitle2.innerHTML = "<h3>" + listTitle2 + "</h3>";
            var myContainer2 = document.querySelector("#output2"); 


            var result2="";   
            for (var i = 0; i < directory.length ; i++) {
                 result2 +=  "<ul><li>" + directory[i].name + "</li>" ;

                 if( directory[i].type == "directory" ){
                    for ( var j = 0;  j < directory[i].files.length  ; j++){
                        result2+=  "<ul><li>" + directory[i].files[j].name + "</li></ul>" 
                    }
                }    

                result2 += "</ul>";
            }
            myContainer2.innerHTML = result2; 
};
