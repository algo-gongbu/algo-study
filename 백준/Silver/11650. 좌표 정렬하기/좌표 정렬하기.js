const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    input.shift() //slice는 array 데이터를 복제해서 데이터를 많이 잡아먹음. shift로 기존 array의 가장 앞 element만 빼버림
     const answer = input
      .map(line => line.split(' ').map(Number))
      .sort((a, b) => a[0] === b[0] ?  a[1] - b[1] : a[0] - b[0])
      .map(line => line.join(' '))
      .join('\n');
    
    console.log(answer);
}