const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input); 


function solution(input) {
  const [N, nStr, M, mStr] = input;
  const ndic = new Map();
  nStr.split(' ')
    .forEach(num => (ndic.has(num)) ? ndic.set(num, ndic.get(num) + 1) : ndic.set(num, 1)); // ndic.set(num, (ndic.get(num) || 0) + 1)로 단축하여 표현가능
  const answer = mStr.split(' ')
    .map(num => (ndic.has(num)) ? ndic.get(num) : '0') 
    .join(' ');

  console.log(answer.trim());
}