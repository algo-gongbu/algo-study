const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

const input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input){
  const [N, M] = input[0].split(' ').map(Number);
  const numbers = input[1].split(' ').map(Number);
  // let maxSum = 0; Brute Force
  // for (let i = 0; i < N - 2; i++){
  //   for (let j = i + 1; j < N - 1; j++){
  //     for (let k = j + 1; k < N; k++){
  //       const newNum = numbers[i] + numbers[j] + numbers[k];
  //       maxSum = (maxSum < newNum && newNum <= M) ? newNum : maxSum;
  //       if (maxSum == M) {
  //         console.log(maxSum);
  //         return;
  //       }
  //     }
  //   }
  // }
  numbers.sort((a, b) => a - b);
  let maxSum = 0;
  for (let i = 0; i < N - 2; i++){
    let left = i + 1;
    let right = N - 1;
    while (left < right) {
      const newSum = numbers[i] + numbers[left] + numbers[right];
      if (newSum <= M) {
        maxSum = Math.max(maxSum,newSum);
        if (newSum == M) {
          console.log(maxSum);
          return;
        } else left += 1;
      } else right -= 1;
      }
    }
    console.log(maxSum);
}