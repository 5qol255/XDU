package complex;

public class Complex {
    double a, b;// 实部虚部

    public static Complex parseComplex(Object o) {
        try {
            double a = Double.parseDouble(o.toString());
            return new Complex(a);
        } catch (ClassCastException | NumberFormatException err) {
            return null;
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

    public Complex conjugate() {
        // 共轭复数
        return new Complex(this.a, -this.b);
    }

    public Complex add(Complex c) {
        return new Complex(this.a + c.a, this.b + c.b);
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
}