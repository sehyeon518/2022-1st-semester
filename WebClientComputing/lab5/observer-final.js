function EventObserver() {
    this.observers = [];
}

EventObserver.prototype.subscribe = function (fn) {
    this.observers.push(fn);
}

EventObserver.prototype.unsubscribe = function (fn) {
    this.observers = this.observers.filter((subscriber) => subscriber !== fn);
}

EventObserver.prototype.broadcast = function (data) {
    this.observers.forEach((subscriber) => subscriber(data));
}

const blogObserver = new EventObserver();

const blogPost = document.getElementById('blogPost');
blogPost.addEventListener('keyup', () => blogObserver.broadcast(blogPost.value));

const getLetterCount = (text) => text ? text.trim().split("").length : 0;
const getWordCount = (text) => text ? text.trim().split(/\s+/).length : 0;
const getLineCount = (text) => text ? text.trim().split(/\n+/).length : 0;

blogObserver.subscribe((text) => {
    const blogLetterCount = document.getElementById('letter');
    const blogWordCount = document.getElementById('word');
    const blogLineCount = document.getElementById('line');
    blogLetterCount.textContent = getLetterCount(text);
    blogWordCount.textContent = getWordCount(text);
    blogLineCount.textContent = getLineCount(text);
    document.getElementById("ltsize").style.width = (10*parseInt(getLetterCount(text))) + "px";
    document.getElementById("wdsize").style.width = (10*parseInt(getWordCount(text))) + "px";
    document.getElementById("lnsize").style.width = (10*parseInt(getLineCount(text))) + "px";
});

