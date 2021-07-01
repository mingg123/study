import java.util. *;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
class NewsClustering {
    static public double intersect = 0.0;
    static public ArrayList<String> s1 = new ArrayList<String>();
    static public ArrayList<String> s2 = new ArrayList<String>();

    public ArrayList<String> makeArrayList(String str) {
        ArrayList<String> temp = new ArrayList<String>();
        for (int i = 0; i < str.length() - 1; i++) {
            Pattern pattern = Pattern.compile("^[a-zA-Z]");
            Matcher matcher = pattern.matcher(String.valueOf(str.charAt(i)));
            Matcher matcher2 = pattern.matcher(String.valueOf(str.charAt(i + 1)));
            if (matcher.find() && matcher2.find()) 
            temp.add(
                String.valueOf(str.charAt(i)).toUpperCase() + String.valueOf(str.charAt(
                    i + 1
                )).toUpperCase()
            );
        }
        
        return temp;
    }
    public void CalculateIntersect(ArrayList<String> large, ArrayList<String> small) {
        for(int i = 0; i< small.size(); i++) {
            String removeElem = small.get(i);
            if(large.contains(removeElem)){
                large.remove(removeElem);
                intersect++;
            }
        }   
    }
    public int solution(String str1, String str2) {
        s1 = makeArrayList(str1);
        s2 = makeArrayList(str2);
        
       
        if (s1.size() > s2.size()) {
            CalculateIntersect(s1, s2);
        } else {
            CalculateIntersect(s2, s1);
        }

        double sum = s1.size() + s2.size();
        double simulatper = (intersect == 0.0 && sum == 0.0)
            ? 1
            : (intersect / sum);
        double answer = simulatper * 65536;
        return (int)answer;
    }
}