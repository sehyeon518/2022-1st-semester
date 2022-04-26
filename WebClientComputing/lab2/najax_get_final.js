let najax = $ = require('najax');
//          변수
let fs = require('fs');

let errStatus = (err) => {
    if(err) {
        return console.log(err);
    }
    console.log("The file(google_page.html) was saved!");
}

let resp = (response) => {
    tableData = response;
    fs.writeFile(__dirname+"/result/google_page.html", tableData, errStatus);
};

function getData(callback) {
    var tableData;
    $.get('https://www.google.com', callback);
    return tableData;
};

getData(resp);

