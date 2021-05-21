public class RunnableTest {
    public static void main(String[] args) {
        RunCounter rct = new RunCounter();
        Thread th = new Thread(rct);
        th.start();
        System.out.println("The thread has been started");
}

}   