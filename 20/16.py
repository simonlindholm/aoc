import sys

vals = []
names = []
your = None
other = []


# https://www.geeksforgeeks.org/maximum-bipartite-matching/
class GFG:
    def __init__(self,graph):

        # residual graph
        self.graph = graph
        self.ppl = len(graph)
        self.jobs = len(graph[0])
        assert self.ppl == self.jobs

    # A DFS based recursive function
    # that returns true if a matching
    # for vertex u is possible
    def bpm(self, u, matchR, seen):

        # Try every job one by one
        for v in range(self.jobs):

            # If applicant u is interested
            # in job v and v is not seen
            if self.graph[u][v] and seen[v] == False:

                # Mark v as visited
                seen[v] = True

                '''If job 'v' is not assigned to
                   an applicant OR previously assigned
                   applicant for job v (which is matchR[v])
                   has an alternate job available.
                   Since v is marked as visited in the
                   above line, matchR[v]  in the following
                   recursive call will not get job 'v' again'''
                if matchR[v] == -1 or self.bpm(matchR[v],
                                               matchR, seen):
                    matchR[v] = u
                    return True
        return False

    # Returns maximum number of matching
    def maxBPM(self):
        '''An array to keep track of the
           applicants assigned to jobs.
           The value of matchR[i] is the
           applicant number assigned to job i,
           the value -1 indicates nobody is assigned.'''
        matchR = [-1] * self.jobs

        # Count of jobs assigned to applicants
        result = 0
        for i in range(self.ppl):

            # Mark all jobs as not seen for next applicant.
            seen = [False] * self.jobs

            # Find if the applicant 'u' can get a job
            if self.bpm(i, matchR, seen):
                result += 1
        return matchR

pa = 0
for line in sys.stdin:
    line = line.strip()
    if not line:
        pa += 1
    elif pa == 0:
        a,b = line.split(": ")
        vals.append(list(list(map(int, x.split('-'))) for x in b.split(" or ")))
        names.append(a)
    elif pa == 1:
        if not line.startswith("your ticket"):
            your = list(map(int, line.split(",")))
    elif pa == 2:
        if not line.startswith("nearby ticket"):
            other.append(list(map(int, line.split(","))))

n = len(vals)
ed = [[True] * n for _ in range(n)]
part1 = 0
for o in other + [your]:
    fail = False
    assert len(o) == n
    for y in o:
        if not any(a <= y <= b for sub in vals for a,b in sub):
            part1 += y
            fail = True
    if fail:
        continue
    for i,y in enumerate(o):
        for j,l in enumerate(vals):
            if not any(a <= y <= b for a,b in l):
                ed[i][j] = False
# print(ed)
print(part1)

matches = GFG(ed).maxBPM()
# print(matches)
res = 1
for i,j in enumerate(matches):
    if names[i].startswith("departure"):
        res *= your[j]
    # print(names[i], j)
print(res)
