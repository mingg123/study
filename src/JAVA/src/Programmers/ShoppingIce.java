import java.util.*;
class ShoppingIce {
    static Queue<String> q = new LinkedList<String>();
    static HashSet<String> set = new HashSet<String>(); 
    static HashMap<String, Integer> map = new HashMap<String, Integer>();
    static int startPoint = 0;
    static int distance = Integer.MAX_VALUE;
    public int[] solution(String[] gems) {
        int start = 0;
        for(int i = 0; i < gems.length; i++) {
            set.add(gems[i]);
        }
        for(int i = 0; i < gems.length; i++) {
            if(!map.containsKey(gems[i])) {
                map.put(gems[i], 1);
            }
        	else {
                map.put(gems[i], map.get(gems[i]) + 1);
            }
            q.add(gems[i]);
            while(true) {
                String temp = q.peek();
                if(map.get(temp) > 1) {
                    map.put(temp, map.get(temp) - 1);
                    q.poll();
                    startPoint++;
                }
                else {
                    break;
                }
            }
            if(set.size() == map.size() && distance > q.size()) {
                distance = q.size();
                start = startPoint;
            }
        }
        return new int[]{start+1, start+distance};
    }
}