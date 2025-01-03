# 1. 컴퓨터 구조와 개요
## 1.1. 컴퓨터 구조란 무엇인가?
## 1.2. 컴퓨터 시스템의 발전과 역사
| 세대 별 | 1세대 | 2세대 | 3세대 | 4세대 | 5세대 |
| --- | --- | --- | --- | --- | --- |
| 시기 | 1940년대 중반 | 1950년대 중반 | 1960년대 중반 | 1970년대 중반 | 1980년대~현재 |
| 주요 소자 | 진공관 | 트랜지스터 | 집적회로(IC) | (초)대규모 집적회로(LSI, VLSI) |  |
| 사용 언어 | - 기계어
- 어셈블리 언어 | 고급 언어 | 고급 언어 | 고급 언어 | 객체 지향 언어 |
| 특징 | - 넓은 공간 필요
- 발열 많음
- 전력 소모 큼
- 처리 속도 느림
- 과학 계산용 | - 작은 부피
- 고급 언어 개발
- 시스템 소프트웨어 출현
- DEC 설립
- 실시간 처리 시스템 실용화
- 일반 사무용 | - 미세 전자공학
- 시분할 및 다중 처리
- 입력 장치 사용
(OMR, OCR 등) | - 개인용 컴퓨터 등장
- 슈퍼 컴퓨터 등장
- 컴퓨터를 이용한 자동화 실현
- 가상 기억 장치 기법 도입 | - 초소형화/초고속화 실현
- 클러스터 컴퓨터
- 클라우드 컴퓨팅 |
| 예 | ENIAC,
UNIVAC | IBM 1401
 | IBM System/360,
DEC PDP-8 | IBM 370 계열 |  |
## 1.3. 컴퓨터 구성 요소
### 개요

- **폰 노이만 구조: IAS**
    - 단일 메모리
    - 명령어 순차 실행
    - 중앙 처리 장치
    - 기계어 기반 명령어
- 컴퓨터 시스템의 하드웨어 및 소프트웨어 접근법
    - **하드웨어 프로그래밍:**
        1. 데이터 입력
        2. 산술 및 논리 연산
        3. 결과 출력
    - **소프트웨어 프로그래밍:**
        1. 명령어 및 데이터 입력
        2. 명령어 해석
        3. 제어 시그널 전달
        4. 범용 산술 및 논리 연산
        5. 결과 출력

그림 - [3]: p. 56

### 중앙 처리 장치 (CPU)

레지스터의 명령어를 해석하고 산술 및 논리 연산을 수행하는 모듈

- 연산 장치
- 제어 장치
- 레지스터

### 기억 장치(Memory)

명령어와 데이터를 일시적으로 저장해두는 장소

- 주 기억 장치
- 보조 기억 장치
- 캐시 기억 장치

### 입출력 장치 (I/O Module)

명령어와 데이터를 시스템에 입출력 하기 위한 모듈

- 입력 장치
- 출력 장치
## 1.4. 컴퓨터 설계의 기본 원리

## 2.1. 정보의 표현

- **비트 (Bit)**: 0 또는 1인 2진수로 표현하는 데이터 단위
- **바이트 (Byte)**: 1바이트 당 8비트의 집합으로 표현하는 데이터 단위
- **워드 (Word)**: n바이트의 집합으로 표현하는 데이터 단위
    - Kilo(K): 2^10
    - Mega(M): 2^20
    - Giga(G): 2^30
    - Tera(T): 2^40

## 2.2. 수의 체계

### 수 체계와 진법 표기

- **수 체계**: 수를 나타내기 위해 약속한 기호와 규칙을 통틀어 말한 것
    - 복소수
        - 실수
            - 유리수
                - 정수: 양수, 0, 음수
                - 정수가 아닌 유리수: 분수, 소수
            - 무리수
        - 허수
- **10진법 (Decimal Notation)**
    - 0부터 9까지 10개의 숫자로 표현
    - 각 자리의 단위: 10^n
    - 예: 345 = 3 × 10^2 + 4 × 10^1 + 5 × 10^0
- **2진법 (Binary Notation)**
    - 0과 1로 2개의 숫자로 표현
    - 각 자리의 단위: 2^n
    - 예: 1011 = 1 × 2^3 + 0 × 2^2 + 1 × 2^1 + 1 × 2^0
- **8진법 (Octal Notation)**
    - 0부터 7까지 8개의 숫자로 표현
    - 각 자리의 단위: 8^n
    - 예: 57 = 5 × 8^1 + 7 × 8^0
