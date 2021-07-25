import java.util.*;
public class SortFileName {
    class CustomComparator implements Comparator<String> {
        @Override
        public int compare(String o1, String o2) {
            String head1 = o1.split("[0-9]")[0];
            String head2 = o2.split("[0-9]")[0];
                
            int result = head1.toLowerCase().compareTo(head2.toLowerCase());
            //head가 같을경우 
            if(result == 0) {
                result = compareNumber(o1, head1) - compareNumber(o2, head2);
            }
            return result;
        }
    }
    public int compareNumber (String o1, String head) {
        String num = o1.substring(head.length());
        String newStr = "";
        // TAIL을 제외한 방법 
        for(int i = 0; i < num.length(); i++) {
            if(Character.isDigit(num.charAt(i))) {
                newStr = newStr + Character.toString(num.charAt(i));
            } else break;
        }
        return  Integer.parseInt(newStr);
  
    }
    public String[] solution(String[] files) {
        //Compare 메서드 오버라이드 
        Arrays.sort(files, new Comparator<String>() {
        @Override
        public int compare(String o1, String o2) {
            String head1 = o1.split("[0-9]")[0];
            String head2 = o2.split("[0-9]")[0];
                
            int result = head1.toLowerCase().compareTo(head2.toLowerCase());
            //head가 같을경우 
            if(result == 0) {
                result = compareNumber(o1, head1) - compareNumber(o2, head2);
            }
            return result;
        }
        });
     
        return files;
    }
}
