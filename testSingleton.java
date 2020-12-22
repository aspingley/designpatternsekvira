class someClass{
    public void get(){
        testSingleton ts = testSingleton.getInstance();
        int g =  ts.getX();
        System.out.println(g);
        ts.setX(10);

        testSingleton ts1 = testSingleton.getInstance();
        System.out.println(ts1.getX());

        ts.setX(50);

        testSingleton ts2 = testSingleton.getInstance();
        System.out.println(ts2.getX());

        System.out.println(ts1.getX());
    }
}

public class testSingleton{
    private static testSingleton _instance;
    private int x;

   private testSingleton(){
        _instance = null;
        x = 7;
   } 

   public static testSingleton getInstance(){
       if(null == _instance){
            _instance = new testSingleton();
       }
        return _instance;
   }

   public int getX(){
       return x;
   }

   public void setX(int a){
        x = a;
   }

   public static void main(String args[]){
        //testSingleton ts = new testSingleton();
        someClass sc = new someClass();
        sc.get();
    }

}

