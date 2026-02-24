const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const notSameInput = [...new Set(input.slice(1))];
    const answer = notSameInput.sort((a, b) => { // => 에서 {} 사용시 항상 return으로 결과값을 내놔야함.
      return (a.length == b.length) ? a.localeCompare(b) : a.length - b.length;
    });
    console.log(answer.join('\n'));
}