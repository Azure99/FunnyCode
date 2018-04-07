import java.util.HashMap;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sin = new Scanner(System.in);

        int T = sin.nextInt();
        for(int Ti=0; Ti<T; Ti++){
            int N = sin.nextInt();
            HashMap<String, Integer> map = new HashMap<String, Integer>();

            for(int Ni=0; Ni<N-1; Ni++){
                String name = sin.next();
                sin.next();
                int val = sin.nextInt();
                map.put(name, val);
            }


            int sum = 0;
            boolean opt = true;//true 加 false 减

            while (sin.hasNext()){
                String nametmp = sin.next();
                String opttmp = sin.next();

                try
                {
                    int val = Integer.valueOf(nametmp);
                    if(opt)
                    {
                        sum += val;
                    }
                    else
                    {
                        sum -= val;
                    }
                }
                catch (Exception e)
                {
                    if(opt)
                    {
                        sum += map.get(nametmp);
                    }
                    else
                    {
                        sum -= map.get(nametmp);
                    }
                }

                if(opttmp.equals("=")){
                    sin.next();
                    break;
                }
                else if(opttmp.equals("+"))
                {
                    opt = true;
                }
                else
                {
                    opt = false;
                }
            }
            System.out.println(sum);
        }
    }
}