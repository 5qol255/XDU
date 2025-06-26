import java.util.Scanner;

class Test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double m = scanner.nextDouble();
        int p = scanner.nextInt();
        Account a=Account.getInstance(m,p);
    }
}

class MyException extends Exception {
    private static final long serialVersionUID = 1145141919810L;
    private double x;

    public MyException(String txt, double x) {
        super(txt);
        this.x = x;
    }

    public double getId() {
        return x;
    }
}

class Account {
    private double money;
    private int password;

    private Account(double money, int password) {
        this.money = money;
        this.password = password;
    }

    public static Account getInstance(double money, int password)  {
        try {
            Account a = build(money, password);
            return a;
        } catch (MyException e) {
            System.out.println("账户余额不能少于0：" + e.getId());
            return null;
        }
    }

    public static Account build(double money, int password) throws MyException{
        if (money < 0)
            throw new MyException("账户余额不能少于0", money);
        else
            return new Account(money, password);
    }
}