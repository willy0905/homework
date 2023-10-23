import java.io.*;
import java.io.File;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class test extends JFrame implements ActionListener, WindowListener, MouseListener, MouseMotionListener {
    static test frm = new test();
    static test frm1 = new test();
    static test frm2 = new test();
    static test frm3 = new test();
    static test frm4 = new test();
    static test frm5 = new test();
    static JButton level1 = new JButton("level1");
    static JButton level2 = new JButton("level2");
    static JButton level3 = new JButton("level3");
    static JButton level4 = new JButton("level4");
    static JButton level5 = new JButton("level5");
    static int x = 0, y = 0, x1 = 0, y1 = 0;
    static boolean open = true;
    static File file;
    static boolean touch = false;
    static int level = 0;
    static JPanel imagePanel;
    static ImageIcon background;

    public static void main(String[] args) {
        frm.setBounds(0, 0, 400, 300);
        frm.setLayout(new GridLayout(1, 5, 5, 5));
        frm.add(level1);
        frm.add(level2);
        frm.add(level3);
        frm.add(level4);
        frm.add(level5);
        level1.addActionListener(frm);
        level2.addActionListener(frm);
        level3.addActionListener(frm);
        level4.addActionListener(frm);
        level5.addActionListener(frm);
        frm.setVisible(true);
        frm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == level1) {
            if (open) {
                level = 1;
                file = new File("level1.png");
                background = new ImageIcon("level1.png");
                JLabel back = new JLabel(background);
                back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
                imagePanel = (JPanel) frm1.getContentPane();
                imagePanel.setOpaque(false);
                imagePanel.setLayout(new FlowLayout());
                frm1.addWindowListener(this);
                frm1.addMouseListener(this);
                frm1.addMouseMotionListener(this);
                frm1.getLayeredPane().setLayout(null);
                frm1.getLayeredPane().add(back);
                frm1.setSize(background.getIconWidth(), background.getIconHeight());
                frm1.setResizable(false);
                frm1.setVisible(true);
                open = false;
            } else {
                JFrame fork = new JFrame();
                JOptionPane.showMessageDialog(fork, "Had opening other game!!");
            }
        }
        if (e.getSource() == level2) {
            if (open) {
                level = 2;
                file = new File("level2.png");
                background = new ImageIcon("level2.png");
                JLabel back = new JLabel(background);
                back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
                imagePanel = (JPanel) frm2.getContentPane();
                imagePanel.setOpaque(false);
                imagePanel.setLayout(new FlowLayout());
                frm2.addWindowListener(this);
                frm2.addMouseListener(this);
                frm2.addMouseMotionListener(this);
                frm2.getLayeredPane().setLayout(null);
                frm2.getLayeredPane().add(back);
                frm2.setSize(background.getIconWidth(), background.getIconHeight());
                frm2.setResizable(false);
                frm2.setVisible(true);
                open = false;
            } else {
                JFrame fork = new JFrame();
                JOptionPane.showMessageDialog(fork, "Had opening other game!!");
            }
        }
        if (e.getSource() == level3) {
            if (open) {
                level = 3;
                file = new File("level3.png");
                background = new ImageIcon("level3.png");
                JLabel back = new JLabel(background);
                back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
                imagePanel = (JPanel) frm3.getContentPane();
                imagePanel.setOpaque(false);
                imagePanel.setLayout(new FlowLayout());
                frm3.addWindowListener(this);
                frm3.addMouseListener(this);
                frm3.addMouseMotionListener(this);
                frm3.getLayeredPane().setLayout(null);
                frm3.getLayeredPane().add(back);
                frm3.setSize(background.getIconWidth(), background.getIconHeight());
                frm3.setResizable(false);
                frm3.setVisible(true);
                open = false;
            } else {
                JFrame fork = new JFrame();
                JOptionPane.showMessageDialog(fork, "Had opening other game!!");
            }
        }
        if (e.getSource() == level4) {
            if (open) {
                level = 4;
                file = new File("level4.png");
                background = new ImageIcon("level4.png");
                JLabel back = new JLabel(background);
                back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
                imagePanel = (JPanel) frm4.getContentPane();
                imagePanel.setOpaque(false);
                imagePanel.setLayout(new FlowLayout());
                frm4.addWindowListener(this);
                frm4.addMouseListener(this);
                frm4.addMouseMotionListener(this);
                frm4.getLayeredPane().setLayout(null);
                frm4.getLayeredPane().add(back);
                frm4.setSize(background.getIconWidth(), background.getIconHeight());
                frm4.setResizable(false);
                frm4.setVisible(true);
                open = false;
            } else {
                JFrame fork = new JFrame();
                JOptionPane.showMessageDialog(fork, "Had opening other game!!");
            }
        }
        if (e.getSource() == level5) {
            if (open) {
                level = 5;
                file = new File("level5.png");
                background = new ImageIcon("level5.png");
                JLabel back = new JLabel(background);
                back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
                imagePanel = (JPanel) frm5.getContentPane();
                imagePanel.setOpaque(false);
                imagePanel.setLayout(new FlowLayout());
                frm5.addWindowListener(this);
                frm5.addMouseListener(this);
                frm5.addMouseMotionListener(this);
                frm5.getLayeredPane().setLayout(null);
                frm5.getLayeredPane().add(back);
                frm5.setSize(background.getIconWidth() + 10, background.getIconHeight() + 10);
                frm5.setResizable(false);
                frm5.setVisible(true);
                open = false;
            } else {
                JFrame fork = new JFrame();
                JOptionPane.showMessageDialog(fork, "Had opening other game!!");
            }
        }
    }

    @Override
    public void windowOpened(WindowEvent e) {
    }

    @Override
    public void windowClosing(WindowEvent e) {
        open = true;
    }

    @Override
    public void windowClosed(WindowEvent e) {
        open = true;
    }

    @Override
    public void windowIconified(WindowEvent e) {
    }

    @Override
    public void windowDeiconified(WindowEvent e) {
    }

    @Override
    public void windowActivated(WindowEvent e) {
    }

    @Override
    public void windowDeactivated(WindowEvent e) {
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        x = e.getX();
        y = e.getY();
        System.out.println(x + " " + y);
        BufferedImage image;
        int pixel = 0;
        Color color = new Color(0, 255, 255);
        try {
            image = ImageIO.read(file);
            pixel = image.getRGB(x - 10, y);
            color = new Color(pixel, true);
        } catch (IOException e1) {
        }
        if (pixel == -65281) {
            touch = true;
            Graphics g;
            if (level == 1) {
                g = frm1.getGraphics();
            } else if (level == 2) {
                g = frm2.getGraphics();
            } else if (level == 3) {
                g = frm3.getGraphics();
            } else if (level == 4) {
                g = frm4.getGraphics();
            } else {
                g = frm5.getGraphics();
            }
            g.setColor(new Color(0, 255, 255));
            g.fillRect(x - 20, y - 10, 30, 30);
            g.setColor(Color.red);
            g.fillOval(x, y, 15, 15);

        }
        System.out.println(pixel);
    }

    @Override
    public void mousePressed(MouseEvent e) {

    }

    @Override
    public void mouseReleased(MouseEvent e) {
    }

    @Override
    public void mouseEntered(MouseEvent e) {
    }

    @Override
    public void mouseExited(MouseEvent e) {
    }

    @Override
    public void mouseDragged(MouseEvent e) {

    }

    @Override
    public void mouseMoved(MouseEvent e) {
        if (touch) {
            Graphics g;
            if (level == 1) {
                g = frm1.getGraphics();
            } else if (level == 2) {
                g = frm2.getGraphics();
            } else if (level == 3) {
                g = frm3.getGraphics();
            } else if (level == 4) {
                g = frm4.getGraphics();
            } else {
                g = frm5.getGraphics();
            }
            int pixel = 0;
            BufferedImage image;
            Color color = new Color(0, 255, 255);
            try {
                image = ImageIO.read(file);
                pixel = image.getRGB(x, y);
                color = new Color(pixel, true);
            } catch (IOException e1) {
            }

            if (pixel == -16777216) {
                JFrame newfork = new JFrame();
                JOptionPane.showMessageDialog(newfork, "YOU DIE!!");
                touch = false;
                reset();
            } else if (pixel == 0) {

            }
        } else {
            g.setColor(new Color(0, 255, 255));
            g.fillOval(x, y, 15, 15);
            g.setColor(Color.red);
            g.fillOval(e.getX(), e.getY(), 15, 15);
            x = e.getX();
            y = e.getY();
        }
    }

    }

    public void reset() {
        if (level == 1) {
            file = new File("level1.png");
            background = new ImageIcon("level1.png");
            JLabel back = new JLabel(background);
            back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
            frm1.getLayeredPane().add(back);
        } else if (level == 2) {
            file = new File("level2.png");
            background = new ImageIcon("level2.png");
            JLabel back = new JLabel(background);
            back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
            frm2.getLayeredPane().add(back);
        } else if (level == 3) {
            file = new File("level3.png");
            background = new ImageIcon("level3.png");
            JLabel back = new JLabel(background);
            back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
            frm3.getLayeredPane().add(back);
        } else if (level == 4) {
            file = new File("level4.png");
            background = new ImageIcon("level4.png");
            JLabel back = new JLabel(background);
            back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
            frm4.getLayeredPane().add(back);
        } else {
            file = new File("level5.png");
            background = new ImageIcon("level5.png");
            JLabel back = new JLabel(background);
            back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
            frm5.getLayeredPane().add(back);
        }
    }
}
