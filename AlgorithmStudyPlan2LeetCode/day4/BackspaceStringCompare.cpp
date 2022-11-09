class Solution {
public:
    bool backspaceCompare(string s, string t) {
        s = " " + s;
        t = " " + t;
        int s_ptr = s.size()-1, t_ptr = t.size()-1;
        while(s_ptr >= 0 && t_ptr >= 0)
        {
            int counter = 0;
            while(s[s_ptr] == '#' || counter>0)
            {
                if(s_ptr == 0)
                    break;
                if(s[s_ptr] == '#')
                {
                    counter++;
                    s_ptr--;
                }
                else
                {
                    if(counter > 0)
                    {
                        s_ptr--;
                        counter--;
                    }
                }
            }
            counter = 0;
            while(t[t_ptr] == '#' || counter>0)
            {
                if(t_ptr == 0)
                    break;
                if(t[t_ptr] == '#')
                {    
                    counter++;
                    t_ptr--;
                }
                else
                {
                    if(counter > 0)
                    {
                        t_ptr--;
                        counter--;
                    }
                }
            }
            if(s[s_ptr] != t[t_ptr])
                return false;
            else
            {
                s_ptr--;
                t_ptr--;
            }            
        }
        return s_ptr < 0 && t_ptr < 0;
    }
};