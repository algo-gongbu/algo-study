const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = Number(fs.readFileSync(filePath).toString().trim());

solution(input); 


function solution(input) {
  const N = input;
  const nArr = Array.from({length: N}, (v, i) => i + 1);
  let head = 0;
  while (nArr.length - head > 1){
    head++;
    nArr.push(nArr[head]);
    head++;
  }
  console.log(nArr[head]);
}