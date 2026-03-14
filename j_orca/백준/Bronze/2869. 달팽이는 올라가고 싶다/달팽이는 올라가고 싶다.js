const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
  const [A, B, V] = input[0].split(' ').map(Number); 
  const answer = Math.ceil((V - A) / (A - B)) + 1;
  console.log(answer);
}