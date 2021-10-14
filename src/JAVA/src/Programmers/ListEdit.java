import java.util.*;
public class ListEdit {
 
class Solution {
    public String solution(int n, int k, String[] cmd) {
        Node[] nodeArr = new Node[1000000];
        for(int i =0; i< n; i++) {
            nodeArr[i] = new Node();
        }
        for(int i =1; i<n; i++) {
            nodeArr[i-1].next = nodeArr[i];
            nodeArr[i].prev = nodeArr[i-1];
        }
        
        Stack<Node> s = new Stack<>();
        Node curr = nodeArr[k];
        for(String str : cmd) {
            char dir = str.charAt(0);
           
            if(dir=='U') {
                int x = Integer.parseInt(str.substring(2));
                for(int i =0; i< x; i++) 
                    curr = curr.prev;
            }
        
            if(dir=='D') {
                int x= Integer.parseInt(str.substring(2));
                for(int i =0; i<x; i++)
                    curr= curr.next;
            }
                
        
            if(dir=='C') {
                curr.remove = true;
                s.push(curr);
                Node up = curr.prev;
                Node down = curr.next;
                if(up!= null)
                    up.next = down;
                if(down!=null) {
                    down.prev = up;
                    curr = down;
                } else {
                    curr =up;
                }
            }
            
            if(dir=='Z') {
        
                Node recover = s.pop();
                Node up = recover.prev;
                Node down = recover.next;
                
                recover.remove = false;
                if(up!= null) {
                    up.next = recover;
                }
                if(down!=null) {
                    down.prev = recover;
                }
            }
            
        }
      
        StringBuilder sb = new StringBuilder();
        for(int i =0; i<n; i++) {
            if(nodeArr[i].remove) {
                sb.append("X");
            } else {
                sb.append("O");
            }
        }
      
        return sb.toString();
        
    }
    class Node {
        boolean remove;
        Node prev;
        Node next;
    }
}
}
