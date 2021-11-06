import java.util.ArrayList;
import java.util.List;

public class codewars {
    public static void main(String[] args){
        codewars app=new codewars();
        java.io.InputStream in = System.in;
        char c;
        try {
            String buff="";
            while ((c = (char) in.read()) > 0) {
                if (c == '\n') {
                    if(app.isPalindrome(Integer.valueOf(buff)))
                        System.out.print("True");
                    else
                        System.out.print("False");
                    buff="";
                }else {
                    buff+=c;
                }

            }
        } catch (Exception ex) {
            System.out.print("False");
        }

    }
    public boolean isPalindrome(int x) {
        if(!(x>=Integer.MAX_VALUE)&&x>=0) {
            int temp = x;
            List<Integer> list = new ArrayList<Integer>();
            while (temp > 0) {
                list.add(temp % 10);
                temp = temp / 10;
            }
            temp = 0;
            while (temp < list.size() / 2) {
                if (!list.get(temp).equals(list.get(list.size() - temp - 1)))
                    return false;
                temp++;
            }
            return true;
        }else {
            return false;
        }
    }
}