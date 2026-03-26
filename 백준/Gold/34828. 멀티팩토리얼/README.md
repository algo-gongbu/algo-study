# [Gold I] 멀티팩토리얼 - 34828 

[문제 링크](https://www.acmicpc.net/problem/34828) 

### 성능 요약

메모리: 237180 KB, 시간: 236 ms

### 분류

다이나믹 프로그래밍, 제곱근 분할법

### 제출 일자

2026년 3월 26일 15:59:29

### 문제 설명

<p>백준 온라인 저지에는 $n!!! \cdots\, !$에 관련된 <a href="/problem/18373">다양한</a> <a href="/problem/31458">문제</a>들이 있다. 그런데 사실 이러한 문제들에서 사용한 용법과는 달리, $n!!! \cdots\, !$이라는 기호는 $n$에 팩토리얼을 여러 번 적용하라는 뜻이 아니다! 예를 들어, <strong>더블 팩토리얼</strong>이라고도 불리는 $n!!$은, 그 의미가 $(n!) !$과는 다르게 사용되는 기호이다.</p>

<p>실제 더블 팩토리얼의 정의는 다음과 같다.</p>

<p>\[n!!=\begin{cases}n\cdot(n-2)\cdot(n-4)\cdots 5\cdot 3\cdot 1&(\text{odd } n)\\ n\cdot(n-2)\cdot(n-4)\cdots 6\cdot 4\cdot 2&(\text{even } n)\end{cases}\]</p>

<p>예를 들어, $6!!=6\times 4\times 2=48$, $9!!=9\times 7\times 5\times 3\times 1=945$이다.</p>

<p>마찬가지로, $n!!!=n(n-3)(n-6)\cdots$, $n!!!!=n(n-4)(n-8)\cdots$ 등도 정의할 수 있다. $n$을 $k$로 나눈 나머지를 $r$이라고 하면, <strong>멀티팩토리얼</strong>의 정의는 다음과 같다.</p>

<p>\[n\overbrace{!!!\cdots\, !}^{k}=\begin{cases}n\cdot(n-k)\cdot(n-2k)\cdots r & (r \gt 0 ) \\ n\cdot(n-k)\cdot(n-2k)\cdots k& (r=0) \end{cases}\]</p>

<p>양의 정수 $N$, $K$가 주어지면 $N\overbrace{!!!\cdots\, !}^{K}$의 값을 구해보자. 단, 수가 매우 커질 수 있으므로 $998\, 244\, 353$으로 나눈 나머지를 출력한다.</p>

### 입력 

 <p>첫째 줄에 쿼리의 수 $Q$가 주어진다. ($1\leq Q\leq 100\, 000$)</p>

<p>다음 $Q$개의 줄에 걸쳐, 양의 정수 $N$과 $K$가 공백으로 구분되어 주어진다. ($1\leq N,K\leq 100\, 000$)</p>

### 출력 

 <p>각 쿼리마다 $N\overbrace{!!!\cdots\, !}^{K}\mod 998\, 244\, 353$을 한 줄에 하나씩 출력한다.</p>

