const fs = require('fs');

const filePath = process.platform === 'linux' ? '/dev/stdin' : './input.txt';

let input = fs.readFileSync(filePath).toString().trim().split('\n');

solution(input);

function solution(input) {
    const [comNum, edgeNum] = input.slice(0, 2).map(Number)
    const edges = input.slice(2).map(line => line.split(' ').map(Number));
    const graph = Array.from({length: comNum + 1}, () => []);
    const visited = Array(comNum + 1).fill(false);

    for (const edge of edges){
      graph[edge[0]].push(edge[1]); //배열에 추가해야하기에 push로 배열에 값을 추가한다.
      graph[edge[1]].push(edge[0]);
    }

    function dfs(node){
      visited[node] = true;
      for (const connectedNode of graph[node]){
        if(!visited[connectedNode]){
          dfs(connectedNode);
        }
      }
    }
    dfs(1);

    console.log(visited.filter(Boolean).length - 1); //filter 사용시 filter(v => v === true) 혹은 filter(Boolean)으로 사용한다.
    // 또한 답변은 1번 컴퓨터를 제외하고 내야한다.
}