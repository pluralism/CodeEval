import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

public class Main {
    static String evaluate(String[] words, String letters) {
        HashMap<Character, Integer> vals = new HashMap<>();
        for(int i = 0; i < letters.length(); i++) {
            if(!vals.containsKey(letters.charAt(i))) vals.put(letters.charAt(i), 0);
            vals.put(letters.charAt(i), vals.get(letters.charAt(i)) + 1);
        }

        StringBuilder result = new StringBuilder();
        for(String word : words) {
            HashMap<Character, Integer> other = new HashMap<>();
            for(int i = 0; i < word.length(); i++) {
                Character letter = word.charAt(i);
                if(!other.containsKey(letter)) other.put(letter, 0);
                other.put(letter, other.get(letter) + 1);
            }

            boolean valid = true;
            for(Character c : vals.keySet()) {
                int val = vals.get(c);
                if(!other.containsKey(c) || (other.containsKey(c) && other.get(c) < val)) {
                    valid = false;
                    break;
                }
            }
            if(valid) result.append(word).append(" ");
        }

        String res = result.toString().trim();
        return res.isEmpty() ? "False" : res;
    }

    public static void main(String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while ((line = buffer.readLine()) != null) {
            line = line.trim();
            String[] parts = line.split("\\|");
            System.out.println(evaluate(parts[0].split(" "), parts[1].trim()));
        }
    }
}
