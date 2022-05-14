let request=require('request');
let fs=require('fs');

console.log(__dirname);

const work1 = () => new Promise(resolve => request('http://www.naver.com', (err, res, body) => resolve(body)));
const work2 = (body) => new Promise(resolve => fs.writeFile(__dirname+"/result/naver_page.html", body, (err) => resolve(err)));
const work3 = (err) => new Promise(resolve => resolve(err ? 'err occurred' + err: 'file created'));
const urgentWork = () => console.log('긴급 작업');

work1()
    .then(res => {console.log('The file(naver_page.html) received!: ');
                  return work2(res);
                 })
    .then(err => {console.log('The file(naver_page.html) saved!: ');
                  return work3(err);
                 })
    .then(res => {console.log(res);
                 });

urgentWork();
