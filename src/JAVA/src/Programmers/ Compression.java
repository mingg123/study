import java.util.*;
class Compression {
    public int[] solution(String msg) {
        // int[] answer = {};
        ArrayList <Integer> answer = new ArrayList<Integer>();
        //map에 초기화 
        HashMap<String, Integer> m = new HashMap<String, Integer>();
        for(int i = 0; i < 26; i++ ) {
            m.put((Character.toString((char) (65 + i))), i+1);
        }
        
        int z = 0;
        boolean flag = false;
        for(z = 0; z < msg.length(); z++) {
            if(flag == true) {
                break;
            }
            for(int j = z +1; j < msg.length(); j++) {
                String oriStr = msg.substring(z, j);
                String checkStr = msg.substring(z,j+1);
                if(!m.containsKey(checkStr)) {
                    m.put(checkStr, m.size()+1);
                    answer.add(m.get(oriStr));
                    z = j-1;
                    break;
                } else if(j == msg.length()-1 && m.containsKey(checkStr) && m.containsKey(oriStr)) {
                    answer.add(m.get(checkStr));
                    flag = true;
                    break;
                }
            }
            if(flag ==false && z == msg.length() -1) {
                answer.add(m.get(msg.substring(z, z+1)));
            }
        }
        return answer.stream().mapToInt(i -> i).toArray();
    }
}