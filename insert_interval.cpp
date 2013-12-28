/*
 * Insert Intervals
 * 
 * Headline: 
 *   An Epic Battle Won, You deserve a pat on the back and more :) 
 *   But don't let the win confuse you, instead carry on with the joyful spirit and healthy momentum,  
 *   And Win more battles!
 * Algorithm: 
 *   The algorithm is actually straightforward espcially given the intervals are sorted
 * Gotcha: 
     -Don't let the simple algorithm fool you, the boundary conditions can kill you too
     -I started on the wrong path of conditioning on everything   : never do this again
     -Conditioning eats time away so fast and kill your brain equally as fast. 
     -Don't open the pandora unless you have to. 
     -Think out of box and draw a pen to see if you can simplify conditioning b4 actually do the conditioning
 * Gain: 
     1. How to simplify conditions
        1.1 MIND PAPER SKELETON: Rule of Thumb: Think, track, draw and write down draft algorithm b4 you code
        1.2 DUMMY: If bondary conditions are annoying, check if dummy node would help
           . e.g.    dummy node for linked list, 
                     dummy node at the start/end of an array, 
                     dummy node to fill in irregular places
        1.3 ONE AT A TIME: if two many varibles needs to be conditioned, check if you can consider them one by one
            * N^2:  remember that number of conditions grow exponentially with number of concerning variables 
            * e.g.  check newInterval.start and newInterval.end separately 
      2. How to keep your sanity in nasty conditionings 
        2.1 MIND: Rule of Thumb: think, track, draw, write down draft algorithm again and try to simplify
        2.2 PAPER: write down all conditions clearly on paper first before coding 
            . why this works? b/c when writing draft you don't need to consider grammar and many other gritty nitty details
              this enables you to focus and purely focus on the real conditioning
            . Beautifully, divide and conque in real life situations
        2.3 SKELETON: When coding, start with a commented valid skelonton reflecting your draft on paper
            . why this works? Again divide and conquer
            . Write down the working skeleton reduce the workload on grammar
            * Write down the commented skeleton projected from your draft, 
              offload the burdon of keeping track of all the conditions all the time
            * Write down the commented skeleton is good reminder and 
                 may reveal potential bugs at the begining
                 will definitely help debugging/review after coding done
        2.4 Helper: Helper function, helper landmarks
            * don't over do this though, only the absolutely nesessary ones
            
 *
 *      
 */
 


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
#define PMAX  0x7fffffff
#define PMIN  -1
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
      int left, right; // record which interval does '[' ,  ']' falls in  
      bool left_clear, right_clear; // record if '[', ']' is in or btw existing intervals
      int i, j; // numerical iterators
   
      if(intervals.size() == 0)
      {
          intervals.push_back(newInterval);
          return intervals; 
      }
      
      Interval dummy(PMAX, PMAX);
      intervals.push_back(dummy);
      //Interval dummy(PMIN, PMIN);  // this is so wrong, why? called ctor twice, declared dummy twice
      dummy.start = PMIN; dummy.end = PMIN; 
      intervals.insert(intervals.begin(), dummy);
      for(i = 0; i<intervals.size(); i++)
      {
          // charaterize "newInterval.start"
          if(intervals[i].start <= newInterval.start && newInterval.start <= intervals[i].end)
          {
              left = i;
              left_clear = false; 
          }
          if(intervals[i].end < newInterval.start && newInterval.start < intervals[i+1].start)
          {
              left = i; 
              left_clear = true; 
          }
          
          // characterize "newInterval.end"
          if(intervals[i].start <= newInterval.end && newInterval.end <= intervals[i].end)
          {
              right = i;
              right_clear = false; 
          }
          if(intervals[i].end < newInterval.end && newInterval.end < intervals[i+1].start)
          {
              right = i; 
              right_clear = true; 
          }
      }
      
      std::vector<Interval>::iterator iter = intervals.begin();
      // erase from left+1 to right, 
      if(left_clear && right_clear) {
         intervals.erase(iter + left + 1, iter + right + 1) ;
         intervals.insert(iter + left +1, newInterval);
         //return intervals; 
      } 
      // erase from left+1 to right
      if(!left_clear && !right_clear) {
          intervals[left].end = intervals[right].end;
          intervals.erase(iter + left + 1, iter + right + 1);
          //return intervals; 
      }
      // erase from left+1 to right
      if(left_clear && !right_clear) {
          newInterval.end = intervals[right].end;
          intervals.erase(iter+left+1, iter+right+1); 
          intervals.insert(iter + left + 1, newInterval); 
          //return intervals; 
      }
      // erase from left to right
      if(!left_clear && right_clear) {
          intervals[left].end = newInterval.end;
          intervals.erase(iter+left+1, iter+right+1);
          //return intervals;
      }
      
      intervals.erase(intervals.begin()); // remove head dummy
      intervals.erase(intervals.end() - 1); // remove last dummy
      return intervals; 
    }
};
