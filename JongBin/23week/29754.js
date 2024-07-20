const fs = require("fs");
// const stdin = fs
//     .readFileSync("/dev/stdin")
//     .toString()
//     .split("\n")
//     .filter((line) => line.trim() !== "");
const stdin = fs.readFileSync("index.txt").toString().trim().split("\n");
const [N, M] = stdin.shift().split(" ").map(Number);
let answer = new Set();
let youtuber = {};
let week = 0;

for (let i = 0; i < M; i++) {
    const [name, day, startTime, endTime] = stdin[i].split(" ");
    const currentWeek = Math.floor((Number(day) - 1) / 7);

    if (week !== currentWeek) {
        week = currentWeek;
        for (const [key, value] of Object.entries(youtuber)) {
            if (value.day >= 5 && value.time >= 3600) {
                answer.add(key);
            }
        }
        youtuber = {};
    }

    if (!youtuber[name]) {
        youtuber[name] = { time: 0, day: 0 };
    }

    const [startHour, startMin] = startTime.split(":").map(Number);
    const [endHour, endMin] = endTime.split(":").map(Number);
    const duration = (endHour - startHour) * 60 + (endMin - startMin);

    youtuber[name].time += duration;
    youtuber[name].day += 1;
}

for (const [key, value] of Object.entries(youtuber)) {
    if (value.day >= 5 && value.time >= 3600) {
        answer.add(key);
    }
}

if (answer.size === 0) {
    console.log(-1);
} else {
    answer = Array.from(answer).sort();
    console.log(answer.join("\n"));
}
