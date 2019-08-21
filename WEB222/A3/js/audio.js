// Data for the "HTML Audio" Page

var audio = {
    controls: true, 
    source: [
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.mp3", type: "audio/mpeg"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.ogg", type: "audio/ogg"}
    ]
};


window.onload = function() {
    var listTitle = "HTML5 Audio";
    var myTitle = document.querySelector("#title");
    myTitle.innerHTML = "<h3>" + listTitle + "</h3>";
    var myContainer = document.querySelector("#output"); 
    var result= " " ;
    result="<audio controls>";
    for (var i = 0; i < audio.source.length ; i++) {
        result += "<source src='" 
        + audio.source[i].src + "' type='" 
        + audio.source[i].type + "'></audio>";
    }
    
    myContainer.innerHTML = result;


}