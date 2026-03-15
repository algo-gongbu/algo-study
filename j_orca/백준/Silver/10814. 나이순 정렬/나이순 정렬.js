const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const userInfo = input.slice(1).map(line => line.split(' ')); //parseInt는 숫자 부분만 인식하고 나머지는 무시하기 때문에 이를 이용해 split join을 생략하고 sort부분의 숏코딩할 수 있음
    const answer = userInfo.sort((a, b) => a[0] - b[0]) //js는 stable sort를 지원하기 때문에 동일한 값을 갖는 데이터에 대해서 원래 순서를 바꾸지 않고 그대로 유지해줌.
    .map(line => line.join(' '));
    console.log(answer.join('\n'));
}