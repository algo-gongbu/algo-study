const fs = require('fs');

const filePath = process.platform === 'linux' ? 0 : './input.txt'; //'/dev/stdin' 접근 권환 에러 해결


let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const [x, y] = input[0].split(' ').map(Number); 
    const answer = apt(x, y);
    console.log(answer);
}

function apt(A, B){
  return (A**2 - B**2); //java Numnber type is only safty to 9,007,199,254,740,991
}