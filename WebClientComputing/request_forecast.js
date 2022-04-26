let request=require('request');
let fs=require('fs');

console.log(__dirname);

let homepage=request('http://api.openweathermap.org/data/2.5/forecast?q=Busan&units=metric&lang=kr&appid=1e1edc8170eec8cad4c927ae8876cd3f', function(err, res, body){
    console.log(typeof(body)); // string
    console.log(body);
    console.log('------------------------------------');

    const output = JSON.parse(body); // JSON 데이터(문자열)을 객체로 변환
    console.log(typeof(output)); // object
    console.log(output);
    console.log('------------------------------------');

    console.log("도시: " + output.city.name);
    console.log("국가: " + output.city.country);

    for (let i = 0; i < output.list.length; i++) {
        console.log('------------------------------------');
        let date = new Date(output.list[i].dt*1000);
        console.log("예보일시: " + date.toString());
        console.log("날씨: " + output.list[i].weather[0]["description"]);
        console.log("평균온도: " + output.list[i].main["temp"] + " (°C)");
        console.log("최저온도: " + output.list[i].main["temp_min"] + " (°C)");
        console.log("최고온도: " + output.list[i].main["temp_max"] + " (°C)");
        console.log("풍속: " + output.list[i].wind["speed"] + " (m/sec)");
        console.log("습도: " + output.list[i].main["humidity"] + " (%)");
    }
});
