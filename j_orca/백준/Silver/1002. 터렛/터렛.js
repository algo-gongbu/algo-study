const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';


let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const T = Number(input[0]);

    for (let i = 1; i <= T; i++) {
        const [x1, y1, r1, x2, y2, r2] = input[i].split(' ').map(Number);
        const result = getIntersectionCount(x1, y1, r1, x2, y2, r2);
        console.log(result);
    }
}

function getIntersectionCount(x1, y1, r1, x2, y2, r2) {
    const d = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    const sum = r1 + r2;
    const diff = Math.abs(r1 - r2); 

    // 1. 무한대 
    if (d === 0 && r1 === r2) {
        return -1;
    }
    // 2. 안 만나는 경우 (너무 멀거나, 안에 쏙 들어감)
    else if (d > sum || d < diff) {
        return 0;
    }
    // 3. 한 점에서 만나는 경우 (외접 또는 내접)
    else if (d === sum || d === diff) {
        return 1;
    }
    // 4. 그 외 (두 점에서 만남)
    else {
        return 2;
    }
}
