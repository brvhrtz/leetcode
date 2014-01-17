/* 
 *   Again a very simple programming problem. However, this is a very good example to
     showcase handling of open-ended issues. Yes! the while(1) loop 
     
     Gain: 
     1.  if you found open ended issue, use while(1)
     2. if you found your condition at the begining of loop is not able to handle all cases, 
        it probably means you have to make condition on the same condition in the middle
     
     Follow-up: 
     I believe this kind of simple but tricky issues are critical to pass the phone screening, 
     need to bomb them collectively multiple times. 
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // have a index recoding last seen space, the first is -1
        // push until reach the end of string
        int l; // left 
        int r; // right
        int res=0; 
        
        if(s == NULL) return res; 
        l = 0;r = 0; 
        while(1){
            if(*(s+r) == '\0') return res;
            
            while(*(s+r)==' ') r++; // skip all spaces
            if(*(s+r)=='\0')  return res; // xxx________'\0'
            
            l = r; // first non space
            while(*(s+r)!='\0' && *(s+r)!=' '){
               r++; // move until r point to nx space or '\0'
            }
            res = r-l;
        }
    }
};
