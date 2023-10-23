import java.io.*;
import java.io.File;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Timer;
import java.util.TimerTask;

public class test extends JFrame implements ActionListener, WindowListener, MouseListener, MouseMotionListener {
    static test frm = new test();
    static test frm1 = new test();
    static test frm2 = new test();
    static test frm3 = new test();
    static test frm4 = new test();
    static test frm5 = new test();
    static test frm6 = new test();
    static JButton txa1 = new JButton("time");
	static JButton txa2 = new JButton("time");
	static JButton txa3 = new JButton("time");
	static JButton txa4 = new JButton("time");
	static JButton txa5 = new JButton("time");
    static JTextArea text1= new JTextArea("有一個人在沙漠中，頭朝下死了，身邊散落著幾個行李箱子，而這個人手裏緊緊地抓著半個火柴，推理這個人是怎麼死的？");
    static JTextArea tips1= new JTextArea("頭朝下");
    static JTextArea tips2= new JTextArea("半個火柴");
    static JTextArea tips3= new JTextArea("數個行李箱子");
    static JTextArea tips4= new JTextArea("抽籤");
    static JTextArea ans= new JTextArea("他和夥伴一起乘熱氣球，途中出了故障，必須減輕分量，於是大家抽簽決定由誰做出犧牲，跳下熱氣球。此人不幸抽中不祥的半跟火柴，連同行李一起被人扔下熱氣球。");
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
    static JFrame jframe = new JFrame();
    static JLabel jLabel = new JLabel();
    static Timer timer1 = new Timer();
    static Timer timer2 = new Timer();
    static Timer timer3 = new Timer();
    static Timer timer4 = new Timer();
    static Timer timer5 = new Timer();
    static int i = 30;
    static int big = 20;
    static int key = 0;
    static int time1 = 30;
	static int time2 = 30;
	static int time3 = 30;
	static int time4 = 40;
	static int time5 = 70;
    public static void main(String[] args) {
        text1.setLineWrap(true);
        frm6.setBounds(100, 100, 500, 400);
        // text1.setFont(font1);
        frm6.add(text1);
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
        frm6.setVisible(true);
        frm6.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
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
                frm1.add(txa1);
                txa1.setText("Time left: " + 30);
                frm1.addMouseListener(this);
                frm1.addMouseMotionListener(this);
                frm1.getLayeredPane().setLayout(null);
                frm1.getLayeredPane().add(back);
                frm1.setSize(background.getIconWidth(), background.getIconHeight());
                frm1.setResizable(false);
                frm1.setVisible(true);
                open = false;
				timer1.scheduleAtFixedRate(new TimerTask() {
                    public void run() {
                        if (touch) {
                            txa1.setText("Time left: " + time1);
                            time1--;
                            if (time1 < 0 && touch) {
                                JFrame newfork = new JFrame();
                                JOptionPane.showMessageDialog(newfork, "YOU DIE!!");
                                touch = false;
                                reset();
                                time1 = 30;
								return;
                            }
                        }
                    }
                }, 0, 1000);
            } else {
                JFrame fork = new JFrame();
                JOptionPane.showMessageDialog(fork, "Had opening other game!!");
            }
        }
        if (e.getSource() == level2) {
            if (open) {
                timer1.cancel();
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
                frm2.add(txa2);
                txa2.setText("Time left: " + 30);
                frm2.addMouseMotionListener(this);
                frm2.getLayeredPane().setLayout(null);
                frm2.getLayeredPane().add(back);
                frm2.setSize(background.getIconWidth(), background.getIconHeight());
                frm2.setResizable(false);
                frm2.setVisible(true);
                open = false;
				timer2.scheduleAtFixedRate(new TimerTask() {
                    public void run() {
                        if (touch) {
                            txa2.setText("Time left: " + time2);
                            time2--;
                            if (time2 < 0 && touch) {
                                JFrame newfork = new JFrame();
                                JOptionPane.showMessageDialog(newfork, "YOU DIE!!");
                                touch = false;
                                reset();
                                time2 = 30;
								return;
                            }
                        }
                    }
                }, 0, 1000);
            } else {
                JFrame fork = new JFrame();
                JOptionPane.showMessageDialog(fork, "Had opening other game!!");
            }
        }
        if (e.getSource() == level3) {
            if (open) {
                timer2.cancel();
                level = 3;
                file = new File("level3.png");
                background = new ImageIcon("level3.png");
                JLabel back = new JLabel(background);
                back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
                imagePanel = (JPanel) frm3.getContentPane();
                imagePanel.setOpaque(false);
                imagePanel.setLayout(new FlowLayout());
                frm3.add(txa3);
                txa3.setText("Time left: " + 30);
                frm3.addWindowListener(this);
                frm3.addMouseListener(this);
                frm3.addMouseMotionListener(this);
                frm3.getLayeredPane().setLayout(null);
                frm3.getLayeredPane().add(back);
                frm3.setSize(background.getIconWidth(), background.getIconHeight());
                frm3.setResizable(false);
                frm3.setVisible(true);
                open = false;
				timer3.scheduleAtFixedRate(new TimerTask() {
                    public void run() {
                        if (touch) {
                            txa3.setText("Time left: " + time3);
                            time3--;
                            if (time3 < 0 && touch) {
                                JFrame newfork = new JFrame();
                                JOptionPane.showMessageDialog(newfork, "YOU DIE!!");
                                touch = false;
                                reset();
                                time3 = 30;
								return;
                            }
                        }
                    }
                }, 0, 1000);
            } else {
                JFrame fork = new JFrame();
                JOptionPane.showMessageDialog(fork, "Had opening other game!!");
            }
        }
        if (e.getSource() == level4) {
            if (open) {
                timer3.cancel();
                level = 4;
                file = new File("level4.png");
                background = new ImageIcon("level4.png");
                JLabel back = new JLabel(background);
                back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
                imagePanel = (JPanel) frm4.getContentPane();
                imagePanel.setOpaque(false);
                imagePanel.setLayout(new FlowLayout());
                frm4.add(txa4);
                txa4.setText("Time left: " + 40);
                frm4.addWindowListener(this);
                frm4.addMouseListener(this);
                frm4.addMouseMotionListener(this);
                frm4.getLayeredPane().setLayout(null);
                frm4.getLayeredPane().add(back);
                frm4.setSize(background.getIconWidth(), background.getIconHeight());
                frm4.setResizable(false);
                frm4.setVisible(true);
                open = false;
				timer4.scheduleAtFixedRate(new TimerTask() {
                    public void run() {
                        if (touch) {
                            txa4.setText("Time left: " + time4);
                            time4--;
                            if (time4 < 0 && touch) {
                                JFrame newfork = new JFrame();
                                JOptionPane.showMessageDialog(newfork, "YOU DIE!!");
                                touch = false;
                                reset();
                                time4 = 40;
								return;
                            }
                        }
                    }
                }, 0, 1000);
            } else {
                JFrame fork = new JFrame();
                JOptionPane.showMessageDialog(fork, "Had opening other game!!");
            }
        }
        if (e.getSource() == level5) {
            if (open) {
                timer4.cancel();
                level = 5;
                file = new File("level5.png");
                background = new ImageIcon("level5.png");
                JLabel back = new JLabel(background);
                back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
                imagePanel = (JPanel) frm5.getContentPane();
                imagePanel.setOpaque(false);
                imagePanel.setLayout(new FlowLayout());
                frm5.add(txa5);
                txa5.setText("Time left: " + 50);
                frm5.addWindowListener(this);
                frm5.addMouseListener(this);
                frm5.addMouseMotionListener(this);
                frm5.getLayeredPane().setLayout(null);
                frm5.getLayeredPane().add(back);
                frm5.setSize(background.getIconWidth() + 10, background.getIconHeight() + 10);
                frm5.setResizable(false);
                frm5.setVisible(true);
                open = false;
				timer5.scheduleAtFixedRate(new TimerTask() {
                    public void run() {
                        if (touch) {
                            txa5.setText("Time left: " + time5);
                            time5--;
                            if (time5 < 0 && touch) {
                                JFrame newfork = new JFrame();
                                JOptionPane.showMessageDialog(newfork, "YOU DIE!!");
                                touch = false;
                                reset();
                                time5 = 70;
								return;
                            }
                        }
                    }
                }, 0, 1000);
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
        key = 0;
        big = 20;
        x = e.getX();
        y = e.getY();
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
                txa1.setText("Time left: " + 30);
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
            g.fillRect(x - 20, y - 10, big, big);
            g.setColor(Color.red);
            g.fillOval(x, y, big, big);

        }
    
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
            int pixel2 = 0;
            BufferedImage image;
            Color color = new Color(0, 255, 255);
            try {
                image = ImageIO.read(file);
                pixel = image.getRGB(x, y);
                pixel2 = image.getRGB(x + big / 2, y + big / 2);
                color = new Color(pixel, true);
            } catch (IOException e1) {
            }
            if (pixel == -16777216 || pixel2 == -16777216) {
                JFrame newfork = new JFrame();
                JOptionPane.showMessageDialog(newfork, "YOU DIE!!");
                touch = false;
                reset();

            } else if (pixel == -32985 || pixel2 == -32985) {
                if (level == 5) {
                    File imgFile = new File("gs2.png");
                    ImageIcon background1 = new ImageIcon("gs2.png");
                    JLabel back1 = new JLabel(background1);
                    JFrame jframe1 = new JFrame();
                    Frame frametips = new Frame();
                    frametips.setBounds(100, 100, 200, 200);
                    frametips.add(ans);
                    frametips.setVisible(true);
                    frametips.addWindowListener(new WindowAdapter() {
                        public void windowClosing(WindowEvent e) {
                            frametips.dispose();

                        }
                    });
                    text1.append("\n他和夥伴一起乘熱氣球，途中出了故障，必須減輕分量，於是大家抽簽決定由誰做出犧牲，跳下熱氣球。此人不幸抽中不祥的半跟火柴，連同行李一起被人扔下熱氣球。\n");
                    jframe1.add(back1);
                    jframe1.setSize(background1.getIconWidth(), background1.getIconHeight());
                    jframe1.setVisible(true);
                    back1.setBounds(0, 0, background1.getIconWidth(), background1.getIconHeight() - 50);
                    imagePanel = (JPanel) frm1.getContentPane();
                    imagePanel.setOpaque(false);
                    imagePanel.setLayout(new FlowLayout());
                }
                Frame newfork = new JFrame();
				if (level == 1) {
                    Frame frametips = new Frame();
                    frametips.setBounds(100, 100, 200, 200);
                    frametips.add(tips1);
                    frametips.setVisible(true);
                    text1.append("\ntips1");
                    text1.append("\n頭朝下\n");
                    frametips.addWindowListener(new WindowAdapter() {
                        public void windowClosing(WindowEvent e) {
                            frametips.dispose();

                        }
					});

				}
                else if (level == 2) {
                    Frame frametips = new Frame();
                    frametips.setBounds(100, 100, 200, 200);
                    frametips.add(tips2);
                    frametips.setVisible(true);
                    text1.append("\ntips2");
                    text1.append("\n半個火柴\n");
                    frametips.addWindowListener(new WindowAdapter() {
                        public void windowClosing(WindowEvent e) {
                            frametips.dispose();

                        }
                    });

                } else if (level == 3) {
                    Frame frametips = new Frame();
                    frametips.setBounds(100, 100, 200, 200);
                    frametips.add(tips2);
                    frametips.setVisible(true);
                     text1.append("\ntips3");
                    text1.append("\n數個行李箱子\n");
                    frametips.addWindowListener(new WindowAdapter() {
                        public void windowClosing(WindowEvent e) {
                            frametips.dispose();

                        }
                    });

                } else if (level == 4) {
                    Frame frametips = new Frame();
                    frametips.setBounds(100, 100, 200, 200);
                    frametips.add(tips4);
                    frametips.setVisible(true);
                     text1.append("\ntips4");
                    text1.append("\n他與夥伴在空中，並抽籤\n");
                    frametips.addWindowListener(new WindowAdapter() {
                        public void windowClosing(WindowEvent e) {
                            frametips.dispose();

                        }
                    });

                }
                JOptionPane.showMessageDialog(newfork, "YOU WIN!!");
                touch = false;
                reset();
            } else if (pixel == -256 || pixel2 == -256) {
                if(level==1)
					time1 += 1;
				if(level==2)
					time2 += 1;
				if(level==3)
					time3 += 1;
				if(level==4)
					time4 += 1;
				if(level==5)
					time5 += 1;
                g.setColor(new Color(0, 255, 255));
                g.fillOval(x, y, big, big);
                g.setColor(Color.red);
                g.fillOval(e.getX(), e.getY(), big, big);
                x = e.getX();
                y = e.getY();
            } else if (pixel == -15806139 || pixel2 == -15806139) {
                if(level==1)
					time1 -= 1;
				if(level==2)
					time2 -= 1;
				if(level==3)
					time3 -= 1;
				if(level==4)
					time4 -= 1;
				if(level==5)
					time5 -= 1;
                g.setColor(new Color(0, 255, 255));
                g.fillOval(x, y, big, big);
                g.setColor(Color.red);
                g.fillOval(e.getX(), e.getY(), big, big);
                x = e.getX();
                y = e.getY();
            } else if ((pixel == -20792 || pixel2 == -20792) && key == 0) {
                JFrame newfork = new JFrame();
                JOptionPane.showMessageDialog(newfork, "YOU DIE!!");
                touch = false;
                reset();
            } else if (pixel == -7864293 || pixel2 == -7864293) {
                big = 10;
                g.setColor(new Color(0, 255, 255));
                g.fillOval(x, y, big, big);
                g.setColor(Color.red);
                g.fillOval(e.getX(), e.getY(), big, big);
                x = e.getX();
                y = e.getY();
            } else if (pixel == -136026 || pixel2 == -136026) {
                key = 1;
                g.setColor(new Color(0, 255, 255));
                g.fillOval(x, y, big, big);
                g.setColor(Color.red);
                g.fillOval(e.getX(), e.getY(), big, big);
                x = e.getX();
                y = e.getY();
            } else {
                g.setColor(new Color(0, 255, 255));
                g.fillOval(x, y, big, big);
                g.setColor(Color.red);
                g.fillOval(e.getX(), e.getY(), big, big);
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
            time4 = 30;
            txa1.setText("Time left: " + 30);
        } else if (level == 2) {
            file = new File("level2.png");
            background = new ImageIcon("level2.png");
            JLabel back = new JLabel(background);
            back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
            frm2.getLayeredPane().add(back);
            time5 = 30;
            txa2.setText("Time left: " + 30);
        } else if (level == 3) {
            file = new File("level3.png");
            background = new ImageIcon("level3.png");
            JLabel back = new JLabel(background);
            back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
            frm3.getLayeredPane().add(back);
            time3 = 30;
            txa3.setText("Time left: " + 30);
        } else if (level == 4) {
            file = new File("level4.png");
            background = new ImageIcon("level4.png");
            JLabel back = new JLabel(background);
            back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
            frm4.getLayeredPane().add(back);
            time4 = 40;
            txa4.setText("Time left: " + 40);
        } else {
            file = new File("level5.png");
            background = new ImageIcon("level5.png");
            JLabel back = new JLabel(background);
            back.setBounds(0, 0, background.getIconWidth(), background.getIconHeight() - 50);
            frm5.getLayeredPane().add(back);
            time5 = 70;
            txa5.setText("Time left: " + 70);
        }
    }
}
