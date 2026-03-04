const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input); 


function solution(input) {
  const testCases = input.slice(1);
  const answer = testCases.map((testCase) => isValidVPS(testCase) ? `YES` : `NO`).join('\n'); //testCase.split('')으로 배열에 할당할 필요 없이 testCase 문자 순회 
  // 긴 텍스트 입력을 받아서 파싱해야하는 경우 그때마다 배열로 쪼개면 메모리 낭비. 문자열 자체를 iterable로 디자인해서 메모리 효율 극대화.
  // answer += ... 는 문자열의 삭제와 추가를 반복하며 메모리 낭비 및 GC 발생
  console.log(answer.trim());
}

function isValidVPS(str){
  const stack = [];
  for (const char of str){
    if (char === '('){
      stack.push(char);
    } else if (stack.length === 0) return false
    else stack.pop(); 
  } return (stack.length === 0);
}

