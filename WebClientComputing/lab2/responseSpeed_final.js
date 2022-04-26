
function callWebService(callback) {
    let second = 0;

    let id = setInterval(function () {
        second += 1;
        console.log(`${second}초 경과...`);
        if (second == stoptime) {
            console.log(`stoptime: ${stoptime}`);
        }
    }, 1000);

    let stoptime = Math.floor(Math.random() * 6) + 2; // 타이머 변수 stoptime

    setTimeout(function () {
        clearInterval(id); callback(stoptime);
    }, stoptime * 1000);

}

let evaluateSpeed = (stoptime) =>  {
    console.log(`stoptime: ${stoptime}`);
    switch (stoptime) {
        case 1:
        case 2:
        case 3:
            console.log("빠르네!!!!");
            break;
        case 4:
        case 5:
            console.log("수고했어!");
            break;
        default:
            console.log("느리다. 서둘러.");
            break;
    }
};

callWebService(evaluateSpeed);