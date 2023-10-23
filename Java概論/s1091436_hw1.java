import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class test extends Frame implements ActionListener
{
    static test frm = new test();
    static Button one=new Button();
    static Button two=new Button();
    static Button three=new Button();
    static Button four=new Button();
    static Button five=new Button();
    static Button six=new Button();
    static Button seven=new Button();
    static Button eight=new Button();
    static Button nine=new Button();
    static int check[]={0,0,0,0,0,0,0,0,0};
    static int circle[]={0,0,0,0,0,0,0,0,0};
    static int fork[]={0,0,0,0,0,0,0,0,0};
    static  int mode=0;
    static boolean checkwin()
    {
        if((circle[0]==1&&circle[1]==1&&circle[2]==1)||(circle[3]==1&&circle[4]==1&&circle[5]==1)||(circle[6]==1&&circle[7]==1&&circle[8]==1)
        ||(circle[0]==1&&circle[3]==1&&circle[6]==1)||(circle[1]==1&&circle[4]==1&&circle[7]==1)||(circle[2]==1&&circle[5]==1&&circle[8]==1)
        ||(circle[0]==1&&circle[4]==1&&circle[8]==1)||(circle[2]==1&&circle[4]==1&&circle[6]==1))
            return true;
        else if((fork[0]==1&&fork[1]==1&&fork[2]==1)||(fork[3]==1&&fork[4]==1&&fork[5]==1)||(fork[6]==1&&fork[7]==1&&fork[8]==1)
        ||(fork[0]==1&&fork[3]==1&&fork[6]==1)||(fork[1]==1&&fork[4]==1&&fork[7]==1)||(fork[2]==1&&fork[5]==1&&fork[8]==1)
        ||(fork[0]==1&&fork[4]==1&&fork[8]==1)||(fork[2]==1&&fork[4]==1&&fork[6]==1))
            return true;
        else
            return false;
    }
    static void reset()
    {
        one.setLabel("");
        two.setLabel("");
        three.setLabel("");
        four.setLabel("");
        five.setLabel("");
        six.setLabel("");
        seven.setLabel("");
        eight.setLabel("");
        nine.setLabel("");
        for(int i=0;i<9;i++)
        {
            check[i]=0;
            circle[i]=0;
            fork[i]=0;
        }
        mode=0;
    }
    public static void main(String args[])
    {
        one.addActionListener(frm);
        two.addActionListener(frm);
        three.addActionListener(frm);
        four.addActionListener(frm);
        five.addActionListener(frm);
        six.addActionListener(frm);
        seven.addActionListener(frm);
        eight.addActionListener(frm);
        nine.addActionListener(frm);
        GridLayout grid=new GridLayout(3,3);
        frm.setLayout(grid);
        frm.setSize(200,150);
        frm.setVisible(true);   
        frm.add(one);
        frm.add(two);
        frm.add(three);
        frm.add(four);
        frm.add(five);
        frm.add(six);
        frm.add(seven);
        frm.add(eight);
        frm.add(nine);
        frm.addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
            }
        });
    }
    public void actionPerformed(ActionEvent e)
    {
        Button btn=(Button)e.getSource();
        if(mode==0)
        {
            if(btn==one)
            {
                if(check[0]==0)
                {
                    one.setLabel("O");
                    check[0]=1;
                    circle[0]=1;
                    mode=1;
                }
            }
            if(btn==two)
            {
                if(check[1]==0)
                {
                    two.setLabel("O");
                    check[1]=1;
                    circle[1]=1;
                    mode=1;
                }
            }
            if(btn==three)
            {
                if(check[2]==0)
                {
                    three.setLabel("O");
                    check[2]=1;
                    circle[2]=1;
                    mode=1;
                }
            }
            if(btn==four)
            {
                if(check[3]==0)
                {
                    four.setLabel("O");
                    check[3]=1;
                    circle[3]=1;
                    mode=1;
                }
            }
            if(btn==five)
            {
                if(check[4]==0)
                {
                    five.setLabel("O");
                    check[4]=1;
                    circle[4]=1;
                    mode=1;
                }
            }
            if(btn==six)
            {
                if(check[5]==0)
                {
                    six.setLabel("O");
                    check[5]=1;
                    circle[5]=1;
                    mode=1;
                }
            }
            if(btn==seven)
            {
                if(check[6]==0)
                {
                    seven.setLabel("O");
                    check[6]=1;
                    circle[6]=1;
                    mode=1;
                }
            }
            if(btn==eight)
            {
                if(check[7]==0)
                {
                    eight.setLabel("O");
                    check[7]=1;
                    circle[7]=1;
                    mode=1;
                }
            }
            if(btn==nine)
            {
                if(check[8]==0)
                {
                    nine.setLabel("O");
                    check[8]=1;
                    circle[8]=1;
                    mode=1;
                }
            }
            if(checkwin())
            {
                JFrame circle = new JFrame();
                JOptionPane.showMessageDialog(circle, "圈圈方贏了!!!");  
            }
            else
            {
                int sum=0;
                for(int i=0;i<9;i++)
                {
                    sum+=check[i];
                }
                if(sum==9)
                {
                    JFrame nowin = new JFrame();
                    JOptionPane.showMessageDialog(nowin, "沒有人贏!!!");
                    reset();
                }
            }
        }
        else if(mode==1)
        {
            
            if(btn==one)
            {
                if(check[0]==0)
                {
                    one.setLabel("X");
                    fork[0]=1;
                    check[0]=1;
                    mode=0;
                }
            }
            if(btn==two)
            {
                if(check[1]==0)
                {
                    two.setLabel("X");
                    fork[1]=1;
                    check[1]=1;
                    mode=0;
                }
            }
            if(btn==three)
            {
                if(check[2]==0)
                {
                    three.setLabel("X");
                    fork[2]=1;
                    check[2]=1;
                    mode=0;
                }
            }
            if(btn==four)
            {
                if(check[3]==0)
                {
                    four.setLabel("X");
                    fork[3]=1;
                    check[3]=1;
                    mode=0;
                }
            }
            if(btn==five)
            {
                if(check[4]==0)
                {
                    five.setLabel("X");
                    fork[4]=1;
                    check[4]=1;
                    mode=0;
                }
            }
            if(btn==six)
            {
                if(check[5]==0)
                {
                    six.setLabel("X");
                    fork[5]=1;
                    check[5]=1;
                    mode=0;
                }
            }
            if(btn==seven)
            {
                if(check[6]==0)
                {
                    seven.setLabel("X");
                    fork[6]=1;
                    check[6]=1;
                    mode=0;
                }
            }
            if(btn==eight)
            {
                if(check[7]==0)
                {
                    eight.setLabel("X");
                    fork[7]=1;
                    check[7]=1;
                    mode=0;
                }
            }
            if(btn==nine)
            {
                if(check[8]==0)
                {
                    nine.setLabel("X");
                    fork[8]=1;
                    check[8]=1;
                    mode=0;
                }
            }
            if(checkwin())
            {
                JFrame fork = new JFrame();
                JOptionPane.showMessageDialog(fork, "叉叉方贏了!!!");
                reset();
            }
            else
            {
                int sum=0;
                for(int i=0;i<9;i++)
                {
                    sum+=check[i];
                }
                if(sum==9)
                {
                    JFrame nowin = new JFrame();
                    JOptionPane.showMessageDialog(nowin, "沒有人贏!!!");
                    reset();
                }
            }
        }
    }
}