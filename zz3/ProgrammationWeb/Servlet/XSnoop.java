import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class XSnoop extends HttpServlet {

    static Connection link;
    static String myURL = "jdbc:odbc:source";

	/*	***************************	*/
	/*	CONNECTING TO THE DATA BASE	*/
	/*	***************************	*/
    
    public static void connect() {
    	try {
    		DriverManager.registerDriver(new sun.jdbc.odbc.JdbcOdbcDriver());
    		link = DriverManager.getConnection(myURL);
    	} catch (SQLException e) {
    		System.out.println("Connection failure: " + e.getMessage());
    	}
    }

	/*	*******************************	*/
	/*	CATCHING THE HTTP POST REQUEST	*/
	/*	*******************************	*/
    
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    	Statement question;
    	String query;
    	ResultSet answer;
    	connect();
    	try {
			query = "SELECT * FROM PILOT WHERE Address ='" + request.getParameter("city") + "'";
			question = link.createStatement();
			answer = question.executeQuery(query);
			PrintWriter pen;
			response.setContentType("text/html");
			pen = response.getWriter();
			pen.println("<HTML>");
			pen.println("<HEAD> <TITLE> Answer </TITLE> </HEAD>");
			pen.println("<BODY>");
			while (answer.next()) {
				String pN = answer.getString("PilotNumber");
				String lN = answer.getString("LastName");
				String fN = answer.getString("FirstName");
				String ad = answer.getString("Address");
				float sa = answer.getFloat("Salary");
				float pr = answer.getFloat("Premium");
				Date hD = answer.getDate("HiringDate");
				if (answer.wasNull() == false) {
					pen.println("<P><B> Pilot : </B>" + lN + " " + fN);
					pen.println("<P><B> ---Reference : </B>" + pN);
					pen.println("<P><B> ---Address : </B>" + ad);
					pen.println("<P><B> ---Salary : </B>" + sa);
					pen.println("<P><B> ---since : </B>" + hD);
					if (pr > 0 ) pen.println("<P><B> ---Premium : </B>" + pr);
					else pen.println("<P><B> ---No premium </B>");
				}
			}
			pen.println("</BODY>");
			pen.println("</HTML>");
			answer.close();
			question.close();
			link.close();
    	} catch (SQLException e) {
    		System.out.println("Connection error: " + e.getMessage());
    	}
    }

	/*	*******************************	*/
	/*	CATCHING THE HTTP GET REQUEST	*/
	/*	*******************************	*/
    
    public void doGet(HttpServletRequest requete, HttpServletResponse reponse) throws ServletException, IOException {
    	doPost(requete,reponse);
    }

	/*	*******************	*/
	/*	SERVLET DESTRUCTOR	*/
	/*	*******************	*/
    
    public void destroy() {
		super.destroy();
		try { link.close();
		} catch (Exception e) {
			System.err.println(e.getMessage());
		}
    }
}