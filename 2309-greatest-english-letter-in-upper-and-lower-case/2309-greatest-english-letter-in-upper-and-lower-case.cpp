class Solution {
public:
    string greatestLetter(string s) 
    {
        // declare a Hahmap for storing the characters and their occurance
        unordered_map<char, int> mp;
        
        // counting occuracne
        for(auto it: s)
        {
            mp[it]++;
        }
        
        // sort the string so repeated char will be come with together
        sort(s.begin(), s.end());
        
        // declare a ans string that will store our ans
        string ans = "";
        for(int i=0; i<s.size(); i++)
        {
            // char curr chatr into lowercase and uppercase
            char l = tolower(s[i]);
            char u = toupper(s[i]);
            
            // if both lower and uppercase are present then store it into ans
            // it will take greatest english letter that have occured more than 1 because it will run till n
            if(mp[l] && mp[u])
            {
                ans = u;        // storeing uppercase as given in the question that we need to return uppercase 
            }     
        }
        return ans;
    }
};