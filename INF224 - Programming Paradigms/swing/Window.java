//package swing;
import javax.swing.*;
import javax.swing.text.BadLocationException;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Container;


public class Window extends JFrame{
	private static final long serialVersionUID = 1L;
	
	private Client client;
	
	private JButton b1, b2, b3, b4, b5, b6;
	private JMenu menu;
	private JMenuItem m1, m2, m3;
	
	private JTextArea txt;
	private JScrollPane scroll;
	
	private JPanel panel;
	
	private JToolBar tools;
	private JMenuBar menubar;
	
	public Window(Client client) { 
		this.client = client;
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setBounds(100, 100, 20, 20);
		
		//creating button panel
		panel = new JPanel();
		b1 = new JButton("Search");
		b2 = new JButton("Play");
		b3 = new JButton("Close");
		
		panel.add(b1);
		panel.add(b2);
		panel.add(b3);
		this.add(panel, BorderLayout.SOUTH);
		
		// creating text area
		txt = new JTextArea(20, 30);
		//txt.setEditable(false);
		txt.setLineWrap(true);
		txt.setWrapStyleWord(true);
		scroll = new JScrollPane(txt);
	    scroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
		this.add(scroll, BorderLayout.CENTER);
		
		//creating toolbar
		tools = new JToolBar();
		b4 = new JButton("Search");
		b5 = new JButton("Play");
		b6 = new JButton("Close");
		
		tools.add(b4);
		tools.add(b5);
		tools.add(b6);
		this.add(tools, BorderLayout.NORTH);
		
		//creating menubar

		menubar = new JMenuBar();
		menu = new JMenu("Menu");
		m1 = new JMenuItem("Search");
		m2 = new JMenuItem("Play");
		m3 = new JMenuItem("Close");
		
		menu.add(m1);
		menu.add(m2);
		menu.add(m3);
		menubar.add(menu);
		this.setJMenuBar(menubar);
		
		this.pack();
		this.setVisible(true);
		
		b1.addActionListener(new Listener());
		b2.addActionListener(new Listener());
		b3.addActionListener(new Listener());
		b4.addActionListener(new Listener());
		b5.addActionListener(new Listener());
		b6.addActionListener(new Listener());
		m1.addActionListener(new Listener());
		m2.addActionListener(new Listener());
		m3.addActionListener(new Listener());
	};
	class Listener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			String str;
			int i=0;
			if (e.getSource()==b3||e.getSource()==b6||e.getSource()==m3) {
				System.exit(0);
			}
			// there is text to parse
			str = txt.getText();
			for (i=str.length()-1;i>=0;i--) {
				if (str.charAt(i)=='\n') break;
			}
			if (i<0)i=0;
			else i++;
			System.out.println(i);
			try {
				str = txt.getText(i, str.length()-i);
			} catch (BadLocationException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
			
			if(e.getSource()==b1||e.getSource()==b4||e.getSource()==m1) {
				System.out.println("Request to search...");
				txt.append("\nSearching for: " + str + "\n");
				String response = client.send("search " + str);
				if(response != null) {txt.append(response + "\n");}
				else {txt.append("Name not found!\n");}
				
			} else if (e.getSource()==b2||e.getSource()==b5||e.getSource()==m2) {
				System.out.println("Request to play...");
				txt.append("\nPlaying:"+str+ "\n");
				String response = client.send("play " + str);
				if(response != null) {txt.append(response + "\n");}
				else {txt.append("Name not found!\n");}
		}
	};

}
}
