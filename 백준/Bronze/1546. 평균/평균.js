const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const scores = input[1].split(' ').map(Number);
    const M = Math.max(...scores);
    const answer = avg(scores.map((score) => (score / M) * 100));
    console.log(answer);
}

function avg(scores){
  return scores.reduce((sum, cur) => sum + cur, 0) / scores.length;
}