// All you JavaScript code for assignment 4 should be in this file
window.onload = function(){    
    document.querySelector("#menu_1").onclick = list;
    document.querySelector("#menu_21").onclick = function () {CreateTableByPopulationOrConte(21,100000000,0,0,0) };
    document.querySelector("#menu_22").onclick = function () {CreateTableByPopulationOrConte(22,1000000,2000000,0,0) };
    document.querySelector("#menu_31").onclick = function () {CreateTableByPopulationOrConte(31,0,0,"Americas",1000000)};
    document.querySelector("#menu_32").onclick = function () {CreateTableByPopulationOrConte(32,0,0,"Asia",0)};
    document.querySelector("#menu_41").onclick = function () {CreateTableByLan(41)};
    document.querySelector("#menu_42").onclick = function () {CreateTableByLan(42)};
    document.querySelector("#menu_43").onclick = function () {CreateTableByLan(43)};
    document.querySelector("#menu_44").onclick = function () {CreateTableByLan(44)};
    document.querySelector("#menu_45").onclick = function () {CreateTableByLan(45)};
    document.querySelector("#menu_46").onclick = function () {CreateTableByLan(46)};
    document.querySelector("#menu_47").onclick = function () {CreateTableByLan(47)};
    document.querySelector("#menu_48").onclick = function () {CreateTableByLan(48)};
}


function Subtitle(text)
{
  var sub = document.querySelector("#subtitle");
  sub.innerHTML = "List of Countries and Dependencies" + text;
}

function imgInsert(code){
    var cell = document.createElement("td");
    var img = document.createElement ("img"); 
    img.src = "flags/" + code.toLowerCase() +".png";
    img.height = 30;
    img.width = 30;
    img.setAttribute("alt","");
    cell.appendChild(img);
    return cell;
}

function getTd(text){
    var cell = document.createElement("td");
    var celltext = document.createTextNode(text);
    cell.appendChild(celltext);
    return cell;
}

function list(e){
    e.preventDefault();
    Subtitle("\t");

    var tbl = document.querySelector("#outputTable");
    
    var tblExistingBody = tbl.querySelector("tbody");
    if (tblExistingBody) tbl.removeChild(tblExistingBody);
    
    var tblBody = document.createElement("tbody");

    for( var i = 0; i < countries.length; i++){
        var row = document.createElement("tr");
        row.appendChild(imgInsert(countries[i].Code));
        row.appendChild(getTd(countries[i].Code));
        row.appendChild(getTd(countries[i].Name.English));
        row.appendChild(getTd(countries[i].Continent));
        row.appendChild(getTd(countries[i].AreaInKm2));
        row.appendChild(getTd(countries[i].Population));
        row.appendChild(getTd(countries[i].Capital));
        tblBody.appendChild(row);
    }
    tbl.appendChild(tblBody);
}


function CreateTableByLan(flag){
    var tbl = document.querySelector("#outputTable");
    
    var tblExistingBody = tbl.querySelector("tbody");
    if (tblExistingBody) tbl.removeChild(tblExistingBody);
    
    var tblBody = document.createElement("tbody");


    for( var i = 0; i < countries.length; i++){
        var row = document.createElement("tr");
        row.appendChild(imgInsert(countries[i].Code));
        row.appendChild(getTd(countries[i].Code));
        
    switch (flag){
        case 41:
            Subtitle(" - Country/Dep. Name in English");
            row.appendChild(getTd(countries[i].Name.English));
            break;
        case 42:
            Subtitle(" - Country/Dep. Name in Arabic");
            row.appendChild(getTd(countries[i].Name.Arabic));
            break; 
        case 43:
            Subtitle(" - Country/Dep. Name in 中文 (Chinese)");
            row.appendChild(getTd(countries[i].Name.Chinese));
            break;
        case 44:
            Subtitle(" - Country/Dep. Name in Franch");
            row.appendChild(getTd(countries[i].Name.Franch));
            break;   
        case 45:
            Subtitle(" - Country/Dep. Name in Hindi");
            row.appendChild(getTd(countries[i].Name.Hindi));
            break;
        case 46:
            Subtitle(" - Country/Dep. Name in Korean");
            row.appendChild(getTd(countries[i].Name.Korean));
            break;
        case 47:
            Subtitle(" - Country/Dep. Name in Japanese");
            row.appendChild(getTd(countries[i].Name.Japanese));
            break;
        case 48:
            Subtitle(" - Country/Dep. Name in Russain");
            row.appendChild(getTd(countries[i].Name.Russian));
            break; 
    }
        row.appendChild(getTd(countries[i].Continent));
        row.appendChild(getTd(countries[i].AreaInKm2));
        row.appendChild(getTd(countries[i].Population));
        row.appendChild(getTd(countries[i].Capital));
        tblBody.appendChild(row);
    }
    tbl.appendChild(tblBody);

}



