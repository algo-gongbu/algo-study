# [Silver III] 가위 바위 보 - 8896 

[문제 링크](https://www.acmicpc.net/problem/8896) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

구현, 시뮬레이션

### 제출 일자

2026년 3월 18일 20:08:38

### 문제 설명

<p>We have robots who can play the “Rock Paper Scissors (RPS)” game. This game consists of k successive rounds. Each robot keeps a predefined sequence of k hands in a string of length k. In the game the disqualified robots will be eliminated and the game will go on with the remaining robots. The game is over if only one winner remains. If there are more than one robots survived after k rounds, the game should be declared a “draw”. <br>
 <br>
Let R, P and S denote Rock, Paper and Scissor, respectively. If the hand string is “RSPSRSSP”, then the robot will show “Rock” in the first round and “Scissors” in the next round. And in the final 8th round the robot will show “Paper” only if he is not disqualified during the game. In the game if only one winner remains after the i-th round competition, then the robot RPS game terminates in the i-th round and you should report the winner robot. The game may not terminate depending on the RPS sequences after k rounds have passed. Then you should report 0(zero) to declare a “draw” ending. </p>

### 입력 

 <p>Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case starts with the integer N to denote the number of robots participating. Then the predefined RPS strings of length k are given in the following N lines one by one. Note that 2 ≤ N ≤ 10 and k, the length of the RPS sequence string, is restricted to 3 ≤ k ≤ 30. For each test case, the robots are numbered 1 to N sequentially from top. </p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one integer to denote the robot number of the one winner, if it exists. If there is no winner after the k rounds competition, then you should print zero(0) to denote the “draw” ending. </p>

