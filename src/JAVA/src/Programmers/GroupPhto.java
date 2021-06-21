import java.util.*;
import java.io.*;
class Solution {
    
    static int [] result;
    static boolean [] visitied;
    static int cnt;
    static HashMap<Character, Integer> map;
    
    public static void perm(int depth, String [] data) {
        if(depth == 8) {
            if(checkValidation(data))
            {
                cnt++;
            }
            return;
        }
        for(int i = 0; i< 8; i++) {
            if(!visitied[i]){
                visitied[i] = true;
                result[depth]= i;
                perm(depth+1, data);
                visitied[i] = false;
            }
        }
    }    
 
    
      public static boolean checkValidation(String [] data) {
        for(int i =0; i< data.length; i++) {
            int x = map.get(data[i].charAt(0));
            int y = map.get(data[i].charAt(2));
            char type = data[i].charAt(3);
            int Xpos = result[x];
            int Ypos = result[y];
            int diff = Integer.parseInt(String.valueOf(data[i].charAt(4)));
            //  int diff = data[i].charAt(4) - '0';
            if(type == '='){
                if(Math.abs(Xpos-Ypos) != (diff+1)) {
                    return false;
                }
            } else if(type == '>') {
                if(Math.abs(Xpos-Ypos)  <= diff+1) {
                    return false;
                }
            } else {
                if(Math.abs(Xpos-Ypos)  >= diff+1) {
                    return false;
                }
            }   
        }
        return true;
    }
    
    public int solution(int n, String[] data) {
        int answer = 0;
        result = new int[8];
        visitied = new boolean[8];
        cnt = 0;
        map = new HashMap<>();
        
        map.put('A', 0);
        map.put('C', 1);
        map.put('F', 2);
        map.put('J', 3);
        map.put('M', 4);
        map.put('N', 5);
        map.put('R', 6);
        map.put('T', 7);
        perm(0, data);
        answer = cnt;
        return answer;
    }
}