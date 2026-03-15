  const fs = require('fs');

  const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

  let input = fs.readFileSync(filePath).toString().trim();

  solution(input);

  function solution(input) {
      const ascending = [1, 2, 3, 4, 5, 6, 7, 8].join(' ');
      const descending = [8, 7, 6, 5, 4, 3, 2, 1].join(' ');

      const numbers = input;
      const answer = (numbers === ascending) ? 'ascending' : (numbers === descending) ? 'descending' : 'mixed';
      console.log(answer);
      }