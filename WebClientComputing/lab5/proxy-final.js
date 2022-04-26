var Session;

let Session1 = {
    user: undefined,
}

let Session2 = {
    user: 'Hong',
}

function GeoCoder() { // 지리정보제공서비스: 주소를 받아 좌표 반환하는 메소드 하나
    this.getLatLng = function (address) {
        if (address === "Amsterdam") {
            return "52.3700° N, 4.8900° E";
        } else if (address === "London") {
            return "51.5171° N, 0.1062° W";
        } else if (address === "Paris") {
            return "48.8742° N, 2.3470° E";
        } else if (address === "Berlin") {
            return "52.5233° N, 13.4127° E";
        } else {
            return "";
        }
    };
}

function GeoProxy() {
    let geocoder = new GeoCoder();
    let geocache = {}; // 객체

    return {
        getLatLng: function (address) { //GeoCoder의 메소드를 똑같이 프록시함
            if (!geocache[address]) { // geocache에 이미 값이 있으면 GeoCoder을 호출하지 않고 geocache의 내의 값을 즉시 리턴
                geocache[address] = geocoder.getLatLng(address);
            }
            console.log(address + ": " + geocache[address]);
            return geocache[address];
        },
        getCount: function () { // 디버깅 목적
            let count = 0;
            for (let code in geocache) { count++; }
            return count;
        }
    };
};

function GeoSecurity(geo) {
    // 코드 추가

    return {
        getLatLng: function (address) {
            // 코드 추가
            if(Session.user == undefined) {console.log("로그인을 먼저 해주세요.");}
            else {
                geo.getLatLng(address);
            }
        },
        getCount: function () {
            // 코드 추가      
            if(Session.user == undefined) {return "error";}   
            else {
                return geo.getCount();
            }
        }
    };
};

// geolocation requests
function geoRequest(geo) { //geoCoder 13번 호출
    geo.getLatLng("Paris");
    geo.getLatLng("London");
    geo.getLatLng("London");
    geo.getLatLng("London");
    geo.getLatLng("London");
    geo.getLatLng("Amsterdam");
    geo.getLatLng("Amsterdam");
    geo.getLatLng("Amsterdam");
    geo.getLatLng("Amsterdam");
    geo.getLatLng("London");
    geo.getLatLng("London");

    console.log("Cache size: " + geo.getCount() + "\n");
}


//let geo = new GeoProxy();
let geo = new GeoSecurity(new GeoProxy());

console.log("(geolocation requests without login)");
Session = Session1;
geoRequest(geo);

console.log("(geolocation requests after login)");
Session = Session2;
geoRequest(geo);