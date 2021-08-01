import java.util. *;
public class AutoComplete {

    static Node root = new Node();
    public void init(String str) {
        Node curNode = root;
        for (int i = 0; i < str.length(); i++) {
            Node newNode = curNode.put(str.charAt(i));
            curNode = newNode;
        }
        //가장 마지막임을 알리는 표시 go* , gone*
        curNode.put('*');
    }
    //root부터 하나씩 내려가면서 찾음
    public int search(Node root, int cnt) {
        // 가장 마지막 다음으로 갈 필요X
        if (root.count == 1) {
            return cnt;
        } else {
            int count = 0;
            for (char key : root.Nodes.keySet()) {
                //가장 마지막일경우 ex) go*
                if (key == '*') {
                    count = count + cnt;
                } else {
                    count = count + search(root.Nodes.get(key), cnt + 1);
                }
            }
            return count;
        }

    }
    public int solution(String[] words) {
        int answer = 0;
        for (int i = 0; i < words.length; i++) {
            //트리를 채움
            init(words[i]);
        }
        return search(root, 0);
    }
    static class Node {
        private HashMap<Character, Node> Nodes = new HashMap<>();
        private int count = 0;

        Node put(char temp) {
            count++;
            if (!Nodes.containsKey(temp)) {
                Nodes.put(temp, new Node());
            }
            return Nodes.get(temp);
        }
    }

}
