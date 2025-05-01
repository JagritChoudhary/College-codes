interface shape{
   void cube(int number);
   void square(int number);

}
class a implements shape{

  public  void cube(int number){
        System.out.println("cube -");
       
        int r=number*number*number;
        System.out.println(r);
    }
    public void square(int number){
        System.out.println("square- ");
        int r1=number*number;
        System.out.println(r1);

    }
}
class main3 extends a{
    
    public static void main (String[] args){
         
        main3 m= new main3();
        
        m.cube(25);
        m.square(25);
       

    }
}
