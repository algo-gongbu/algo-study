const fs = require('fs');

const filePath = process.platform === 'linux' ? 0 : './input.txt'; //'/dev/stdin' 접근 권환 에러 해결


let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const Xs = input[1].split(' ').map(Number); //set를 sort해서 뽑아 낸다면?
    const noDuplication =  [...new Set(Xs)].sort((a, b) => a - b);

    const dict = {};

    noDuplication.forEach((val, index) => { //forEach는 undefine을 반환하지만 map은 새로운 배열을 반환한다. forEach는 method chaining 불가능 (출력값이 없기에)
      dict[val] = index;
    })
    const answer = Xs.map((x) => dict[x]).join(' ');
    console.log(answer);
}