const fs = require("fs");
const stdin = fs.readFileSync("/dev/stdin").toString().split("\n");
// const stdin = fs.readFileSync("index.txt").toString().trim().split("\n");
const [n, w, L] = stdin.shift().split(" ").map(Number);
const bus = stdin.shift().split(" ").map(Number);
let time = 0;
let sum = 0;
let q = Array(w).fill(0);
let arrive = 0;
while (arrive < n) {
    time++;
    sum -= q.shift();
    if (sum + bus[arrive] <= L) {
        q.push(bus[arrive]);
        sum += bus[arrive];
        arrive++;
    } else {
        q.push(0);
    }
}
console.log(time + w);
