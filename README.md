# AddressBook

### 기능

1. 이름, 전화번호 저장 기능 (명령어 : add)
    - 중복된 이름은 저장 가능하지만 중복된 전화번호는 저장 불가능함.
    - 이름에는 특수문자 등 모든 글자 허용, 64글자 허용
    - 전화번호에는 정수만 허용 ( 예 : 12341234 ), 8글자 허용
2. 즐겨 찾기 기능 (명령어 : mark)
    - 중복된 이름으로 즐찾 등록시 해당 이름, 전화번호 모두 출력 후 ‘mark 전화번호’로 등록 유도
3. 검색 기능 
    - 이름과 전화번호로 둘다 검색할수 있어야함.
    - 이름과 전화번호로 검색했을때 이름과 전화번호가 모두 나와야됨.
    - 중복된 이름을 검색했을 시에도 이름과 전화번호 모두 출력돼야됨.
4. 삭제 기능
    - 중복된 이름으로 삭제시 해당 이름과 전화번호 출력 후 ‘rm 전화번호’ 로 삭제유도
5. 명령어
    - 저장 → add 이름:전화번호
    - 즐겨찾기 → mark 이름:전화번호
    - 즐겨찾기 목록(ㄱㄴㄷ순) → cmark
    - 모든 목록(ㄱㄴㄷ순) → c
    - 검색 → find 이름 / find 전화번호
    - 삭제 → rm 이름 / rm 전화번호

### 자료구조

- 이중 연결리스트
- 이진트리
- 각각 구현 후 성능비교

### 성능 측정

- 10만개의 데이터를 넣어본 뒤 검색 시간 측정

### 목표

- 아직 시간에 대한 목표는 확립하지 못했음. 최대한 최적화를 하여 성능 측정 후 목표 결정해야됨.
