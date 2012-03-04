import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.Reader;
import java.io.Writer;
import java.net.HttpURLConnection;
import java.net.ProtocolException;
import java.net.URL;
import java.net.URLConnection;
public class postGet
{
	/**
	* Sends an HTTP GET request to a url
	*
	* @param endpoint - The URL of the server. (Example: " http://www.yahoo.com/search")
	* @param requestParameters - all the request parameters (Example: "param1=val1&param2=val2"). Note: This method will add the question mark (?) to the request - DO NOT add it yourself
	* @return - The response from the end point
	*/
	public static String sendGetRequest(String endpoint, String requestParameters){
		String result = null;
		if (endpoint.startsWith("http://")){
			// Send a GET request to the servlet
			try
			{
				// Send data
				String urlStr = endpoint;
				if (requestParameters != null && requestParameters.length () > 0)
				{
				urlStr += "?" + requestParameters;
				}
				URL url = new URL(urlStr);
				URLConnection conn = url.openConnection ();
				// Get the response
				BufferedReader rd = new BufferedReader(new InputStreamReader(conn.getInputStream()));
				StringBuffer sb = new StringBuffer();
				String line;
				while ((line = rd.readLine()) != null)
				{
				sb.append(line);
				}
				rd.close();
				result = sb.toString();
			} catch (Exception e){
				e.printStackTrace();
			}
		}
		return result;
	}
	/**
	* Reads data from the data reader and posts it to a server via POST request.
	* data - The data you want to send
	* endpoint - The server's address
	* output - writes the server's response to output
	* @throws Exception
	*/
	public static void postData(Reader data, URL endpoint, Writer output) throws Exception
	{
		HttpURLConnection urlc = null;
		try
		{
			urlc = (HttpURLConnection) endpoint.openConnection();
			try
			{
				urlc.setRequestMethod("POST");
			} catch (ProtocolException e){
				throw new Exception("Shouldn't happen: HttpURLConnection doesn't support POST??", e);
			}
			urlc.setDoOutput(true);
			urlc.setDoInput(true);
			urlc.setUseCaches(false);
			urlc.setAllowUserInteraction(false);
			urlc.setRequestProperty("Content-type", "text/xml; charset=" + "UTF-8");
			OutputStream out = urlc.getOutputStream();
			try
			{
				Writer writer = new OutputStreamWriter(out, "UTF-8");
				pipe(data, writer);
				writer.close();
			} catch (IOException e){
				throw new Exception("IOException while posting data", e);
			} finally{
				if (out != null)
				out.close();
			}
			InputStream in = urlc.getInputStream();
			try
			{
				Reader reader = new InputStreamReader(in);
				pipe(reader, output);
				reader.close();
			} catch (IOException e)
			{
				throw new Exception("IOException while reading response", e);
			} finally
			{
				if (in != null)
				in.close();
			}
		} catch (IOException e){
			throw new Exception("Connection error (is server running at " + endpoint + " ?): " + e);
		} finally
		{
			if (urlc != null)
			urlc.disconnect();
		}
	}
	/**
	* Pipes everything from the reader to the writer via a buffer
	*/
	private static void pipe(Reader reader, Writer writer) throws IOException
	{
		char[] buf = new char[1024];
		int read = 0;
		while ((read = reader.read(buf)) >= 0)
		{
			writer.write(buf, 0, read);
		}
		writer.flush();
	}
	public static void main(String args[]){
		String name = "ShadowLover";
		String API_Key = "27324DC2B00640FB";
		String RobotId = "604";
		
		sendGetRequest("http://bots.myrobots.com/update","key="+API_Key+"&field1=[1]"+"&field2=[2]"+"&field3=[3]"+"&field4=[4]");
		
	}
}
}