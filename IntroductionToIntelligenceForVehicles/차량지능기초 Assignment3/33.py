from queue import PriorityQueue
from heapq import heappush, heappop
from collections import deque


def a_star_graph_search(start, goal_function, successor_function, heuristic):
    visited = set()
    came_from = dict()
    distance = {start: 0}
    frontier = PriorityQueue()
    frontier.add(start)
    while frontier:
        node = frontier.pop()
        if node in visited:
            continue
        if goal_function(node):
            return reconstruct_path(came_from, start, node)
        visited.add(node)
        for successor in successor_function(node):
            frontier.add(successor, priority=distance[node] + 1 + heuristic(successor))
            if successor not in distance or distance[node] + 1 < distance[successor]:
                distance[successor] = distance[node] + 1
                came_from[successor] = node
    return None


def reconstruct_path(came_from, start, end):
    reverse_path = [end]
    while end != start:
        end = came_from[end]
        reverse_path.append(end)
    return list(reversed(reverse_path))


def get_goal_function(grid):
    M = len(grid)
    N = len(grid[0])

    def is_bottom_right(cell):
        return cell == (M - 1, N - 1)

    return is_bottom_right


def get_successor_function(grid):
    def get_clear_adjacent_cells(cell):
        i, j = cell
        return (
            (i + a, j + b)
            for a in (-1, 0, 1)
            for b in (-1, 0, 1)
            if a != 0 or b != 0
            if 0 <= i + a < len(grid)
            if 0 <= j + b < len(grid[0])
            if grid[i + a][j + b] == 0
        )

    return get_clear_adjacent_cells


def get_heuristic(grid):
    M, N = len(grid), len(grid[0])
    (a, b) = goal_cell = (M - 1, N - 1)

    def get_clear_path_distance_from_goal(cell):
        (i, j) = cell
        return max(abs(a - i), abs(b - j))

    return get_clear_path_distance_from_goal


class PriorityQueue:

    def __init__(self, iterable=[]):
        self.heap = []
        for value in iterable:
            heappush(self.heap, (0, value))

    def add(self, value, priority=0):
        heappush(self.heap, (priority, value))

    def pop(self):
        priority, value = heappop(self.heap)
        return value

    def __len__(self):
        return len(self.heap)


def breadth_first_search(grid):
    N = len(grid)

    def is_clear(cell):
        return grid[cell[0]][cell[1]] == 0

    def get_neighbours(cell):
        (i, j) = cell
        return (
            (i + a, j + b)
            for a in (-1, 0, 1)
            for b in (-1, 0, 1)
            if a != 0 or b != 0
            if 0 <= i + a < N
            if 0 <= j + b < N
            if is_clear((i + a, j + b))
        )

    start = (0, 0)
    goal = (N - 1, N - 1)

    queue = deque()
    if is_clear(start):
        queue.append(start)
    visited = set()
    path_len = {start: 1}

    while queue:
        cell = queue.popleft()
        if cell in visited:
            continue
        if cell == goal:
            return path_len[cell]
        visited.add(cell)
        for neighbour in get_neighbours(cell):
            if neighbour not in path_len:
                path_len[neighbour] = path_len[cell] + 1
            queue.append(neighbour)

    return -1


def Astar(grid):
    if grid[0][0] == 1:
        return -1
    answer = a_star_graph_search(
        start=(0, 0),
        goal_function=get_goal_function(grid),
        successor_function=get_successor_function(grid),
        heuristic=get_heuristic(grid)
    )
    if len(answer):
        return len(answer)
    else:
        return -1


grid1 = [[0, 0, 0], [1, 1, 0], [1, 1, 0]]
answer1 = Astar(grid1)
print("correct test case 1") if answer1 == 4 else print("incorrect test case 1")

grid2 = [[1, 0, 0], [1, 1, 0], [1, 1, 0]]
answer2 = Astar(grid2)
print("correct test case 2") if answer2 == -1 else print("incorrect test case 2")
