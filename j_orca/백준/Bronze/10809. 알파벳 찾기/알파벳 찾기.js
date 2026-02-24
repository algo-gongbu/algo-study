const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const S = input[0];
    const alphabet = "abcdefghijklmnopqrstuvwxyz";
    const answer = alphabet.split('').map(char => S.indexOf(char));
    
    console.log(answer.join(' '));
}