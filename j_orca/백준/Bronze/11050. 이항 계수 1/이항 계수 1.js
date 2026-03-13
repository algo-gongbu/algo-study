const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
  const [N, K] = input[0].split(' ').map(Number);
  let acc = 1;
  const cache = Array.from({length: N + 1}, (_, i) => i === 0 ? acc : acc *= (i));
  const answer = cache[N] / (cache[N-K] * cache[K]);
  console.log(answer);
} 