- **16진법 (Hexadecimal Notation)**
    - 0부터 9까지의 숫자와 A부터 F까지의 문자로 표현
    - 각 자리의 단위: 10^n
    - 예: 1F = 1 × 16^1 + 15 × 16^0 (F는 15)

| 10진수 | 2진수 | 8진수 | 16진수 |
| --- | --- | --- | --- |
| 1 | 0000 0001 | 1 | 1 |
| 2 | 0000 0010 | 2 | 2 |
| 8 | 0000 1000 | 10 | 8 |
| 9 | 0000 1001 | 11 | 9 |
| 10 | 0000 1010 | 12 | A |
| 11 | 0000 1011 | 13 | B |

### 진법 변환

- 10진수 변환
    - 10진수 → 2진수
    - 10진수 → 8진수
    - 10진수 → 16진수
- 2진수 변환
    - 2진수 → 8진수
    - 2진수 → 16진수
- 8진수 변환
    - 8진수 → 2진수
    - 8진수 → 16진수
- 16진수 변환
    - 16진수 → 2진수
    - 16진수 → 8진수

## 2.3. 정수와 실수 표현

### 정수 표현

- 부호화-크기 표현
    - 부호 비트
    - 절대 크기
- 보수 표현
    - 보수
    - 1의 보수
    - 2의 보수
- 비트 확장
    
    데이터의 비트 수를 늘리는 연산
    
    - 부호화-크기 표현
    - 2의 보수 표현

### 실수 표현

- 소수를 포함한 2진 실수
- 정규화 표현 (IEEE 754)
- 부동 소수점 수의 표현 범위

## 2.4. 데이터 연산

### 2진수 연산

- 정수의 산술 연산
- 부동 소수점 수의 산술 연산

### 논리 연산

- 기본 논리 연산
    - AND
    - OR
    - XOR
    - NOT
- 응용 논리 연산
    - 선택적 세트
    - 선택적 보수
    - 마스크
    - 삽입
    - 비교
    - 순환 시프트
    - 산술적 시프트

# 3. 중앙처리장치

## 3.1. CPU의 구조와 구성 요소

### 프로세서 요구 사항

- **명령어 인출 (Fetch instruction)**: 프로세서는 명령어를 수행하기 위해 기억 장치로부터 명령어를 읽어와야 함
- **명령어 해석 (Interpret instruction)**: 수행해야 할 동작을 결정하기 위해 명령어를 해독해야 함
- **데이터 인출 (Fetch data)**: 명령어를 실행하기 위해 기억 장치 또는 I/O 모듈로부터 데이터를 읽어야 함
- **데이터 처리 (Process data)**: 명령어를 실행하기 위해 데이터에 대한 산술적 또는 논리적 연산을 수행할 수도 있음
- **데이터 쓰기 (Write data)**: 실행한 결과로서 데이터를 기억 장치 또는  I/O 모듈에 작성될 수도 있음

그림 - [2]: p. 434-435

### 구성 요소

- **산술 논리 연산 장치 (ALU: Arithmetic and Logic Unit):**
    - 각종 산술 연산들과 논리 연산들을 수행하는 회로들로 이루어진 하드웨어 모듈
- **제어 유닛 (CU: Control Unit):**
    - 프로그램 명령(코드)을 해석하고, 이를 실행하기 위한 제어 신호를 순차적으로 발생하는 하드웨어 모듈
    - 즉 실행에 필요한 각종 정보들의 전송 통로와 방향을 지정하고, CPU 내부 요소들과 시스템 구성 요소들의 동작 시간을 결정
- **레지스터 (Registers):**
    - CPU 내부의 임시 기억 장치
    - 기억 장치 중 접근 속도가 가장 빠름
    - 특수 목적용 레지스터와 일반 목적용 레지스터가 있음
- **CPU 내부 버스 (Internal CPU bus)**:
    - 각 요소 간 데이터 이동을 위한 선으로 구성
    - 내부 버스 선들은 반드시 버퍼 레지스터 혹은 인터페이스 회로를 통하여 시스템 버스(외부 버스)와 접속 됨

## 3.2. 명령어 사이클

### 명령어 사이클 단계

