const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const submit = input.map(Number);
    let answer = '';
    for (let i = 1; i <= 30; i++){
      answer += submit.includes(i) ? '' : `${i}\n`;
    }

    
    console.log(answer.trim());
}