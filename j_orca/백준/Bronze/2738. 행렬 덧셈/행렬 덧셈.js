const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const [N, M] = input[0].split(' ').map(Number);
    const A = input.slice(1,  N + 1).map(line => line.split(' ').map(Number));
    const B = input.slice(N + 1).map(line => line.split(' ').map(Number));
    let answer = '';
    for (let i = 0; i < N ; i++){
      answer += `${addArray(A[i], B[i]).join(' ')}\n`;
    }
    console.log(answer.trim());
}

function addArray(a, b) {
    return a.map((element, index) => element + b[index]);
}