1. **인출 (Fetch)**: 기억 장치로부터 프로세서로 다음 명령어를 읽어옴
2. **간접 (Indirect)**: 명령어가 인출된 후 간접 주소 지정을 사용하는지 확인하고, 필요한 경우 참조된 포인터의 값을 읽어 실제 명령어를 인출함
3. **실행 (Execute)**: 연산 코드를 해석하고, 지정된 연산을 수행함
4. **인터럽트 (Interrupt)**: 인터럽트가 활성화된(enabled) 상태에서 인터럽트가 발생한 경우, 현재 프로세스 상태를 저장하고 인터럽트를 서비스함

### 명령어 실행 레지스터

- **프로그램 카운터 (Program Counter: PC):**
    - 다음에 인출된 명령어의 주소를 갖고 있는 레지스터
- **누산기 (Accumulator: AC):**
    - 데이터를 일시적으로 저장하는 레지스터
- **명령어 레지스터 (Instruction Register: IR):**
    - 가장 최근에 인출된 명령어가 저장되어 있는 레지스터
- **기억 장치 주소 레지스터 (Memory Address Register: MAR):**
    - 프로그램 카운터에 저장된 명령어 주소가 시스템 주소 버스로 출력되기 전에 일시적으로 저장되는 주소 레지스터
- **기억 장치 버퍼 레지스터 (Memory Buffer Register: MBR):**
    - 기억 장치에 저장될 데이터 혹은 기억 장치로부터 읽혀진 데이터가 일시적으로 저장되는 버퍼 레지스터

### 데이터 흐름

- **인출 사이클**
    1. PC 값을 읽어서 MAR로 전송: 
        
        PC → MAR
        
    2. PC 값 증가: 
        
        PC + 1 → PC
        
    3. MAR를 참조하여 기억 장치에 저장된 명령어를 읽고 IR에 저장: 
        
        Memory[MAR] → MBR (**간접 사이클**),
        
        MBR → IR
        
    4. 명령어 디코딩 준비
- **실행 사이클**
    1. 데이터 이동:
        
        CPU와 기억 장치 간 혹은 CPU와 I/O 장치 간에 데이터를 이동
        
    2. 데이터 처리:
        
        데이터에 대하여 산술 혹은 논리 연산을 수행
        
    3. 데이터 저장:
        
        연산 결과 데이터 혹은 입력 장치로부터 읽은 데이터를 기억 장치에 저장
        
    4. 프로그램 제어:
        
        프로그램의 실행 순서 결정
        
- **인터럽트 사이클**
    1. 인터럽트 감지:
        
        인터럽트 발생
        
    2. 현재 상태 저장:
        
        현재 PC의 내용을 스택에 저장 (처리 후에 복귀할 주소)
        
    3. 인터럽트 서비스 루틴 시작:
        1. 인터럽트 요청에 따라 호출
        2. 인터럽트 처리
        3. 복귀

## 3.3. 명령어 집합 구조
명령어의 종류와 수는 CPU마다 다름

### CISC (Complex Instruction Set Computer)

- **복잡한 명령어 집합**: 다양한 작업을 하나의 명령어로 처리
- **동적 길이의 명령어**: 다양한 형식의 명령어를 사용
- **하나의 명령어로 메모리 접근과 처리**까지 동시에 수행
- **목표**: 복잡한 작업을 하나의 명령어로 처리하여 효율성을 높임
- **예시: 펜티엄(Pentium) 계열 프로세서**
- 데스크톱, 서버 등 고성능 컴퓨팅 환경에 사용됨

### RISC (Reduced Instruction Set Computer)

- **단순한 명령어 집합**:  각 명령어는 하나의 작업만 수행
- **고정 길이의 명령어**: 고정된 길이의 간단한 명령어를 사용
- **하나의 명령어로 레지스터 연산**을 처리하고, 메모리 접근은 별도의 명령어로 처리.
- **목표**: 명령어 단순화로 빠른 처리 속도와 효율적인 파이프라인 처리
- **예: ARM 계열 프로세서**
- 모바일, IoT, 임베디드 시스템에서 사용됨

# 4. 메모리 구조
## 4.1. 메모리 계층 구조
그림 4-1 출처: [3], p. 86

1. 레지스터(Register)
2. 캐시(Cache)
3. 주 기억 장치(Main memory)
4. 하드디스크 및 SSD(Magnetic Disk or Solid State Disk)
5. 자기 테이프 및 광 디스크 (Tape, Optical disk)

## 4.2. 캐시 메모리
그림 4- 출처: [2], p.121

그림 4- 출처: [3], p.83

