# push_swap
이 프로젝트는 가능한 최소한의 작업을 사용하여 제한된 명령어 세트로 스택에서 데이터를 정렬하도록 합니다. 성공하려면 다양한 유형의 알고리즘을 조작하고 최적화 된 데이터 정렬에 가장 적합한 솔루선을 선택해야 합니다.

### 과제 소개
<img width="655" alt="image" src="https://github.com/2021110806/push_swap/assets/104808812/801fbcf0-4b24-42db-844d-1652473f71e2">

사용자가 입력한 무작위 숫자 배열을 특정 명령어와 스택 두 개만을 이용하여 재정렬 하는 문제이다.

#### 사용할 수 있는 명령어
#### ra / rb

<img width="598" alt="image" src="https://github.com/2021110806/push_swap/assets/104808812/a55ed10a-5154-4201-aaac-36987f109185">

스택을 정방향으로 한 바퀴 회전 시키는 명령어이다. ra의 경우에는 stackA, rb의 경우에는 stackB를 회전시킨다.

#### rra / rrb

<img width="601" alt="image" src="https://github.com/2021110806/push_swap/assets/104808812/042aa86f-7443-4680-9638-2bd92aa34063">

스택을 역방향으로 한 바퀴 회전 시키는 명령어이다. rra의 경우에는 stackA, rrb의 경우에는 stackB를 회전시킨다.

#### pa / pb

<img width="926" alt="image" src="https://github.com/2021110806/push_swap/assets/104808812/11653ed6-b424-4915-ada9-5686805831e6">

한 스택에서 다른 스택으로 원소를 하나 옮기는 명령어이다. 스택의 특성에 따라 가장 마지막(후입)에 있던 원소부터 빠져나가며, pa의 경우엔 stackB에서 stackA로 원소가 이동하고, pb의 경우엔 stackA에서 stackB로 원소가 이동한다.

### 구현 과정
#### 스택 구현하기

#### 명령어 구현하기
#### 그리디 알고리즘을 통해 stackA에서 stackB로 정렬시키기
