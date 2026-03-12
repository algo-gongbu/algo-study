const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = Number(fs.readFileSync(filePath).toString().trim());

solution(input);

function solution(input) {
  let pack = 0; 
  while (input >= 0){
    if(input % 5 == 0){
      pack += input/5;
      break;
    } else {
      pack += 1
      input -= 3;
    }
  }
  console.log((input >= 0) ? pack : -1);
}
