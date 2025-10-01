class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ll = new ArrayList<>();
        Map<String, Integer> wordFreq = new HashMap<>();
        for(String s1 : words){
            wordFreq.put(s1, wordFreq.getOrDefault(s1, 0) + 1);
        }
        int wordLen = words[0].length();
        for(int i = 0; i < wordLen; i++){
            int right = i;
            int left = i;
            HashMap<String, Integer> seen = new HashMap<>();
            int count  = 0;
            while(right + wordLen <= s.length()){
                String s1 = s.substring(right, right + wordLen);
                right += wordLen;
                if(wordFreq.containsKey(s1)){
                    seen.put(s1, seen.getOrDefault(s1, 0) + 1);
                    count++;
                    while(seen.get(s1) > wordFreq.get(s1)){
                        String s2 = s.substring(left, left + wordLen);
                        seen.put(s2, seen.get(s2) - 1);
                        count--;
                        left += wordLen;
                    }
                    if(count == words.length){
                        ll.add(left);

                    }
                }
                else{
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        return ll;
    }
}