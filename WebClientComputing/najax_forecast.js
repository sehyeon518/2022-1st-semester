let najax = $ = require('najax');
let fs=require('fs');


function getData(callback) {
	var tableData;
	$.get('https://api.openweathermap.org/data/2.5/weather?q=Seoul&units=metric&lang=kr&appid=1e1edc8170eec8cad4c927ae8876cd3f', callback);
    return tableData;
}

getData(function (response) {
		tableData = response;
    console.log(typeof(tableData));
    console.log(tableData);
    console.log('------------------------------------');

    const output = JSON.parse(tableData);
    console.log(typeof(output));
    console.log(output);
    console.log('------------------------------------');

    console.log("도시: " + output.name);
    console.log("국가: " + output.sys.country);
    console.log("날씨: " + output.weather[0]["description"]);
    console.log("평균온도: " + output.main["temp"] + " (°C)");
    console.log("최저온도: " + output.main["temp_min"] + " (°C)");
    console.log("최고온도: " + output.main["temp_max"] + " (°C)");
    console.log("풍속: " + output.wind["speed"] + " (m/sec)");
    console.log("습도: " + output.main["humidity"] + " (%)");

/*    fs.writeFile(__dirname+"/temp/weather_seoul.json", tableData, function(err) {
        if(err) {
            return console.log(err);
        }
        console.log("The file(weather_seoul.json) was saved!");
     });
*/
});
