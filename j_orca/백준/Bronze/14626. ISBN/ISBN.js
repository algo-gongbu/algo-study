const fs = require('fs');

const filePath = process.platform === 'linux' ? 0 : './input.txt'; //'/dev/stdin' 접근 권환 에러 해결


let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const isbn = input[0].split('');
    const starWeight = isbn.indexOf('*') % 2 === 1 ? 3 : 1;

    // const calc = 10 - isbn.map((target, index) => (target === '*') ? target : ((index % 2) * 2 + 1) *  Number(target))
    //   .filter((target) => typeof(target) === 'number')
    //   .reduce((acc, cur) => acc+cur, 0) % 10;
    // 체이닝이 길어지면 오히려 디버깅이 힘들어질 때가 있다
    
    const sum = isbn.reduce((acc, cur, index) => {
        if (cur === '*') return acc; 
        const weight = ((index % 2) * 2 + 1); 
        return acc + (Number(cur) * weight);
    }, 0);

    const targetCalc = (10 - (sum % 10)) % 10

    // 0부터 9까지 하나씩 넣어보면서 가중치를 곱한 뒤 % 10 한 값이 targetCalc와 같은지 확인 O(1)
    for (let i = 0; i <= 9; i++) {
        if ((i * starWeight) % 10 === targetCalc) {
            console.log(i);
            break;
        }
    }
}