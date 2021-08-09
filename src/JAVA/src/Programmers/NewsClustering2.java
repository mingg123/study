import java.util.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
public class NewsClustering2 {
    public int solution(String str1, String str2) {
        int answer = 65536;
        str1 = (str1).toUpperCase();
        str2 = (str2).toUpperCase();
 
        String changeStr1 = "";
        String changeStr2 = "";
        for(int i = 0; i <str1.length() -1; i++) {
            if(Character.isLetter(str1.charAt(i)) && Character.isLetter(str1.charAt(i+1))) {
                changeStr1 = changeStr1 + str1.substring(i, i+2);
            }
        } 
        
         for(int i = 0; i <str2.length() -1; i++) {
            if(Character.isLetter(str2.charAt(i)) && Character.isLetter(str2.charAt(i+1))) {
                changeStr2 = changeStr2 + str2.substring(i, i+2);
            }
        } 
        
        // System.out.println(changeStr1 + " " + changeStr2);
        
        ArrayList <String> str1List = new ArrayList<>();
        ArrayList <String> str2List = new ArrayList<>();
        
        for(int i = 0; i < changeStr1.length()-1; i = i+2) {
            str1List.add(changeStr1.substring(i, i+2));
        }
        for(int i = 0; i < changeStr2.length()-1; i = i+2) {
            str2List.add(changeStr2.substring(i, i+2));
         
        }
        
        ArrayList<String> tempList = new ArrayList<>(str2List);
        for(int i = 0; i < str1List.size(); i++)
        {
            tempList.remove(str1List.get(i));
        }
   
        int commonCount = str2List.size() - tempList.size();
        int sumCount = str1List.size() + str2List.size() - commonCount;
        if(commonCount != 0 || sumCount != 0) {
            answer = (int)((Double.valueOf(commonCount)/ Double.valueOf(sumCount)) * Double.valueOf(65536));
        }
        return answer;
    }
}

