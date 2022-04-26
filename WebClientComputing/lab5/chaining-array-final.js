function MyArray(array) {
    this.array = array ? array : [];

    // 필요 문장 추가 위치
    console.log(`초기배열: ${this.array}`);
}

MyArray.prototype.push = function (val) {
    // 필요 문장 추가 위치
    console.log(`값추가: ${val}`);
    this.array.push(val);
    return this;
}

MyArray.prototype.pop = function () {
    // 필요 문장 추가 위치
    let x = this.array[this.array.length-1];
    this.array = this.array.slice(0,this.array.length-1);
    console.log(`값제거: ${x}`);
    return this;
}

MyArray.prototype.list = function () {
    // 필요 문장 추가 위치
    console.log(`현재 배열 값: ${this.array}`);
    return this;
}

x = new MyArray([600, 800, 300]).push(50000).push(10000).push(5000)
     .list().pop().pop().list().push(50).list();

console.log();

new MyArray().push(50000).push(10000).push(5000)
     .list().pop().pop().list().push(50).list();