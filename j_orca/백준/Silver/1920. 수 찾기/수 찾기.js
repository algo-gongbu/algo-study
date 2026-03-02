const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input); 


function solution(input) {
  const [N, aStr, M, mStr] = input;
  const A = new Set(aStr.split(' ').map(Number)); //set으로 중복 제거
  const answer = mStr.split(' ').map(Number)
    .map(num => A.has(num) ? '1' : '0') //reduce를 쓰게되면 JS의 문자열이 immutable이므로 메모리 상에서 기존 문자열을 버리고 새로운 문자열을 생성함 -> 생성/GC 수 증가
    .join(`\n`);

  console.log(answer.trim());
}

