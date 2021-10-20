#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void updateTime(int &hour, int &min, bool up)
    {
        if(min%15 == 0)
        {
            return;
        }
        
        if(min > 0 & min < 15)
        {
            if(up)
            {
                min = 15;
            }
            else
            {
                min = 0;
            }
        }
        else if(min > 15 & min < 30)
        {
            if(up)
            {
                min = 30;
            }
            else
            {
                min = 15;
            }
        }
        else if(min > 30 & min < 45)
        {
            if(up)
            {
                min = 45;
            }
            else
            {
                min = 30;
            }
        }
        else
        {
            if(up)
            {
                min = 0;
                hour += 1;
            }
            else
            {
                min = 45;
            }
        }
        
        return;
    }
    
    int findRounds(int starthour, int startmin, int endhour, int endmin)
    {
        int ans = 0;
        if(starthour == endhour)
        {
            return (endmin-startmin)/15;
        }
        
        if(startmin != 0)
        {
            ans += (60-startmin)/15;
            starthour+=1;
        }
        
        if(endmin != 0)
        {
            ans += endmin/15;
            // endhour-=1;
        }
        
        // cout << ans << " " << endhour << " " << starthour << endl;
        ans += (endhour-starthour)*4;
        cout << ans << endl;
        return ans;
    }
    
    int numberOfRounds(string startTime, string finishTime) {
        int starthour = stoi(startTime.substr(0, 2));
        int startmin = stoi(startTime.substr(3,2));
        int endhour = stoi(finishTime.substr(0,2));
        int endmin = stoi(finishTime.substr(3,2));
        if(starthour == endhour && startTime < finishTime)
        {
            if(startmin > 0 && startmin < 15 && endmin > 0 && endmin < 15)
            {
                return 0;
            }
            else if(startmin > 15 && startmin < 30 && endmin > 15 && endmin < 30)
            {
                return 0;
            }
            else if(startmin > 30 && startmin < 45 && endmin > 30 && endmin < 45)
            {
                return 0;
            }
            else if(startmin > 45 && endmin > 45)
            {
                return 0;
            }
        }
        
        updateTime(starthour, startmin, true);
        updateTime(endhour, endmin, false);
        // cout << starthour << " " << startmin << " " << endhour << " " << endmin << endl;
        if(startTime > finishTime)
        {
            return findRounds(starthour, startmin, 24, 0) + findRounds(0, 0, endhour, endmin);
        }
        
        return findRounds(starthour, startmin, endhour, endmin);
    }
};