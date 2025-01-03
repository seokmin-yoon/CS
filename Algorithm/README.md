# 1. 정렬 (Sorting)

## 1.1. 기본 정렬 알고리즘
버블 정렬

선택 정렬

삽입 정렬

## 1.2. 고급 정렬 알고리즘
병합 정렬

퀵 정렬

힙 정렬

기수 정렬

계수 정렬

셸 정렬

# 2. 탐색 (Search)
선형 탐색

이진 탐색

이진 탐색 변형

탐색 알고리즘의 시간 복잡도 분석

# 3. 재귀 및 분할 정복 
## 3.1. 재귀 (Recursion)

## 3.2. 분할 정복 (Divide and Conquer)
병합 정렬

퀵 정렬

이진 탐색

## 3.3. 백트래킹 (Backtracking)

# 4. 그리디 알고리즘 (Greedy Algorithm)
동전 문제

활동 선택 문제

최소 신장 트리

# 5. 동적 계획법 (Dynamic Programming)
피보나치 수열

배낭 문제

최장 공통 부분 시퀀스

최단 경로

# 6. 그래프 알고리즘
## 6.1. 탐색
깊이 우선 탐색

너비 우선 탐색

## 6.2. 최단 경로
### 다익스트라 알고리즘
- **특징**
    - 하나의 시작 정점에서 다른 정점까지의 최단 경로를 구함
    - Greedy Algorithm
    - 음수 가중치 처리 불가
    - 방향 및 무방향 그래프 모두에 적용 가능
    - 정점 수에 비례한 시간 복잡도
- **작동 과정**
    1. **초기화**
        1. 시작 정점 s 선택
        2. 각 정점 v에 대한 최단 경로를 나타내는 배열 distance 준비
        3. 후보자 집합 C 준비: 그래프의 정점 집합 N으로 설정
        4. 솔루션 집합 S 준비: 최단 경로에 포함된 정점들의 집합으로, 처음엔 공집합으로 설정
    2. **최소 거리 정점 선택**
        1. 집합 C에서 최소 거리를 가지는 정점 u를 선택
        2. 선택된 정점 u를 집합 S에 추가하고, 집합 C에서는 제거
    3. **인접 정점에 대한 거리 갱신**
        1. 현재 정점 v의 최단 경로 d[v]가 u를 거쳐서 v에 도달하는 경로 보다 크다면, 최단 경로 값을 갱신
            
            $$
            distance[v]=min(distance[v], distance[u]+weight[u][v])
            $$
            
    4. **반복 및 종료**
        1. 집합 C에서 처리 되지 않은 정점이 있을 경우 2, 3번 과정을 반복
        2. 집합 C가 공집합이 되면, 모든 정점에 대한 최단 경로가 계산되어 종료
- **의사 코드(pseudo code)**
```c
function Dijkstra(G = (N, E; W), s)
{
	for (each vertex v ∈ N) do {
		d[v] ← ∞;
		π[v] ← NIL;
	}
	d[s] ← 0;
	S ← ∅;
	C ← N;
	while (C ≠ ∅) do {
		u ← ExtraMin(C);
		S ← S ∪ {u};
		C ← C - {u};
		for (each vertex v ∈ Adj[u]) do {
			if (d[v] > d[u] + w(u, v)) then {
				d[v] ← d[u] + w(u, v);
				π[v] ← u;
			}
		}
	}
	return (d);
}
```  
- **Example**
    - 구현
    - 실행 결과

### 벨만-포드 알고리즘
- **특징**
    - 하나의 시작 정점에서 다른 정점까지의 최단 경로를 구함
    - Dynamic Programming Algorithm
    - 음수 가중치 처리 가능, 음수 사이클 감지
    - 그래프의 모든 간선에 대한 최단 경로를 갱신
    - 간선 수에 비례한 시간 복잡도
- **작동 과정**
    1. **초기화**
        1. 시작 정점 s 선택
        2. 각 정점 v에 대한 최단 경로를 나타내는 배열 distance 준비
    2. **간선에 대한 최단 경로 갱신**
        1. 그래프의 모든 간선 (u, v)에 대해 |V| - 1번 반복하며, 최단 경로 값을 갱신
            
            $$
            distance[v]=min(distance[v], distance[u]+weight[u][v])
            $$
            
    3. **음수 사이클 감지**
        1. 모든 간선 (u, v)에 대해 한번 더 확인하여 음수 사이클이 존재하는지 확인
            1. 음수 사이클 있음: FALSE 반환
            2. 음수 사이클 없음: TRUE 반환
        2. 음수 사이클이 발견되지 않으면 최단 경로 계산을 정상적으로 종료
- **의사 코드 (pseudo code)**
```c
function Bellman-Ford(G = (N, E; W), s)
{
	for (each vertex v ∈ N) do {
		d[v] ← ∞;
		π[v] ← NIL;
	}
	d[s] ← 0;
	for (i ← 1 to |V| - 1) do {
		for (each edge(u, v) ∈ E) do {
			if (d[v] > d[u] + w(u, v)) then {
				d[v] ← d[u] + w(u, v);
				π[v] ← u;
			}
		}
	}
	for (each edge(u, v) ∈ E) do {
		if (d[v] > d[u] + w(u, v)) then
			return FALSE;	
	}
	return TRUE;
}
```
- **Example**
    - 구현
    - 실행 결과
