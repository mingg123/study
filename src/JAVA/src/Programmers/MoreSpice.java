import java.util.*;

class MoreSpice {
    static PriorityQueue<Integer> priorityQueue;
    
    
    public int solution(int[] scoville, int K) {
        int answer = 0;
        priorityQueue = new PriorityQueue<>(); 
     
        
        for(int i =0; i<scoville.length; i++) {
            priorityQueue.offer(scoville[i]);
        }

        while(priorityQueue.peek() <= K) {

            //if문 가장위에써주지 않고 poll먼저 했더니 답이 한 3개인가 틀림 
             if(priorityQueue.size() == 1) {
                answer = -1;
                break;
            } 
            
            int first = priorityQueue.poll();
            int second = priorityQueue.poll();
            
            answer ++;
            priorityQueue.offer(first + (second *2));
            
        }
        return answer;
    }
}