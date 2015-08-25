import org.testng.Assert;
import org.testng.annotations.AfterClass;
import org.testng.annotations.BeforeClass;
import org.testng.annotations.Test;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

/**
 * Created by jia.wang on 24/08/15.
 */
public class SimplePlusTest {
    @BeforeClass
    public void setUp() {
        try {
            Files.createFile(Paths.get("before.txt"));
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Setup 111");
        System.out.println("Setup...");
    }

    @Test
    public void test_case_simple() {
        System.out.println("test case");
        String filename = System.getProperty("txt_file_name");
        if (filename == null) {
            filename = "default_output_file.txt";
        }
        try {
            Files.createFile(Paths.get(filename));
        } catch (IOException e) {
            e.printStackTrace();
        }
        Assert.assertEquals(SimplePlus.plus(1, 2), 3);
    }

    @AfterClass
    public void tearDown() {
        System.out.println("tear down...");
    }
}
