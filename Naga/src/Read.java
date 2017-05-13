import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class read {

    public static void main(String[] args) {        
        try {
            File f = new File("kepala_naga.txt");
            Scanner sc = new Scanner(f);

            
            while(sc.hasNextLine()){

                String line = sc.nextLine();
                if (line.equals("a")) {
                	System.out.println("");
	                System.out.println("glColor3f(1,0,0);");
  					System.out.println("glBegin(GL_POLYGON);");
	            }
	            else if (!line.equals("")){
	            	String[] details = line.split(",");
	                int x = Integer.parseInt(details[0]);
	                int y = 397 - Integer.parseInt(details[1]);
	                System.out.println("glVertex2f("+x+","+y+");");
	            }
	            else {
	            	System.out.println("glEnd();");	
	            }
                
			}

        } catch (FileNotFoundException e) {         
            e.printStackTrace();
        }
    }

    public void linear() {
    	try {
            File f = new File("kepala_naga.txt");
            Scanner sc = new Scanner(f);
            int x = 0;
            int y = 0;
            
            while(sc.hasNextLine()){

                String line = sc.nextLine();
            	System.out.println("");
                System.out.println("glColor3f(1,0,0);");
				System.out.println("glBegin(GL_POLYGON);");
            	String[] details = line.split(",");

            	for (int i = 0; i<details.length; i++) {
            		if (i%2==0) {
            			x = Integer.parseInt(details[0]);		
            		}
            		else {
            			y = 397 - Integer.parseInt(details[1]);
		                System.out.println("glVertex2f("+x+","+y+");");
		            	System.out.println("glEnd();");	   
            		}
            	}   
			}

        } catch (FileNotFoundException e) {         
            e.printStackTrace();
        }
    }

    public void pair() {
		try {
			File f = new File("kepala_naga.txt");
    		Scanner sc = new Scanner(f);
        
	    	while(sc.hasNextLine()){
            	int x=0;
            	int y=0;
                String line = sc.nextLine();
                System.out.println("glColor3f(1,0,0);");
				System.out.println("glBegin(GL_POLYGON);");
            	String[] details = line.split(",");
            	for (int i=0; i<details.length; i++) {
            		if ((i%2)==0) {
	                	x = Integer.parseInt(details[i]);
	            	}
	            	else {
	            		y = 397 - Integer.parseInt(details[i]);
	            		System.out.println("glVertex2f("+x+","+y+");");
	            	}
                	
            	}	
            	System.out.println("glEnd();");	
	            
                
			}
		} catch (FileNotFoundException e) {         
            e.printStackTrace();
        }
    }
}