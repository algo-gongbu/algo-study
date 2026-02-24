const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const result = String(input.map(Number).reduce((acc, cur) => acc * cur)).split('');
    let answer = new Array(10).fill(0);

    for (const one of result){
      answer[Number(one)] += 1;
    }
    console.log(answer.join('\n'));
}