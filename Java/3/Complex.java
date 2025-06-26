import java.util.Scanner;

class Test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s1 = "2.312313+0.1i";
        String s2 = "3i";
        String s3 = "7781212";
        String s4 = scanner.next();
        Complex c1 = new Complex(s1);
        Complex c2 = new Complex(s2);
        Complex c3 = new Complex(s3);
        Complex c4 = new Complex(s4);
        Complex c5 = Complex.valueOf(s1);
        Complex c6 = Complex.valueOf(s2);
        Complex c7 = Complex.valueOf(s3);
        Complex c8 = Complex.valueOf(s4);
        System.out.println(c1.add(c2));
        System.out.println(c1.sub(c3));
        System.out.println(c1.mul(c4));
        System.out.println(c2.div(c1));
        System.out.println(c5.add(c6));
        System.out.println(c5.sub(c7));
        System.out.println(c5.mul(c8));
        System.out.println(c6.div(c5));
    }
}

public class Complex extends Number {
    public double a, b;

    public static Complex valueOf(String s) {
        if (s.contains("+")) {
            String[] c = s.split("\\+");
            double a = Double.parseDouble(c[0]);
            double b = Double.parseDouble(c[1].replace("i", ""));
            return new Complex(a, b);
        } else if (s.contains("i")) {
            double b = Double.parseDouble(s.replace("i", ""));
            return new Complex(0, b);
        } else {
            double a = Double.parseDouble(s);
            return new Complex(a);
        }
    }

    public Complex(double a, double b) {
        this.a = a;
        this.b = b;
    }

    public Complex(double a) {
        this(a, 0.0);
    }

    public Complex() {
        this(0.0);
    }

    public Complex(String s) {
        if (s.contains("+")) {
            String[] c = s.split("\\+");
            this.a = Double.parseDouble(c[0]);
            this.b = Double.parseDouble(c[1].replace("i", ""));
        } else if (s.contains("i")) {
            this.a = 0;
            this.b = Double.parseDouble(s.replace("i", ""));
        } else {
            this.a = Double.parseDouble(s);
            this.b = 0;
        }
    }

    public Complex conjugate() {
        // 共轭复数
        return new Complex(this.a, -this.b);
    }

    public Complex add(Complex c) {
        return new Complex(this.a + c.a, this.b + c.b);
    }

    public Complex add(double x) {
        return new Complex(this.a + x, this.b);
    }

    public Complex sub(Complex c) {
        return new Complex(this.a - c.a, this.b - c.b);
    }

    public Complex mul(Complex c) {
        return new Complex(this.a * c.a - this.b * c.b, this.b * c.a + this.a * c.b);
    }

    public Complex div(Complex c) {
        Complex r = this.mul(c.conjugate());
        double tmp = c.a * c.a + c.b * c.b;
        if (tmp == 0)
            return null;
        r.a /= tmp;
        r.b /= tmp;
        return r;
    }

    public static Complex add(Complex x, Complex y) {
        return new Complex(x.a + y.a, x.b + y.b);
    }

    public static Complex sub(Complex x, Complex y) {
        return new Complex(x.a - y.a, x.b - y.b);
    }

    public static Complex mul(Complex x, Complex y) {
        return new Complex(x.a * y.a - x.b * y.b, x.b * y.a + x.a * y.b);
    }

    public static Complex div(Complex x, Complex y) {
        Complex r = Complex.mul(x, y.conjugate());
        double tmp = y.a * y.a + y.b * y.b;
        if (tmp == 0)
            return null;
        r.a /= tmp;
        r.b /= tmp;
        return r;
    }

    @Override
    public boolean equals(Object o) {
        Complex c = (Complex) o;
        return this.a == c.a && this.b == c.b;
    }

    @Override
    public int hashCode() {
        // 借鉴的网上的方法
        long r = Double.doubleToLongBits(a);
        r ^= Double.doubleToLongBits(b) * 31;
        return (((int) r) ^ ((int) (r >> 32)));
    }

    @Override
    public String toString() {
        if (this.a != 0 && this.b != 0) {
            if (this.b < 0)
                return this.a + "" + this.b + "i";
            else
                return this.a + "+" + this.b + "i";
        } else if (this.a == 0 && this.b != 0)
            return this.b + "i";
        else
            return this.a + "";
    }

    @Override
    public int intValue() {
        return (int) (this.a * this.a + this.b * this.b);
    }

    @Override
    public long longValue() {
        return (long) (this.a * this.a + this.b * this.b);
    }

    @Override
    public float floatValue() {
        return (float) (this.a * this.a + this.b * this.b);
    }

    @Override
    public double doubleValue() {
        return this.a * this.a + this.b * this.b;
    }
}