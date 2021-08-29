import java.util.*;
class NavigationRank {

    static HashMap<String, ArrayList<Integer>> map;
    
    static int findQuery(String key, int score) {
        if(!map.containsKey(key)) return 0;
        
        //아래와 같이 하면 효율성에서 시간초과남 
        // ArrayList<Integer> scoreList = new ArrayList<>(map.get(key));
        ArrayList<Integer> scoreList = (map.get(key));
        int start = 0;
        int end = scoreList.size() -1;
        while(start<=end) {
            int mid = (start+end)/2;
            if(scoreList.get(mid) < score) {
                start = mid +1;
            } else {
                end = mid -1;
            }
        }
        return scoreList.size() - start;

    }
    
    
    //이어 붙여서 넣음 
    static void dfs(String str, int depth, String[] token) {
        if(depth == 4) {
            if(!map.containsKey(str)) {
                ArrayList <Integer> temp = new ArrayList<>();
                temp.add(Integer.parseInt(token[4]));
                map.put(str, temp);
            } else {
                map.get(str).add(Integer.parseInt(token[4]));
            }
            return;
        }
        dfs(str+"-", depth+1, token);
        dfs(str+token[depth], depth+1, token);
    }
    
    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        map = new HashMap<>();
        for(int i = 0; i < info.length; i++) {
            dfs("", 0, info[i].split(" "));
        }
        
        // 안의 value 한번 정리한번 하고 이분탐색쓰기위해 
        ArrayList<String> list = new ArrayList<>(map.keySet());
        for(String key : list) {
            ArrayList<Integer> value = map.get(key);
            Collections.sort(value);
        }
        
        
        for(int i = 0; i < query.length; i++) {
            query[i]= query[i].replaceAll(" and ", "");
            String [] str = query[i].split(" ");
            answer[i] = findQuery(str[0], Integer.parseInt(str[1]));
        }
        return answer;
    }
}

