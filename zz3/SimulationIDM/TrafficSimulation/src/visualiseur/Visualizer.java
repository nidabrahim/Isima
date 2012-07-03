package visualiseur;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.io.*;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import java.util.ArrayList;

public class Visualizer extends JFrame implements Runnable {

    private static final long serialVersionUID = 1L;
    // File chooser, used to select the file to run the simulation
    protected JFileChooser fileChooser_;
    // JLabel which contains the image of the traffic light
    protected JLabel image_;
    protected JLabel imageFeux1;
    protected JLabel imageFeux2;
    protected JLabel imageFeuxAuxilliaire1;
    protected JLabel imageFeuxAuxilliaire2;
    // Image of the traffic light off
    protected ImageIcon tf_off;
    // Image of the green traffic light
    protected ImageIcon tf_green;
    // Image of the orange traffic light
    protected ImageIcon tf_orange;
    // Image of the red traffic light
    protected ImageIcon tf_red;
    protected ImageIcon tf_carrefour;
    // Current time of the simulation
    protected double time;
    // Boolean which allows or not to run the visualization
    protected Boolean ready = false;
    // Buttons of control
    JButton run, quit;
    // List of the states and dates of times of the traffic light
    protected ArrayList<String[]> infos_;
    // Coefficient to change the speed of the visualization
    // The higher the faster
    int speed = 2;
    static Visualizer demo;

    // **********************************
    // Main method: just launches the GUI
    // **********************************
    public static void main(String args[]) {
        SwingUtilities.invokeLater(new Runnable() {

            public void run() {
                // A new instance of the visualization window is created...
                demo = new Visualizer();
                // ... and the window is made visible
                demo.setVisible(true);
            }
        });
    }

    // ***************************************
    // Constructor of the visualization window
    // ***************************************
    public Visualizer() {
        super();
        infos_ = new ArrayList<String[]>();		// This is the data list (simulation results)
        build();								// This calls for the building of the visualization window
    }

