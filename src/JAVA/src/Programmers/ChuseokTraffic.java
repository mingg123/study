import java.util.*;
class ChuseokTraffic {
    public int solution(String[] lines) {
        int answer = 0;
        int [] cnt = new int[lines.length];
        double complete;
        
        for(int i= 0; i< lines.length; i++) {
            lines[i] = lines[i].substring(11).replace(":", "").replace("s", "");
            System.out.println(lines[i]);
        int sec = Integer.parseInt(lines[i].substring(0,2))*3600 + Integer.parseInt(lines[i].substring(2,4))*60 + Integer.parseInt(lines[i].substring(4,6));
        lines[i] = sec + lines[i].substring(6);           
        }
        
        for(int i=0; i<lines.length; i++)
        {
            String [] temp = lines[i].split(" ");
            
            complete = Double.parseDouble(temp[0]);
            
            //1초 후 
            double finish = complete + 1;
            
            for(int j = i; j < lines.length; j++) {
                temp = lines[j].split(" ");
                double start = Double.parseDouble(temp[0]) - Double.parseDouble(temp[1]) + 0.001;
                if(start < finish) {
                    cnt[i]++;
                }
            }
        }
        answer = Arrays.stream(cnt).max().getAsInt();
    
        return answer; 
    }
}