import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class NumberOfOnes {
    static int numberOfOnes(int num) {
        int total = 0;
        while (num > 0) {
            total += (num & 1);
            num >>= 1;
        }
        return total;
    }

    public static void main(String[] args) throws IOException {
        File file = new File(args[0]);
        BufferedReader buffer = new BufferedReader(new FileReader(file));
        String line;
        while ((line = buffer.readLine()) != null) {
            line = line.trim();
            int num = Integer.valueOf(line);
            System.out.println(numberOfOnes(num));
        }
    }
}
