import java.util.*;
public class Main extends LinkedHashMap{
	private static final int MAX_ENTRIES = 8;
	protected boolean removeEldestEntry(Map.Entry eldest) {
		return size() > MAX_ENTRIES;
	}
	public static void main(String[] args){
		Scanner sca = new Scanner(System.in);
		LinkedHashMap<String, Integer> hs = new Main();
		int count = 0;
		int begin = 0, spaceStart, spaceEnd;
		String s;
		while (sca.hasNext()){
			StringBuffer sb = new StringBuffer(sca.nextLine());
			begin = sb.lastIndexOf("\\");
			spaceStart = sb.indexOf(" ");
			spaceEnd = sb.lastIndexOf(" ");
			sb.replace(spaceStart, spaceEnd, "");
			if((spaceStart - begin - 1) > 16)
				s = sb.substring(spaceStart -16);
			else
				s = sb.substring(begin + 1);
			if(!hs.containsKey(s))
				hs.put(s, new Integer(1));
			else{
				count = hs.get(s).intValue();
				count++;
				hs.put(s, new Integer(count));
			}
		}
		for(Map.Entry<String, Integer> me : hs.entrySet()){
			System.out.println(me.getKey() + " " + me.getValue().intValue());
		}
	}
}