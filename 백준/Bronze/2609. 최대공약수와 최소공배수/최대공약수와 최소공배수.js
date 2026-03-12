const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const [a, b] = input[0].split(' ').map(Number);
    let getGCD = (num1, num2) => (num2 > 0 ? getGCD(num2, num1 % num2) : num1);

    const gcd = getGCD(a, b);
    const lcm = Math.min(a, b) * (Math.max(a, b)/ gcd);
    console.log([gcd, lcm].join('\n'));
}
    
