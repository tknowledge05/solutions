# https://www.hackerrank.com/challenges/connected-cell-in-a-grid

import Queue

n = int(raw_input())
m = int(raw_input())
arr = []
#vis = [[0]*m]*n

vis = [[0 for x in range(m)] for y in range(n)] 
max_lent = 0
for x in range(n):
	val = map(int, raw_input().strip().split())
	arr.append(val)


def is_valid_move(x, y):
	return True if (x>=0 and y>=0 and x<n and y<m) else False

def bfs(cur_sx, cur_sy):
	global max_lent 
	xa = [-1, -1, 0, 1, 1, 1, 0, -1]
	ya = [0, 1, 1, 1, 0, -1, -1, -1]
	q = Queue.Queue()
	q.put([cur_sx, cur_sy])
	vis[cur_sx][cur_sy] = 1
	cur_len = 0
	while not q.empty():
		curr = q.get()
		cur_x = curr[0]
		cur_y = curr[1]
		cur_len += 1
		for x in xa:
			for y in ya:
				if is_valid_move(cur_x + x, cur_y + y):
					if ((arr[cur_x + x][cur_y + y]) and  (not vis[cur_x + x][cur_y + y])):
						vis[cur_x + x][cur_y + y] = 1
						q.put([cur_x + x,cur_y + y])

	max_lent = max(max_lent, cur_len)

def process():
	for x in range(n):
		for y in range(m):
			if(arr[x][y] and not vis[x][y]):
				bfs(x, y)
			# else:
			# 	vis[x][y] = 1
	#print "#######################"
	print max_lent

process()
				



