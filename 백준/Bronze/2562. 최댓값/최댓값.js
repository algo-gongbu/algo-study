const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const answer = input.map(Number).reduce((acc, cur, index) => acc[0] < cur ? [cur, index + 1] : acc, [0, 0]) //acc를 array로 만들어서 값과 index를 저장한다면?
    //js => 뒤에 {}가 없다면 자동으로 return해주는 implicit return 기능이 있음
    console.log(answer.join('\n'));
}