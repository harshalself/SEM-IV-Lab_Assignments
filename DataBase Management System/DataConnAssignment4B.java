package demo;
import java.sql.*;
public class DataConn {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{ 
		Class.forName("oracle.jdbc.driver.OracleDriver");  
		  
		//step2 create  the connection object  
		Connection con=DriverManager.getConnection(  
		"jdbc:oracle:thin:@localhost:1521:xe","system","system");  
		  
		 String sql = "insert into  fine values(43,'12-apr-24',452210)";
		//step3 create the statement object  
		 PreparedStatement ps = null;
		 ps = con.prepareStatement(sql);
		 ps.execute();
		Statement stmt=con.createStatement();  
		  
		//step4 execute query  
		ResultSet rs=stmt.executeQuery("select * from fine");  
		while(rs.next())  
		System.out.println(rs.getInt(1)+"  "+rs.getString(2)+"  "+rs.getInt(3));  
		  
		//step5 close the connection object  
		con.close();  
		  
		}catch(Exception e){ System.out.println(e);}  
		  
		 
	}

}