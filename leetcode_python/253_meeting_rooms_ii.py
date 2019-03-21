# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

# Before anything, sort the meeting room intervals based on start time.
# Idea is to use min-heap to store ending times of meetings and if a meeting room can be 
# freed for next meeting to be scheduled, Free it. Else, push the new room's end time to min-heap
class Solution(object):
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        if not intervals:
            return 0
        intervals.sort(key=lambda x:x.start)
        f = []
        heapq.heappush(f,intervals[0].end)
        for i in intervals[1:]:
            if f[0] <= i.start:
                heapq.heappop(f)
            heapq.heappush(f,i.end)
        return len(f)
