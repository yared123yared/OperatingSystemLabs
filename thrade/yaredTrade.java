public class YaredThradeTest{
    public static void main(String[] args){
           DrawUi dr=new DrawUi();
           Download dwn= new Download();
           dr.start();
           dwn.start();
            System.out.println("The thrade has been started");
    }
}

class DrawUi extends Thread{
   public void run(){
        draw();
   }
   public void draw(){
    //    for(int i=0;i<10000000;i++){
    //     //    do nothing
    //    }
       System.out.println("Draw the user interface");
   }
    
}
class Download extends Thread{
    public void run(){
        download();
    }
    public void download(){
        System.out.println("Download");
    }
}