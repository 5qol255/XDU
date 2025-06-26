//import java.util.Scanner;

public class Querier {
    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
        Querier querier = new Querier();
        String op = "";
        try {
            op = args[0];
        } catch (java.lang.ArrayIndexOutOfBoundsException err) {
            System.out.println("请输入参数！\n参数列表：\n-d yyyy MM dd：查询星期\n-c yyyy：输出日历");
        } finally {
            if (op.equals("-c")) {
//                System.out.println("请输入年份（1583年及以后）：");
//                int 年份 = scanner.nextInt();
//                querier.打印日历(年份);
                querier.打印日历(Integer.parseInt(args[1]));
            } else if (op.equals("-d")) {
//                System.out.println("请输入日期（1583年及以后）：");
//                int 年 = scanner.nextInt(), 月 = scanner.nextInt(), 日 = scanner.nextInt();
//                querier.打印星期(年, 月, 日);
                querier.打印星期(Integer.parseInt(args[1]), Integer.parseInt(args[2]), Integer.parseInt(args[3]));
            }
        }
    }

    private void 打印日历(int 年份) {
        int[] a = {5, 6, 7, 1, 2, 3, 4};// 修正数组，1583.1.1是周六
        String[] b = {"", "一月", "二月", "三月", "四月", "五月", "六月", "七月", "八月", "九月", "十月", "十一月", "十二月"};
        int s = 0, 星期;
        // 到输入年份的一月一日经过多少天
        for (int i = 1583; i < 年份; ++i)
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
                s += 366;
            else
                s += 365;
        ++s;// 算上一月一号
        星期 = a[s % 7];

        System.out.printf("\t\t    %d年\n", 年份);
        for (int i = 1; i <= 12; ++i) {
            System.out.printf("\t\t    %s\n一\t二\t三\t四\t五\t六\t日\n", b[i]);
            for (int tmp = 1; tmp < 星期; ++tmp)
                System.out.print('\t');
            for (int j = 1; j <= 28; ++j) {
                System.out.printf("%02d\t", j);
                if (++星期 > 7) {
                    System.out.print('\n');
                    星期 = 1;
                }
            }
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                for (int k = 29; k <= 31; ++k) {
                    System.out.printf("%d\t", k);
                    if (++星期 > 7) {
                        System.out.print('\n');
                        星期 = 1;
                    }
                }
            else if (i == 4 || i == 6 || i == 9 || i == 11)
                for (int k = 29; k <= 30; ++k) {
                    System.out.printf("%d\t", k);
                    if (++星期 > 7) {
                        System.out.print('\n');
                        星期 = 1;
                    }
                }
            else if ((年份 % 4 == 0 && 年份 % 100 != 0) || 年份 % 400 == 0) {
                System.out.print("29\t");
                if (++星期 > 7) {
                    System.out.print('\n');
                    星期 = 1;
                }
            }
            if (星期 != 1)
                System.out.println();
        }
    }

    private void 打印星期(int 年, int 月, int 日) {
        int[] a = {5, 6, 7, 1, 2, 3, 4};
        String[] b = {"", "一", "二", "三", "四", "五", "六", "日"};
        int s = 0;
        for (int i = 1583; i < 年; ++i)
            if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
                s += 366;
            else
                s += 365;
        for (int i = 1; i < 月; ++i) {
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                s += 31;
            else if (i == 4 || i == 6 || i == 9 || i == 11)
                s += 30;
            else if ((年 % 4 == 0 && 年 % 100 != 0) || 年 % 400 == 0)
                s += 29;
            else
                s += 28;
        }
        s += 日;
        System.out.println(b[a[s % 7]]);
    }
}