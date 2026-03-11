  const fs = require('fs');

  const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

  let input = fs.readFileSync(filePath).toString().trim().split('\n');

  solution(input);

  function solution(input) {
      let i = 0;
      let answer ='';
      while (input[i] != 0){
        const word = input[i];
        // const mid = Math.floor(word.length / 2);
        // let answerI = true;
        
        // for (let j = 0; j < mid ; j++){
        //   answerI = answerI && word[j] == word[(word.length - 1 )- j];
        //   if (!answerI) break;
        // }
        
        const answerI = word === word.split('').reverse().join(''); //method chaining을 이용한 방법
      
        answer += `${answerI ? 'yes' : 'no'}\n`
        i++;

        
      }

      console.log(answer.trim());
  }