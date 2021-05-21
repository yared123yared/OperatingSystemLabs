public class ThreadTest {
    public static void main(String[] args) {
            CounterThread ct = new CounterThread();
            ct.start();
            System.out.println("The thread has been started");
            
            }
    }

class CounterThread extends Thread {
    public void run() {
        for ( int i=1; i<=5; i++) {
            System.out.println("Count: " + i); 
            }
        } 
    }