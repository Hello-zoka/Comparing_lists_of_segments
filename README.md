_**Hello! My name is Yurij Zajcev, I'm from Saint-Petersburg, Russia.**_ 

First of all, I want to apologize for my terrible English, but I need to practice somewhere ;)

You can find here my solution of problem: **"We have two sets of segments(with ends in integer coordinates). It must be said whether the sets of points covered by the line segments are identical or not"**

In Main function you can find place to insert name of input file. 

_**Format of input file is**:_

1) First line contains one integer `N`- number of segments in first set.
2) Then `N` lines with 4 integers in each of them: `x1`, `y1`, `x2`, `y2` - coordinates of current segment's ends.
3) Next line contains one integer `M` - number of segments in second set.
4) Then `M` lines with 4 integers in each of them: `x1`, `y1`, `x2`, `y2` - coordinates of current segment's ends.
   
(Example of input file you also can find in repository)

**_My solution can be described by the following plan:_**
1) Reading Input, using function ReadListOfSegments()
2) Normalizing (merging of crossing segments) segments using function Normalize(list of segments):
   1) Trying to merge some segments as long as possible ("greedy" solve of course can be used here), using function Relaxing(), which returns true, if some segments were merged:
   2) Iterate over a couple of segments and checking if we can merge them, using function NeedMerging, which checks if two segments are lying on one line and crossing.
3) Comparing two lists of segments, using Compare function

This solution is not very fast ;(

**_TODO:_**
Asymptotics of second stage is O(`N ^ 3`), but we can solve it by O(`NlogN`), using sorting segments by tangent and solving standard problem of minimum covering segments for each tangent by O(`N`).

Asymptotics of third stage is O(`N ^ 2`), but we can solve it by O(`NlogN`), using sorting of list of segments.

