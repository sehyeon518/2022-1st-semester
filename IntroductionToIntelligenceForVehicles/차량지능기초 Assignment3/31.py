from collections import deque

def solution(maps):

    n = len(maps[0])  # 가로 길이
    m = len(maps)     # 세로 길이

    answer = 1

    queue = deque()
    queue.append(0)
    visited = [0]

    while len(queue) > 0:
        cdnt = queue.popleft()

        pointerX = cdnt // 10
        pointerY = cdnt % 10

        # 상대편에 도달하면 종료
        if pointerX == m - 1 and pointerY == n - 1:
            return answer

        # 상하좌우 살펴보기
        if pointerX > 0:
            if maps[pointerX - 1][pointerY] == 1 and (cdnt-10 not in visited):
                queue.append(cdnt-10)
                visited.append(cdnt-10)
        if pointerX < m-1:
            if maps[pointerX + 1][pointerY] == 1 and (cdnt+10 not in visited):
                queue.append(cdnt+10)
                visited.append(cdnt+10)
        if pointerY > 0:
            if maps[pointerX][pointerY - 1] == 1 and (cdnt-1 not in visited):
                queue.append(cdnt-1)
                visited.append(cdnt-1)
        if pointerY < n-1:
            if maps[pointerX][pointerY + 1] == 1 and (cdnt+1 not in visited):
                queue.append(cdnt+1)
                visited.append(cdnt+1)
        print("queue:", queue)
        print("visit:", visited)
        answer += 1

    return -1  # 지나가야하는 칸의 개수의 최솟값 or -1


# 1번 테스트
map1 = [[1, 0, 1, 1, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 1], [1, 1, 1, 0, 1], [0, 0, 0, 0, 1]]
answers = solution(map1)

if answers == 11:
    print("correct test case 1")
else:
    print("incorrect test case 1", answers)

# 2번 테스트
map2 = [[1, 0, 1, 1, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 1], [1, 1, 1, 0, 0], [0, 0, 0, 0, 1]]
answers = solution(map2)
if answers == -1:
    print("correct test case 2")
else:
    print("incorrect test case 2")
