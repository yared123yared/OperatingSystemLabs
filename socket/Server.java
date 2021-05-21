import java.io.*;
import java.net.*;



public class Server {
    
static ServerSocket servSock;
    private static final int PORT = 1234;
    public static void main(String[] args) throws IOException {
        
    
        try {
            servSock = new ServerSocket(PORT);
        } catch (IOException e) {
            System.out.println(e);
            System.exit(-1);
        }


        while(true){
            Listen listen1= new Listen(servSock);
            Thread th1= new Thread(listen1);
            th1.start();
        }
        // Thread th2= new Thread(listen1);
        
        // th2.start();
    }

    public static void listenSocket() {
        

    }
}

class Listen extends Nothing implements Runnable{
    ServerSocket servSock;
    Listen(ServerSocket servSock){
this.servSock=servSock;
    }
    
    public void run(){
        
        Socket link = null;
        try {
            link = servSock.accept();
        } catch (IOException e) {
            System.out.println("Accept failed: Port 1234");
        }
        System.out.println("Openning port.....");
        Read read = new Read(link);
        Thread th1= new Thread(read);
       
        Write write = new Write(link);
        while (true) {
            th1.start();
           
            write.start();
        }
    }
}

class Write extends Thread {
    Socket link;

    Write(Socket link) {
        this.link = link;
    }

    public void run() {
        write();
    }

    public void write() {
        try {
            // BufferedReader in = new BufferedReader(new InputStreamReader(link.getInputStream()));
            PrintWriter out = new PrintWriter(link.getOutputStream(), true);
            BufferedReader userentry = new BufferedReader(new InputStreamReader(System.in));
            String message;
            do {
                System.out.print("Enter Replay message:");
                message = userentry.readLine();
                out.println(message);

            } while (!message.equals("close"));
        } catch (IOException e) {
            System.out.println("Message is not sent.");
        }
    }
}



class Read extends Nothing implements Runnable {
    Socket link;

    Read(Socket link) {
        this.link = link;
    }

    public void run() {
        read();
    }

    public void read() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(link.getInputStream()));
            // PrintWriter out = new PrintWriter(link.getOutputStream(), true);
            int numMessages = 0;
            String message = in.readLine();

            while (!message.equals("close")) {
                System.out.println("Message recieved.");
                numMessages++;
                System.out.println("Message" + numMessages + ":" + message);
                message = in.readLine();
            }
        } catch (IOException e) {
            System.out.println("Message is not recieved");
        }
    }
}
class Nothing {

}