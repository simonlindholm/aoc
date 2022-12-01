import sys

# https://www.geeksforgeeks.org/maximum-bipartite-matching/
class GFG:
    def __init__(self,graph):

        # residual graph
        self.graph = graph
        self.ppl = len(graph)
        self.jobs = len(graph[0])

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

alling = []
eds = {}
for line in sys.stdin:
    line = line.strip()
    aller = None
    if "contains" in line:
        line,b = line.split("(contains")
        aller = b[:-1].strip().split(", ")
    ing = line.split()
    if aller:
        for a in aller:
            if a not in eds:
                eds[a] = set(ing)
            else:
                eds[a] &= set(ing)
    alling.append(ing)

ingtoi = {}
itoing = {}
index = 0
for a in eds:
    for ing in eds[a]:
        if ing not in ingtoi:
            ingtoi[ing] = index
            itoing[index] = ing
            index += 1

part1 = 0
for x in alling:
    for ing in x:
        if ing not in ingtoi:
            part1 += 1
print(part1)

assert index == len(eds)

gr = [[False] * index for _ in range(index)]
atoi = {}
for i, a in enumerate(eds):
    atoi[a] = i
    for ing in eds[a]:
        gr[ingtoi[ing]][i] = True
matches = GFG(gr).maxBPM()

print(",".join(itoing[matches[atoi[a]]] for a in sorted(a for a in eds)))
