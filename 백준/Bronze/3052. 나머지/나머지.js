const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const remainder = input.map(num => Number(num) % 42);
    const answer = new Set(remainder).size;
    console.log(answer);
}