const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const numbers = input[0].split(' ').map(Number);
    const answer = KOI(numbers);

    console.log(answer);
}

function KOI(numbers){
  const sumOfSquares = numbers.reduce((acc, cur) => acc + (cur ** 2), 0);
  return sumOfSquares % 10;
}
