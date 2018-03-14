//以下代码在JDK 1.8中通过。
import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();
        while (k-- != 0) {
            BigInteger result = BigInteger.ZERO;
            for (int i = 0; i != 4; ++i) {
                result = result.add(in.nextBigInteger());
            }
            System.out.println(result);
        }
    }
}
