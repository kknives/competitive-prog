from pprint import pprint
import io,os,sys
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
n,k = list(map(int, input().split()))
# unfamiliarity = [[] for _ in range(n+1)]
# unfamiliarity[0] = [0]*(n+1)
pre = [[] for _ in range(n+1)]
pre[0] = [0]*(n+1)
for i in range(1,n+1):
    alist = list(map(int, input().split()))
    pre[i] = [0 for _ in range(n+1)]
    for j, a in zip(range(1, n+1), alist):
        pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a
    # unfamiliarity[i] = [0]+list(map(int, input().split()))
# pre = [[] for _ in range(n+1)]
# for i in range(2, n+1):
#     for j in range(i+1, n+1):
#         pre[i][j] = unfamiliarity[i][j] + pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1]
# pprint(pre, width=(n+1)*4)
def cost(begin, end):
    # for i in range(begin, end+1):
    #     for j in range(i, end+1):
    s=(pre[end][end]-pre[begin-1][end]-pre[end][begin-1]+pre[begin-1][begin-1])
    # return sum([unfamiliarity[i][j] for i in range(begin, end+1) for j in range(i, end+1)])
    return s>>1
minufrd = [[] for _ in range(k+1)]
minufrd[0] = [0]*(n+1)
minufrd[1] = [0]+[cost(i,n) for i in range(1,n+1)]

def compute(d,l,r,optl,optr):
    if l > r: return
    mid = (l+r)>>1
    best = (sys.maxsize, -1)
    for i in range(max(mid,optl), optr+1):
        best = min(best, (minufrd[d-1][i]+cost(mid,i-1), i))
    minufrd[d][mid] = best[0]
    opt = best[1]
    compute(d,l,mid-1,optl,opt)
    compute(d,mid+1,r,opt,optr)
for i in range(2,k+1):
    minufrd[i] = [0 for _ in range(n+1)]
    compute(i,1,n-1,1,n)
    # for j in range(1, n):
    #     cand = sys.maxsize
    #     for a in range(j+1, n+1):
    #         cand = min(cand, cost(j,a-1) + minufrd[i-1][a])
    #     minufrd[i][j] = cand
    #     # minufrd[i][j] = min([cost(j,a-1) + minufrd[i-1][a] for a in range(j+1,n+1)])
    # minufrd[i][n] = 0
# pprint(minufrd,width=(n+1)*4)
print(minufrd[k][1])

