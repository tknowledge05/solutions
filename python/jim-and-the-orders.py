#https://www.hackerrank.com/challenges/jim-and-the-orders?h_r=next-challenge&h_v=zen

import Queue

class Job(object):
    def __init__(self, priority, description):
        self.priority = priority
        self.description = description
        #print 'New job:', description
        return
    def __cmp__(self, other):
        #return cmp(self.priority, other.priority)
        return self.priority > other.priority

q = Queue.PriorityQueue()

n = int(raw_input())
for i in range(n):
    val = map(int, raw_input().strip().split())
    
    q.put(Job(val[0] + val[1], i+1))


while not q.empty():
    next_job = q.get()
    print str(next_job.description),


