import java.io.*;
import java.net.*;

public class Client {
    private static InetAddress host;
    private static final int PORT = 1234;
    private static Socket link = null;

    public static void main(String[] args) throws IOException {
        try {
            host = InetAddress.getLocalHost();

        } catch (UnknownHostException e) {
            System.out.println("Host id not found!");
            System.exit(-1);
        }

        try {
            link = new Socket(host, PORT);
        } catch (IOException e) {
            System.out.println(e);
            System.exit(-1);
        }

        ReadMessage read = new ReadMessage(link);

        WriteMessage write = new WriteMessage(link);
        while (true) {
            write.start();
            read.start();

        }

    }

}

class WriteMessage extends Thread {
    Socket link;

    WriteMessage(Socket link) {
        this.link = link;
    }

    public void run() {
        write();
    }

    public void write() {
        try {
            BufferedReader in = new BufferedReader(new InputStreamReader(link.getInputStream()));
            PrintWriter out = new PrintWriter(link.getOutputStream(), true);
            BufferedReader userentry = new BufferedReader(new InputStreamReader(System.in));
            String message;
            do {
                System.out.print("Enter message:");
                message = userentry.readLine();
                out.println(message);

            } while (!message.equals("close"));
        } catch (IOException e) {
            System.out.println("Message is not sent.");
        }
    }
}

class ReadMessage extends Thread {
    Socket link;

    ReadMessage(Socket link) {
        this.link = link;
    }

    public void run() {
        BufferedReader in = null;
        try {
            in = new BufferedReader(new InputStreamReader(this.link.getInputStream()));
        } catch (IOException e) {
            System.out.println("Unable to assigne link");
            System.exit(-1);
        }

        String response = null;

        try {
            response = in.readLine();

            while (!response.equals("close")) {
                System.out.println("Message recieved.");
                System.out.println("\nSERVER>" + response);

                response = in.readLine();
            }
        } catch (IOException e) {
            System.out.println("Message is not recieved");
        }

    }
}