### 플로이드-워셜 알고리즘
- **특징**
    - 모든 정점 사이의 최단 경로를 구함
    - 인접 행렬 사용
    - Dynamic Programming Algorithm
    - 음수 가중치 처리 가능, 음수 사이클 감지
    - 각 정점 간의 경로를 경유지를 기준으로 갱신
- **작동 과정**
    1. 초기화
        1. 인접 행렬 준비: 입력 행렬 L, 거리 행렬 D 
    2. 경유지를 기준으로 최단 경로 갱신
        1. 정점 쌍 i, j에 대해, 중간 정점 k을 거쳐 가는 경로가 더 짧다면 그 값으로 갱신
            
            $$
            distance[i][j]=min(distance[i][j], distance[i][k]+distance[k][j])
            $$
            
    3. 모든 중간 정점 k에 대해 각 정점 쌍 (i, j)을 반복
    4. 모든 중간 정점이 처리되면 종료
- **의사 코드 (pseudo code)**
```c
function Floyd-Warshall(L[1...n, 1...n])
{
	D ← L;
	for (k ← 1 to n) do {
		for(i ← 1 to n) do {
			for(j ← 1 to n) do {
				D[i, j] = min(D[i, j], D[i, k] + D[k, j])
			}
		}
	}
	return D;
}
```
- **Example**
    - 구현
    - 실행 결과

## 6.3. 최소 신장 트리
### 크루스칼 알고리즘
- **특징**
    - 간선 중심
    - 간선을 가중치 순으로 정렬하여 최소 신장 트리를 구성하는 방법
    - Greedy Algorithm
- **작동 과정**
    1. 먼저 그래프 G의 모든 간선을 가중치에 따라 오름차순으로 정렬
    2. 그래프 G에 가중치가 가장 낮은 간선을 최소 비용 신장 트리(MST) 집합에 삽입
        1. 단, 싸이클을 형성하지 않는 간선을 삽입
    3. 그래프 G에 간선이 n-1개가 아니라면 2를 반복
    4. 그래프 G의 간선이 n-1개 라면 최소 신장 트리 완성
- **의사 코드 (pseudo code)**
```c
function Kruskal(G = (N, E; W))
{
	sort E by non-decreasing lenght;
	T ← ∅;
	n ← |N|;
	initialize n sets each containing a different element of N
	for (each edge(u, v) ∈ E) in order by non-decreasing lenght
	{
		if (find_set(u) ≠ find_set(v)) then {
			T ← T ∪ {(u, v)}
			union (u, v)
		}
	}
	return (T);
}	
```
- **Example**
    - 구현
    - 실행 결과

### 프림 알고리즘
- **특징**
    - 정점 중심
    - 하나의 정점에서 시작하여 최소 신장 트리를 확장해 나가는 방법
    - Greedy Algorithm
- **작동 과정**
    1. 그래프 G에서 시작 정점을 선택
    2. 현재 정점에 부속된 모든 간선 중에서 가중치가 가장 낮은 간선을 최소 비용 신장 트리(MST) 집합에 삽입하여 트리를 확장
    3. 그래프 G에 간선이 n-1개가 아니라면 2를 반복 수행
    4. 그래프 G의 간선이 n-1개 라면 최소 신장 트리 완성
- **의사 코드 (pseudo code)**
```c
function Prim(G = (N, E; W))
{
	T ← ∅;
	B ← {an arbitrary element of N}
	while (B ≠ N)
	{
		find(u, v) of minimum lenght such that u ∈ B and v ∈ N-B
		T ← T ∪ {(u, v)}
		B ← B ∪ {v}
	}
	return (T);
}
```
- **Example**
    - 구현
    - 실행 결과

## 6.4. 위상 정렬

## 6.5. 네트워크 플로우
에드몬드-카프 알고리즘

푸시-재명칭 알고리즘

# 7. 문자열 알고리즘
## 7.1. 문자열 검색
KMP 알고리즘

라빈-카프 알고리즘

## 7.2. 접미사 배열 및 트라이
접미사 배열

접미사 트리

## 7.3. 롤링 해시 및 Z-알고리즘
# 8. 수학 및 수치 알고리즘
유클리드 호제법

소수 판별

에라토스테네스의 체

빠른 거듭제곱

행렬 연산

모듈러 연산 및 중국인의 나머지 정리

# 9. 조합 및 확률
순열 및 조합

비트마스트를 활용한 부분집합 생성

조합 최적화 문제

# 10. 기타 알고리즘
슬라이딩 윈도우

분할-정복적 접근법

유니온-파인트

두 포인터 기법

스위핑 기법

랜덤화 알고리즘

# 11. 알고리즘 분석
시간 복잡도

공간 복잡도

최선의 경우

평균의 경우

최악의 경우

