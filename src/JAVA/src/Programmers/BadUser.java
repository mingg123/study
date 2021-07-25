import java.util.*;
public class BadUser {
    HashSet <String> set;
    public void sol(int idx, String result, String [] reg, String[] user_id, boolean [] visit) {
        //banned_id 기준으로 다 찾으면 
        if(idx == reg.length) {
           String [] findStr = result.split(":");
           //순서가 섞여있어서 정렬한번 해주고 Set에 넣어줘야댐 
           Arrays.sort(findStr);

           set.add(Arrays.toString(findStr));
           return;
        }
        for(int i = 0; i < user_id.length; i++) {
            if(!visit[i] && user_id[i].matches(reg[idx])) {
                visit[i] = true;
                // 문자를 구분하기위해 임의로 : 넣어줌 
                String temp = result + ":" + user_id[i];
                sol(idx + 1, temp, reg, user_id, visit);
                visit[i] = false;
            }
        }
    }
    public int solution(String[] user_id, String[] banned_id) {
        set = new HashSet<>();
        String [] reg = new String[banned_id.length];
        boolean [] visit = new boolean[user_id.length];
        for(int i = 0; i< banned_id.length; i++) {
            //정규식 사용을 위해 
            reg[i] = banned_id[i].replace("*", ".");
        }
    
        sol(0, "", reg, user_id, visit);

    return set.size();
    }
}
