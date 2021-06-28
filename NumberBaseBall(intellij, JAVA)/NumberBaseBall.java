/*
 * 숫자 야구 1.0
 * programmer: yooj
 * Date: 21.06.29
 * using: IntelliJ
 */
import java.util.HashSet;
import java.util.Scanner;

public class BBB {
    private static int first;
    private static int second;
    private static int third;
    private static HashSet<Integer> set;
    private static int sn;
    private static int bn;
    private static boolean flag;

    public static int getFirst() {
        return first;
    }

    public static int getSecond() {
        return second;
    }

    public static int getThird() {
        return third;
    }

    public static HashSet<Integer> getSet() {
        return set;
    }

    public static int getSn() {
        return sn;
    }

    public static int getBn() {
        return bn;
    }

    public static boolean isFlag() {
        return flag;
    }

    public static void main(String[] args) {
        setTarget("713");//시작넘버를 713으로 테스팅
        Scanner scanner = new Scanner(System.in);
        flag = true;
        while (flag) {//숫자야구 시작
            System.out.print("Insert the Numbers : ");
            String a = scanner.next();
            checkB(a);
        }

    }

    public static void setTarget(String str) {//종료시 타겟 설정
        first = Integer.parseInt(str.substring(0, 1));
        second = Integer.parseInt(str.substring(1, 2));
        third = Integer.parseInt(str.substring(2, 3));
        set = new HashSet<>();
        set.add(first);
        set.add(second);
        set.add(third);
    }

    public static void checkB(String str) {//볼 체크
        bn = 0;
        sn = 0;
        int one = Integer.parseInt(str.substring(0, 1));
        int two = Integer.parseInt(str.substring(1, 2));
        int three = Integer.parseInt(str.substring(2, 3));
        //스트라이크 체크
        if (set.contains(one)) {
            bn++;
            checkS(1, one);
        }
        if (set.contains(two)) {
            bn++;
            checkS(2, two);
        }
        if (set.contains(three)) {
            bn++;
            checkS(3, three);
        }
        PrintScore();//스코어 확인
    }

    public static void checkS(int idx, int x) {//스트라이크 체크
        if (idx == 1 && first == x) {
            sn++;
            bn--;
            return;
        }
        if (idx == 2 && second == x) {
            sn++;
            bn--;
            return;
        }
        if (idx == 3 && third == x) {
            sn++;
            bn--;
        }

    }

    public static void PrintScore() {//스코어 출력
        StringBuilder str = new StringBuilder();
        if (bn > 0) {
            str.append(bn + "Ball ");
        }
        if (sn > 0) {
            str.append(sn + "Strike");
        }
        if (sn == 0 && bn == 0)
            str.append("Nothing");
        System.out.println(str);
        if (sn == 3)
            exitThegame();
    }

    public static void exitThegame() {//게임 종료할지 계속할지 확인
        System.out.println("3 correct game set");
        System.out.println("re game: 1, exit: 2");
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        if (k == 1) {
            System.out.println("set Target");
            setTarget(scanner.next());
            flag = true;
            return;
        }
        if (k == 2) {
            flag = false;
        }
    }


}
