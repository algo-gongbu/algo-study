const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
   const result = input.slice(1).map(line => 
    line.split('')
    .map(cur => cur == 'O' ? 1 : 0)
    .reduce((acc, cur) =>{
      if (cur == 1) {
        acc.sum += acc.count;
        acc.count++;
      } else {
        acc.count = 1;
      }
      return acc;
    }, {sum: 0, count: 1}).sum
  );
  console.log(result.join('\n'));
}