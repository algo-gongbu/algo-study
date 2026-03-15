const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = Number(fs.readFileSync(filePath).toString().trim());

solution(input);

function solution(input) {
    let N = input; //내부 벌집을 감싼 외부 벌집의 갯수는 6의 배수로 증가함
    let i = 1
    while (N > 1){
      N -= 6*i;
      i++;
    }
    const answer = i;
    console.log(answer)
}