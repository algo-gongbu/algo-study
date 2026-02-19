const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const [A, B, C] = input;
    const answer = `${+A + +B - C}\n${A + B - C}`; //JS는 +단항 연산자를 붙여 Number casting을 대신할 수 있다.
    console.log(answer);
} 