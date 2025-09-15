class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.size();
        int cnt = 0;
        for(int i=0; i < n; i++){
            int start = i;
            bool canType = true;
            while(i<n && text[i] !=' ') i++;
            for(int j=0; j < brokenLetters.size(); j++){
                for(int k=start; k < i; k++){
                    if(brokenLetters[j] == text[k]){
                        canType = false;
                        break;
                    }
                }
                if(!canType) break;
            }
            if(canType){
                cnt++;
            }
        }
        return cnt;
    }
};