const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const words = input[0].trim().split(' ');
    const answer = (words[0] === '') ? 0 : words.length; //const answer = words.filter(Boolean).length; 이렇게 하면 빈문자열 0, null, undefined 를 싹 날려줌.
    console.log(answer);
}