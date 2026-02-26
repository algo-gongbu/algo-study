const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
  let answer = "";
  for (const testCase of input.slice(1)){
    const [H, W, N] = testCase.split(' ').map(Number);
    answer += `${jiwoo(H, W, N)}\n`;
  }
  console.log(answer.trim());
}

function jiwoo(H, W, N){
  const floor = (N % H == 0) ? H : N%H;
  const room = Math.ceil(N / H);

  return `${floor}${String(room).padStart(2,'0')}`;
}