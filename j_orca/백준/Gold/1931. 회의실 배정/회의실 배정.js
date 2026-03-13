
const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const schedules = input.slice(1).map(line => line.split(' ').map(Number));
    schedules.sort((a, b) => a[1] === b[1] ? a[0] - b[0] : a[1] - b[1]);
    let endtime = 0;
    let answer = 0;


    for (const [start, end] of schedules){
      if (endtime <= start) {
        endtime = end;
        answer ++;
      }
    }
    console.log(answer);
} 