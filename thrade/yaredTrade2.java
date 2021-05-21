public class RunnableTest{
    public static void main(String[] args){
        Draw dr= new Draw();
        Download dwn= new Download();
        Thread tr1= new Thread(dr);
        Thread tr2= new Thread(dwn);

        tr1.start();
        tr2.start();

        System.out.println("Thrade has been started");
       

    }
}

class Draw extends Nothing implements Runnable{
    public void run(){
            draw();
    }

    public void draw(){
        for(int i=0;i<1000;i++){
            System.out.println("Count" + i);
        }
    }
}

class Download extends Nothing implements Runnable{
    public void run(){
        download();
    }
    public void download(){
        System.out.println("Download");
    }
}
class Nothing{
    // Place holder
}