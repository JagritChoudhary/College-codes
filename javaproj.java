import javax.swing.*;
import java.awt.*;

public class Example1{
public static void main(String[] args) {
    JFrame j = new JFrame("Student info ");
    j.setSize(500,600);
  
    j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    JPanel p = new JPanel();
    JLabel label1= new JLabel("Student name - ");
    label1.setBounds(1,12,100,20 );
    JTextField l1 = new JTextField(10);
    l1.setBounds(10,50,300,30);
    JLabel label2= new JLabel("Student intrest - ");
    label2.setBounds(1,60,300,80);
    JTextField l2 = new JTextField(10);
    l2.setBounds(10,130,300,30);
    JButton b = new JButton("Submit");
    b.setBounds(80,180,100,50);

    b.setPreferredSize(new Dimension(100,50));
    p.setLayout(null);
    p.add(label1);
    p.add(l1);
    p.add(label2);
    p.add(l2);
    

    j.add(p);
    p.add(b);
    j.setVisible(true);
}
}
