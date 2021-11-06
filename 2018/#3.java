import java.util.Scanner;

public class codewars{
    public int numDecodings(String s) {
        if (s.length() == 0) return 0;
        int[] arr=new int[s.length()+1];
        char[] sa = s.toCharArray();
        arr[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            if (sa[i - 1] > '0') {
                arr[i] += arr[i - 1];
            }
            if(i>1){
                int num=Integer.valueOf(new String(new char[]{sa[i-2],sa[i-1]}));
                if ( num >= 10 && num <= 26) {
                    arr[i] += arr[i - 2];
                }
            }
        }
        return arr[s.length()];
    }
    
    public static void main(String[] argv) {
        codewars app=new codewars();
        Scanner scanner = new Scanner(System.in);
        String myString = scanner.next();
        System.out.println( app.numDecodings (myString) );
    }
}