# test.json
#{"board": {
#    "0": { 
#        "0": "X",
#        "1": "",
#        "2": "X"
#    },
#    "1": { 
#        "0": "",
#        "1": "",
#        "2": ""
#    },
#	"2": { 
#        "0": "X",
#        "1": "",
#        "2": "X"
#    }
#}} 

from sys import argv
import json

def bfs(boardlist, visited, x, y, m, n):
	dz = zip([1, 0, -1, 0], [0, 1, 0, -1])
	if boardlist[x][y] == 1:
		return True
	queue = [(x, y)]
	visited[x][y] = True
	while queue:
		curr = queue.pop(0)
		boardlist[curr[0]][curr[1]] = 2
		for d in dz:
			nxt = (curr[0] + d[0], curr[1] + d[1])
			if inbound(nxt, m, n) and boardlist[nxt[0]][nxt[1]] == 0 and not visited[nxt[0]][nxt[1]]:
				visited[nxt[0]][nxt[1]] = True
				queue.append(nxt)
	return False

def inbound(nxt, m, n):
	return nxt[0] >= 0 and nxt[0] < m and nxt[1] >= 0 and nxt[1] < n

script, inputx, inputy = argv

fn = "board.json"
file = open(fn)
js = json.load(file)

board = js['board']
m, n = len(board), len(board['0'])
boardlist = [ [0 for y in range(n) ] for x in range(m)]
visited = [ [False for y in range(n) ] for x in range(m)]
for i in range(m):
	for j in range(n):
		if board[str(i)][str(j)] == 'X':
			boardlist[i][j] = 1
	
boom = bfs(boardlist, visited, int(inputx), int(inputy), m, n)

if boom == True:
	print("Boom!!!")
else:
	print("Sweep:")
	print(boardlist)
