import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class MyPanel extends JPanel {
    public void paint(Graphics g) {
        super.paint(g);
        g.setColor(new Color(255, 255, 255));
        g.fillRect(0, 0, getWidth(), getHeight());
    }
}

public class s1091436 extends JFrame implements ActionListener, WindowListener, MouseListener, MouseMotionListener {
    MyPanel mp = null;
    static s1091436 frm = new s1091436();
    static JButton clear = new JButton("clear");
    static JButton draw = new JButton("draw");
    static JButton size = new JButton("size");
    static JButton color = new JButton("color");
    static JButton erase = new JButton("erase");
    static Color choosecolor = new Color(0, 0, 0);
    static Color memcolor;
    static int x = 0, y = 0, x1 = 0, y1 = 0, drawsize = 0, mode = 0;

    public static void main(String[] args) {
        MyPanel mp = new MyPanel();
        Container cp = frm.getContentPane();
        JPanel panel = new JPanel();
        panel.add(draw);
        panel.add(erase);
        panel.add(color);
        panel.add(size);
        panel.add(clear);
        cp.add(panel, BorderLayout.NORTH);
        frm.add(mp);
        clear.addActionListener(frm);
        size.addActionListener(frm);
        color.addActionListener(frm);
        erase.addActionListener(frm);
        draw.addActionListener(frm);
        frm.addMouseListener(frm);
        frm.addMouseMotionListener(frm);
        frm.setSize(1000, 1000);
        frm.setVisible(true);
        frm.setResizable(false);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        Graphics g = frm.getGraphics();
        if (mode != 2) {
            x1 = e.getX();
            y1 = e.getY();
        }
        g.setColor(choosecolor);
        {
            if (mode == 0) {
                if (y > 70) {
                    if (drawsize == 0)
                        g.drawLine(x, y, x1, y1);
                    else {
                        g.fillOval(x1, y1, drawsize, drawsize);
                    }
                }
            } else if (mode == 1) {

                if (drawsize == 0)
                    g.fillRect(x1, y1, 10, 10);
                else {
                    g.fillRect(x1, y1, drawsize, drawsize);
                }
            }
            x = x1;
            y = y1;
        }
    }

    @Override
    public void mouseMoved(MouseEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void mouseClicked(MouseEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void mousePressed(MouseEvent e) {
        // TODO Auto-generated method stub
        x = e.getX();
        y = e.getY();
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void mouseEntered(MouseEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void mouseExited(MouseEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void windowOpened(WindowEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void windowClosing(WindowEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void windowClosed(WindowEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void windowIconified(WindowEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void windowDeiconified(WindowEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void windowActivated(WindowEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void windowDeactivated(WindowEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == color) {
            Color newColor = JColorChooser.showDialog(s1091436.this,
                    "choosecolor", choosecolor);
            if (newColor != null) {
                choosecolor = newColor;
            }

        } else if (e.getSource() == draw) {
            choosecolor = memcolor;
            mode = 0;
        } else if (e.getSource() == erase) {
            mode = 1;
            memcolor = choosecolor;
            choosecolor = new Color(255, 255, 255);
        } else if (e.getSource() == size) {
            if (drawsize == 0) {
                size.setText("middle");
                drawsize = 10;
            } else if (drawsize == 10) {
                size.setText("big");
                drawsize = 20;
            } else if (drawsize == 20) {
                size.setText("very big");
                drawsize = 30;
            } else if (drawsize == 30) {
                size.setText("small");
                drawsize = 0;
            }
        } else if (e.getSource() == clear) {
            mode = 2;
            memcolor = choosecolor;
            Graphics g = frm.getGraphics();
            g.setColor(new Color(255, 255, 255));
            g.fillRect(0, 65, getWidth(), getHeight() - 70);
            mode = 0;
            choosecolor = memcolor;
        }

    }
}
