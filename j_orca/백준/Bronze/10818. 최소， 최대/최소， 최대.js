const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const numbers = input[1].split(' ').map(Number);
    const [min, max] = numbers.reduce((acc, cur) => {
      if (acc[0] > cur) acc[0] = cur;
      if (acc[1] < cur) acc[1] = cur;

      return acc;
    }, [numbers[0], numbers[0]]);
      console.log(`${min} ${max}`);
    }