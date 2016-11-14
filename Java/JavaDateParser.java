// Date Parser, 
// to convert the date like '[dd/MMM/yyyy:hh:mm:ss Z]' to data like 'yyyy/MM/ddThh:mm'
public static String parseDate(String s) {
	SimpleDateFormat oldFormat = new SimpleDateFormat(
			"[dd/MMM/yyyy:HH:mm:ssZ]");
	try {
		Date time = oldFormat.parse(s);
		SimpleDateFormat newFormat = new SimpleDateFormat(
				"yyyy-MM-dd'T'HH:mm");
		newFormat.setTimeZone(TimeZone.getTimeZone("GMT"));
		s = newFormat.format(time);
	} catch (ParseException e) {
		e.printStackTrace();
	}
	return s;
}