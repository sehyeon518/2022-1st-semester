import heapq


def solution(N, K, road):
    def dijkstra(dlist, glist):
        heap = []
        heapq.heappush(heap, [0, 1])  # 0만큼 떨어진 1에 갈 수 있다 (leng, dest)
        while heap:
            print("heap:", heap)
            step1 = heapq.heappop(heap)
            leng, dest = step1                # leng = a->b
            print("cost:", leng, "node:", dest)
            step2 = glist[dest]
            for l, d in step2:                # l = b->c
                print("[ l , d ]: [", l, ",", d, "]")
                length = leng + l             # c까지 거리 = (a->b) + (b->c)
                if length < dlist[d]:
                    dlist[d] = length
                    heapq.heappush(heap, [length, d])

    distance = [float('inf')] * (N + 1)  # 양의 무한대 값 node 개수 + 1행 >> 그 지점까지 최단 거리
    distance[1] = 0
    graph = [[] for _ in range(N + 1)]
    for r in road:
        graph[r[0]].append([r[2], r[1]])
        graph[r[1]].append([r[2], r[0]])
    dijkstra(distance, graph)
    return len([x for x in distance if x <= K])


# 1번 테스트
N1 = 5                                                                      # 점 개수
K1 = 3
road1 = [[1, 2, 1], [2, 3, 3], [5, 2, 2], [1, 4, 2], [5, 3, 1], [5, 4, 2]]  # a와 b 사이의 시간 c
answer1 = solution(N1, K1, road1)
print("correct test case 1") if answer1 == 4 else print("incorrect test case 1")

# 2번 테스트
N2 = 6
K2 = 4
road2 = [[1, 2, 1], [1, 3, 2], [2, 3, 2], [3, 4, 3], [3, 5, 2], [3, 5, 3], [5, 6, 1]]
answer2 = solution(N2, K2, road2)
print("correct test case 2") if answer2 == 4 else print("incorrect test case 2")
