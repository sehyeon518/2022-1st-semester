// npm install request


let request=require('request');
let fs=require('fs');

console.log(__dirname);

let writingStatus = function(err) {
        if(err) {
            return console.log(err);
        }
        console.log("The file(naver_page.html) was saved!");
};

let pagestore = function(err, res, body){
    fs.writeFile(__dirname+"/result/naver_page.html", body, writingStatus);
};

let homepage=request('http://www.naver.com', pagestore);

homepage.pipe(fs.createWriteStream(__dirname+"/result/naver_page_pipe.html"));

let timeAction = function(){
    var timeout=5000;
    homepage.pipe(fs.createWriteStream(__dirname+"/result/naver_page_pipe_delay5000.html"));
    console.log('The file(naver_page_pipe_delay5000.html) was saved after '+timeout+'msec');
};

setTimeout(timeAction, 5000);
