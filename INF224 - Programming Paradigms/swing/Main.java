//package swing;

public class Main {

	public static void main(String argv[])
	{
		String host = "127.0.0.1";
		int port = 3331;

		try {
			Client client = new Client(host, port);
			Window window = new Window(client);
			System.out.println("Starting server on port " + port);  
		}
		catch(Exception e) {
			e.printStackTrace();
			System.out.println("Failed to start server at port " + port); 
		}
	}
}
