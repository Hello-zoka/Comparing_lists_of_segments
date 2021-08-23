Hey, my name is Yurij Zajcev, I'm from Saint-Petersburg. 

First, I want to apologize for my terrible English, but I need to practice somewhere ;)
You can find here ny solution of problem: "We have two sets of segments(with ends in integer coordinates). It must be said whether the sets of points covered by the line segments are identical or not"

In Main fuction you can find place to insert name of input file. 

Format of input file is:
First line contains one ineger n - number of segments in first set
Then n lines with 4 inegers in each of them: x1 y1 x2 y2 - coordinates of current segment's ends
Next line contains one ineger m - number of segments in second set
Then m lines with 4 inegers in each of them: x1 y1 x2 y2 - coordinates of current segment's ends
(example of input file you alse can find in repository)

My solution can be described by the following plan:
1) Reading Input, using function ReadListOfSegments()
2) Normalizing (merging of crossing segments) segments using function Normalize(list of segments):
  a)  Trying to merge some segments as long as possible ("greedy" solve of course can be used here), using function Relaxing(), which returns true, if some segmets were merged:
    aa) Iterate over a couple of segments and checking if we can merge them, using function NeedMerging, which checks if two segments are lying on one line and crossing.
3) Comparing two lists of segments, using Compare function

This solution is not very fast ;( 
Asymptotics of second stage is O(n^3), but we can solve it by O(n*logn), using sorting segments by tan and solving standart problem of minimum covering segmets for each tan by O(n)
Asymptotics of thirs stage is O(n^2), but we can solve it by O(n*logn), using sorting of list of segmetns

BUT I have no time for these not easy optimizations
Also we can add supporting of float coordinates

