const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    let answer = '';
    for (const testCase of input.slice(0, -1)){
      const [a, b, c] = testCase.split(' ').map(Number).sort((a, b) => b - a);
      answer += `${(a ** 2 === ( b ** 2 ) + ( c ** 2)) ? 'right' : 'wrong'}\n`;
    }
    console.log(answer.trim());
}

