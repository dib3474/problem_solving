from collections import deque 

T = int(input())  # 테스트 케이스 

for _ in range(T):
    
    p = list(input().rstrip())  # 수행할 함수 (R : 배열의 순서 뒤집기 / D : 배열에서 첫 번째 수 버리기)
    n = int(input())   # 배열에 들어있는 수의 개수
    q = deque()
    arr = input().rstrip()  # n개의 원소를 가진 배열을 q에 저장
    if n > 0:
        for i in arr[1:-1].split(","):
            q.append(i)
    
    error = False  # 에러 발생여부
    R_cnt = 0  # R이 나온 횟수
    
    for j in p:
        if j == "R":
            R_cnt += 1
        elif j == "D" and len(q) == 0:
            error = True
            break 
        else:
            if R_cnt % 2 == 0:
                q.popleft()
            else:
                q.pop() 

    if R_cnt % 2 == 1:
        q.reverse() 
    
    if error == True: 
        print("error") 
    else:
        print("[" + ",".join(list(q)) + "]")