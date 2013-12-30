/*
 * Simplify Unix Style Path
 * 
 * Problem: the most important understanding is that all path always start with '/'
      1. This significantly reduce the complexity: 
         1.1 reduces edge conditions such as   ../ ./.. a/../..
         1.2 enables streamlined ".." && "." handling as now we can always just pop the previous dir
             of it is empty, returns the root directory
             nasty conditions like    ../ and ../.. is no longer in the equation
      -- In practice, this also make sense, as we can always add $pwd to the current path
   Algorithm: 
      1. house cleanninng by removing "//" before hand to reduce a few edge conditions 
      2. ignore all "/.", pop previous if stack is not empty for "/.." and push everything else
   Gain: 
      1. Conditionign is absolutly killing, both time and your brain and your morale. 
      2. To improve
          2.1 reduce the amount of time on condition on a particular problem
              - It might sounds anti-productive, but 
                spending too much time on conditioning one problem is 
                the biggest waste of time, energy, brain, morale, momentem 
              - it might even kills your IQ since you kills so many brain cells in one shot. 
              - another biggest concern is it kills confidence, you absolutely want to avoid that 
                It create an illusion of incapablity consciously or unconsciously. 
              - Majority of time, you also find that it is not you that the problem but
                it is the problem you are trying to solve is the problem.
                  * Either the question is vague
                  * The context is not clear
                  * the requirement is unclear. 
                  * the boundary conditions is not clearly defined
           2.2 Given an antiproductive thing to over-spend on conditioning one problem, 
               if you find yourself tricked into one of these unfortunate situations, 
               GET OUT! GET OUT IMMEDIATELY and GET OUT FAST!
           2.3 WHen you are out of the miseries, you can now do some rational things: 
               2.3.1 Read online discussion to really understand the problem and clear all edge conditions
               2.3.2 Read online proposals to see where you are lacking
               2.3.3 After that, follow one good example by typing it into your text box and find it out
                      - good here means: 
                          least bondary discussion 
                          non-convoluting logics 
                          well documented code
                          well written (a.k.a easy to follow which means easy to chew up) 
         
 *
 *
 *
 */


// http://yucoding.blogspot.com/2013/04/leetcode-question-98-simplify-path.html

// work backwards , not good, need to handle the nasty ../../ condition 




class Solution {
public: 
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function 
        
        // Remove double "//"
        int i = 0; 
        while(i<path.size()-1) {
            if(path[i] == '/' && path[i+1]=='/'){
                path.erase(i, 1); // ::erase(i) will work? 
            }else{ i++;}
        }
        // Add a '/' in the end. 
        if(path[path.size()-1]!= '/'){path+="/";}
        
        //main loop
        stack<string> dirs;
        string str="";
        int flag =0; // number of '/' handling
        for(int i = 0; i<path.size(); i++){
            if(path[i]=='/'){flag++;}
            if(flag==1){ str+=path[i];} 
            if(flag==2){
                if(str=="/.." && !dirs.empty()){
                    dirs.pop();
                }
                if(str!="/." && str!="/.."){
                    dirs.push(str);
                }
                flag=1; 
                str="/";
            }
        }
        
        //Prepare return str
        if(dirs.empty()){return "/";}
        str="";
        while(!dirs.empty()){
            str=dirs.top()+str;
            dirs.pop();
        }
        return str; 
    }
};
