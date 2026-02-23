const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const numbers = input[0].trim().split(' ');
    let answer = 0;
    for (const num of numbers){
      const newNum = sangSu(num);
      answer = (answer > newNum) ? answer :  newNum;
    }
    // 그러나 const answer = Math.max(...numbers.map(sangSu)); 처럼 spread (...)과 Math.max()함수를 이용하면 const 형태로 answer 표현 가능
    console.log(answer);
}

function sangSu(number){
  return Number(number.split('').reverse().join(''));
}