function CreateTableByPopulationOrConte(flag,min,max,Continent,AreaInKm2){
    var tbl = document.querySelector("#outputTable");
    
    var tblExistingBody = tbl.querySelector("tbody");
    if (tblExistingBody) tbl.removeChild(tblExistingBody);
    
    var tblBody = document.createElement("tbody");

    if (flag == 21){
        Subtitle(" - Population greater than 100 million"); 
        
      for( var i = 0; i < countries.length; i++){
        if(countries[i].Population > min ){
          var row = document.createElement("tr");
          row.appendChild(imgInsert(countries[i].Code));
          row.appendChild(getTd(countries[i].Code));
          row.appendChild(getTd(countries[i].Name.English));
          row.appendChild(getTd(countries[i].Continent));
          row.appendChild(getTd(countries[i].AreaInKm2));
          row.appendChild(getTd(countries[i].Population));
          row.appendChild(getTd(countries[i].Capital));
          tblBody.appendChild(row);
        }
      }
    }   
    
    else if (flag == 22){
        Subtitle(" - Population between 1 and 2 million");
      for( var i = 0; i < countries.length; i++){
        if(countries[i].Population > min && countries[i].Population < max ){
          var row = document.createElement("tr");
          row.appendChild(imgInsert(countries[i].Code));
          row.appendChild(getTd(countries[i].Code));
          row.appendChild(getTd(countries[i].Name.English));
          row.appendChild(getTd(countries[i].Continent));
          row.appendChild(getTd(countries[i].AreaInKm2));
          row.appendChild(getTd(countries[i].Population));
          row.appendChild(getTd(countries[i].Capital));
          tblBody.appendChild(row);
        }
      }
    }

    else if (flag == 31){
        Subtitle(" - Area greater than 1 million Km2, Americas");
      for( var i = 0; i < countries.length; i++){
        if( countries[i].Continent == Continent && countries[i].AreaInKm2 > AreaInKm2  ){
          var row = document.createElement("tr");
          row.appendChild(imgInsert(countries[i].Code));
          row.appendChild(getTd(countries[i].Code));
          row.appendChild(getTd(countries[i].Name.English));
          row.appendChild(getTd(countries[i].Continent));
          row.appendChild(getTd(countries[i].AreaInKm2));
          row.appendChild(getTd(countries[i].Population));
          row.appendChild(getTd(countries[i].Capital));
          tblBody.appendChild(row);
        }
      }
    }
    else if (flag == 32){
        Subtitle(" - All countries in Asia");
      for( var i = 0; i < countries.length; i++){
            if( countries[i].Continent == Continent){
          var row = document.createElement("tr");
          row.appendChild(imgInsert(countries[i].Code));
          row.appendChild(getTd(countries[i].Code));
          row.appendChild(getTd(countries[i].Name.English));
          row.appendChild(getTd(countries[i].Continent));
          row.appendChild(getTd(countries[i].AreaInKm2));
          row.appendChild(getTd(countries[i].Population));
          row.appendChild(getTd(countries[i].Capital));
          tblBody.appendChild(row);
        }
      }
    }
    tbl.appendChild(tblBody);
}