    // ************************************************************************
    // This method builds the windows and place the components in a flow layout
    // ************************************************************************
    protected void build() {
        // Create a file chooser
        fileChooser_ = new JFileChooser();

        this.setTitle("Demo TrafficLight"); // A title is given to the application
        this.setSize(600, 600);				// A size is defined for the application window
        this.setLocationRelativeTo(null);	// The window is centered in the screen
        this.setResizable(true);			// The window is allowed to be resized if needed

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        // This properly closes the application
        // if the window is closed

        // Let's create the menu bar and the menu of the GUI
        createMenu();

        // Let's add a "run" button to the GUI
        run = new JButton("run");
        JPanel panelBouton = new JPanel();
        panelBouton.setLayout(new FlowLayout());
        panelBouton.add(run);

        //add(panelRun);

        run.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                new Thread(demo).start();	// If the button is clicked, simulation visualization is launched
            }
        });

        // Let's also add an "exit" button to the GUI
        quit = new JButton("exit");


        panelBouton.add(quit);
        //add(panelQuit);
        quit.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                ready = false;
                System.exit(0);	// If the button is clicked, the application is exited
            }
        });

        // Let's load the traffic light images
        // created as image icons
        tf_off = createImageIcon("../images/tf_off.jpg", "traffic light off");
        tf_green = createImageIcon("../images/tf_green.jpg", "traffic light green");

        tf_orange = createImageIcon("../images/tf_orange.jpg", "traffic light orange");
        tf_red = createImageIcon("../images/tf_red.jpg", "traffic light red");

        tf_carrefour = createImageIcon("../images/Carrefour.jpg", "L'image de mon carrefour");

        // Let's initialize the current image and show it

        image_ = new JLabel("", tf_carrefour, JLabel.CENTER);
        imageFeux1 = new JLabel("", tf_off, JLabel.CENTER);
        imageFeux2 = new JLabel("", tf_off, JLabel.CENTER);
        imageFeuxAuxilliaire1 = new JLabel("", tf_off, JLabel.CENTER);
        imageFeuxAuxilliaire2 = new JLabel("", tf_off, JLabel.CENTER);

        //GridLayout layout = new GridLayout(2,2);

        setLayout(new BorderLayout());

        image_.setLayout(new GridLayout(2, 2));

        image_.add(imageFeux1);
        image_.add(imageFeuxAuxilliaire1);
        image_.add(imageFeuxAuxilliaire2);
        image_.add(imageFeux2);

        JPanel panelImage = new JPanel();
        panelImage.add(image_);

        this.add(panelImage);


        this.add(panelBouton, BorderLayout.PAGE_END);
    }
    /*    
    @Override
    public void paint(Graphics g)
    {
    super.paintComponents(g);
    g.drawImage(tf, 20, 20, this);
    }
     */
    // **********************************
    // Creates and returns an image icon,
    // or null if the path was invalid
    // **********************************

    protected static ImageIcon createImageIcon(String path, String description) {
        java.net.URL imgURL = Visualizer.class.getResource(path);
        if (imgURL != null) {
            return new ImageIcon(imgURL, description);
        } else {
            System.err.println("Couldn't find file: " + path);
            return null;
        }
    }

    // *********************************
    // Creates the menu bar and the menu
    // *********************************
    protected void createMenu() {
        // The menu bar's structure
        JMenuBar menuBar;	// Menu bar, used only once.
        JMenu menu;			// Menu, used for each main element of the menu bar
        JMenuItem menuItem; // Menu item, used for each item of a menu.

        // Create the menu bar.
        menuBar = new JMenuBar();

        // Build the "File" menu.
        menu = new JMenu("File");
        menuBar.add(menu);

        // Define the "Open" item in the "File" menu
        menuItem = new JMenuItem("Open");
        menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_O, ActionEvent.CTRL_MASK));
        menuItem.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent event) {
                File file = getDocument();		// This gets a document via a file chooser (dialog box)
                if (file != null) {
                    System.out.println("Open File : " + file.getName());
                    initSim(file);				// This initializes the data list from the document chosen

                }
            }
        });

        // Add the item to the menu, and the menu to the menu bar
        menu.add(menuItem);
        this.setJMenuBar(menuBar);
    }

    // **********************************
    // Gets a document via a file chooser
    // **********************************
    protected File getDocument() {
        File file = null;
        int returnVal = fileChooser_.showOpenDialog(this);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            file = fileChooser_.getSelectedFile();
        }
        return file;
    }

    // ********************************************
    // Initialize the data list from the file given
    // ********************************************
    protected void initSim(File file) {
        // Load the file
        FileInputStream fis = null;
        BufferedInputStream bis = null;
        DataInputStream dis = null;

        try {
            fis = new FileInputStream(file);
            // Here BufferedInputStream is added for fast reading
            bis = new BufferedInputStream(fis);
            dis = new DataInputStream(bis);
            // dis.available() returns 0 if the file does not have more lines
            while (dis.available() != 0) {
                String line = dis.readLine();
                String[] infos = line.split(" : ");
                infos_.add(infos);
            }
            // Dispose all the resources after using them
            fis.close();
            bis.close();
            dis.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        // Now the visualization is allowed
        ready = true;
    }

    // *********************************
    // Runs the simulation visualization
    // *********************************
    public void run() {
        int timeToSleep;
        double elapsed;

        if (ready) {
            time = 0.0;
            int size = infos_.size();

            for (int i = 0; i < size; ++i) {
                if (!ready) {
                    break;
                }
                // read next event time
                time = Double.parseDouble(infos_.get(i)[0]);

                // get the next image(color) of the traffic light
                String color = infos_.get(i)[1];

                if (color.compareTo("vert") == 0) {
                    imageFeux1.setIcon(tf_green);
                    imageFeux2.setIcon(tf_green);
                } else if (color.compareTo("orange") == 0) {
                    imageFeux1.setIcon(tf_orange);
                    imageFeux2.setIcon(tf_orange);
                } else if (color.compareTo("rouge") == 0) {
                    imageFeux1.setIcon(tf_red);
                    imageFeux2.setIcon(tf_red);
                } else if (color.compareTo("eteint") == 0) {
                    imageFeux1.setIcon(tf_off);
                    imageFeux2.setIcon(tf_off);
                } else if (color.compareTo("2vert") == 0) {
                    imageFeuxAuxilliaire1.setIcon(tf_green);
                    imageFeuxAuxilliaire2.setIcon(tf_green);
                } else if (color.compareTo("2orange") == 0) {
                    imageFeuxAuxilliaire1.setIcon(tf_orange);
                    imageFeuxAuxilliaire2.setIcon(tf_orange);
                } else if (color.compareTo("2rouge") == 0) {
                    imageFeuxAuxilliaire1.setIcon(tf_red);
                    imageFeuxAuxilliaire2.setIcon(tf_red);
                } else if (color.compareTo("2eteint") == 0) {
                    imageFeuxAuxilliaire1.setIcon(tf_off);
                    imageFeuxAuxilliaire2.setIcon(tf_off);
                }

                // the future is now: update the display consequently
                image_.paintImmediately(0, 0, image_.getWidth(), image_.getHeight());

                // stay in the current state for a time period according to simulation results
                timeToSleep = 0;
                elapsed = 0.0;
                if (i < size - 1) {
                    elapsed = Double.parseDouble(infos_.get(i + 1)[0]);
                    timeToSleep = (int) (elapsed - time) * 1000;
                }

                try {
                    Thread.sleep(timeToSleep / speed);
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }

                // update time display
                time += elapsed;
            }

        }
    }
}