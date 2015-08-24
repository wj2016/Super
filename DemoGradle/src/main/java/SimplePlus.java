import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * Created by jia.wang on 24/08/15.
 */
public class SimplePlus {
    public static int plus(int a, int b) {
        return a + b;
    }

    public static void main(String[] args) throws IOException {
        System.out.println("Hello, world");
        Files.createFile(Paths.get("simple_plus_main.txt"));
    }
}
