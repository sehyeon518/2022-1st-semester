let request=require('request');
let fs=require('fs');
const MyPromise = require("./MyPromise_v2");

console.log(__dirname);

const work1 = () => new MyPromise(resolve => request('http://www.naver.com', (err, res, body) => resolve(body)));
const work2 = (body) => new MyPromise(resolve => fs.writeFile(__dirname+"/result/naver_page.html", body, (err) => resolve(err)));
const work3 = (err) => new MyPromise(resolve => resolve(err ? 'err' : "file created"));
const urgentWork = () => console.log('긴급 작업');

work1()
    .then(res => {console.log('The file(naver_page.tml) received!: ');
                  return work2(res);
                 })
    .then(err => {console.log('The file(naver_page.html) saved!: ');
                  return work3(err);
                 })
    .then(res => {console.log(res);
                 });

urgentWork();