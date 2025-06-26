import complex.Complex;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double a, b;

        System.out.println("输入第一个复数的实部：");
        a = scanner.nextDouble();
        System.out.println("输入第一个复数的虚部：");
        b = scanner.nextDouble();
        Complex x = new Complex(a, b);
        System.out.println(x + "的共轭复数为" + x.conjugate());

        System.out.println("输入第二个复数的实部：");
        a = scanner.nextDouble();
        System.out.println("输入第二个复数的虚部：");
        b = scanner.nextDouble();
        Complex y = new Complex(a, b);
        System.out.println(y + "的共轭复数为" + y.conjugate());

        System.out.println("(" + x + ")+(" + y + ")=" + x.add(y));
        System.out.println("(" + x + ")-(" + y + ")=" + x.sub(y));
        System.out.println("(" + x + ")*(" + y + ")=" + x.mul(y));
        System.out.println("(" + x + ")/(" + y + ")=" + x.div(y));
    }
}