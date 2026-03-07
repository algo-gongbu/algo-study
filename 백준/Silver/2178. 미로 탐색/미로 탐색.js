class Node {
  constructor(value){
    this.value = value;
    this.next = undefined;
  }
}

class Queue {
  constructor(){
    this.head = undefined;
    this.tail = undefined;
    this.length = 0;
  }
  add(node) {
    if (this.length === 0) {
      this.head = node;
      this.tail = node;
    } else {
    this.tail.next = node;
    this.tail = node;
    }
    this.length = this.length + 1;
  }

  delete() {
    if (this.length === 0) {
      throw new Error('There is no node in queue')
    } 
    const _head = this.head;
    this.length = this.length - 1;
    if (this.length === 0) {
      this.head = undefined;
      this.tail = undefined;
    } else {
    this.head = this.head.next;
    }
    return _head;
  }
}


const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input); 


function solution(input) {
  const [N, M] = input[0].split(' ').map(Number);
  const maze = input.slice(1).map(line => line.split('').map(Number));

  const answer = BFS(N, M, maze);
  console.log(answer);
}

function BFS(N, M, maze){

  const visited = Array.from({ length: N }, () => Array(M).fill(false));
  // 상, 하, 좌, 우 순서대로 x와 y의 변화량을 배열로 만듭니다.
  const dx = [-1, 1, 0, 0]; // 행(세로) 변화량
  const dy = [0, 0, -1, 1]; // 열(가로) 변화량
  const queue = new Queue;

  queue.add(new Node({ x: 0, y: 0, dist : 1}));
  visited[0][0] = true;
  
  while(queue.length > 0){
    const {x, y, dist} = queue.delete().value;

    if (x == N - 1 && y == M -1){ // arrived at destination
      return dist;
    }
    
    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i]; // next x
      const ny = y + dy[i]; // next y
      
      if ((nx >= 0 && nx < N ) && (ny >= 0 && ny < M) && (maze[nx][ny] === 1) && (!visited[nx][ny])){
            visited[nx][ny] = true;
            queue.add(new Node({x : nx, y: ny, dist: dist + 1}));
          } 
        }
      } 
}