### 개요 및 원리

캐시 메모리는 상대적으로 저렴한 반도체 메모리를 사용하여 대용량의 메모리 크기를 제공하고 빠른 메모리 접근을 위해 설계된 소형의 고속 메모리

### 캐시 적중률(cache hit ratio)

CPU가 원하는 데이터가 캐시에 있을 확률

$$
H = \frac{\text{캐시에 적중되는 횟수}}{\text{전체 기억장치 접근 횟수}}

$$

**평균 기억 장치 엑세스 시간 (Ta)**

$$
Ta=H×Tc+(1-H)×Tm
$$

- **Tc**: 캐시 액세스 시간
- **Tm**: 주 기억 장치 액세스 시간
- **(1-H)**: 캐시 미스율

캐시 적중률은 프로그램과 데이터의 지역성에 크게 의존함

- **지역성(locality)**:
    
     CPU가 주 기억 장치의 특정 부분(지역)에 위치한 프로그램 코드나 데이터를 빈번히 혹은 집중적으로 액세스하는 현상
    
    - **시간적** 지역성: 최근에 액세스된 프로그램 코드(명령어)나 데이터가 가까운 미래에 다시 액세스될 가능성이 높아지는 특성
    - **공간적** 지역성: 기억 장치 내에 서로 인접하여 저장되어 있는 데이터들이 연속적으로 액세스될 가능성이 높아지는 특성
    - **순차적** 지역성: 분기(branch)가 발생하지 않는 한, 명령어들은 기억 장치에 저장된 순서대로 인출되어 실행된다는 특성

### 캐시 용량

캐시 용량이 커질 수록 적중률이 높아짐 그러나 비용도 같이 높아짐

### 인출 방식

- **요구 인출 방식(demand fetch)**: 필요한 정보만 인출
- **선인출 방식(prefetch)**: 필요한 정보 외에 앞으로 필요할 것 같은 정보를 미리 인출

### 사상 방식

어떤 주 기억 장치 블록이 어느 캐시 라인을 공유할 것인지 결정해주는 방법

그림 4- 출처: [2], p.119

그림 4- 출처: [2], p.149

- **직접 사상(direct mapping)**: 주 기억 장치 블록들이 지정된 어느 한 캐시 라인으로만 사상 하는 방식
    - 주 기억 장치 필드: 태그, 라인, 단어
    - 직접 사상 캐시의 조직
    - 예:
- **완전-연관 사상(fully-associative mapping)**: 주 기억 장치 블록이 캐시의 어떤 라인으로든 적재될 수 있는 사상 방식
    - 주 기억 장치 필드: 태그, 단어
    - 완전-연관 사상 캐시의 조직
    - 예:
- **세트-연관 사상(set-associative mapping)**: 주 기억 장치 블록이 지정된 어느 한 세트로만 적재될 수 있으며, 각 세트는 두 개 이상의 라인들로 구성된 사상 방식
    - 주 기억 장치 필드: 태그, 세트, 단어
    - 세트-연관 사상 캐시의 조직
    - 예:

### 교체 알고리즘

- **최소 최근 사용(Least Recently Used: LRU)**: 사용되지 않은 채로 가장 오래 적제된 블록을 교체하는 방식
- **FIFO(First-In First-Out)**: 캐시에 적재된 지 가장 오래된 블록을 교체하는 방식
- **최소 사용 빈도(Least Frequently Used: LFU)**: 캐시에 적재된 블록 중 사용된 빈도가 가장 낮은 블록을 교체하는 방식

## 4.3. 가상 메모리

# 5. 입출력 시스템
## 5.1. 입출력 장치와 동작 원리
## 5.2. 입출력 제어 방식
## 5.3. 인터럽트
## 5.4. I/O 버스와 데이터 전송

# 6. 프로세서 설계
## 6.1. 데이터 경로 설계
## 6.2. 제어 유닛 설계
## 6.3. 파이프라인 처리

# 7. 성능 평가와 최적화
## 7.1. 성능 측정 지표
## 7.2. 암달의 법칙
## 7.3. 시스템 성능 최적화

# Reference

[1] Computer Organization and Design, D. Patterson & J. Hennessy, Elsevier

[2] Computer organization and architecture, W. Stallings, Pearson

[3] Structured Computer Organization, Andrew S. Tanenbaum, Todd Austin, Pearson

[4] 컴퓨터 구조론 (개정5판), 김종현, 생능출판사
