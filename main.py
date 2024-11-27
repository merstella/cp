def bpm(graph, u, matchR, seen):
        for v in graph[u]:
if not seen[v]:
seen[v] = True
if matchR[v] == -1 or bpm(graph, v, matchR, seen):  # Sửa lỗi: `v` thay cho `u`
matchR[v] = u
return True
return False

def maxBPM(graph):
num_jobs = len(graph[0])
matchR = [-1] * num_jobs
result = 0
for i in range(len(graph)):
seen = [False] * num_jobs
if bpm(graph, i, matchR, seen):
result += 1
return result

# Biểu diễn đồ thị hai phía
graph = [
[3],
[0, 4],
[3],
[1, 2],
[0, 4]
]

print("Số lượng công việc tối đa có thể phân công:", maxBPM(graph))