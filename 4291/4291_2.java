import java.util.*;
import java.util.Map.Entry;

public class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		ArrayList<String> array = new ArrayList<String>();
		Map<String, Integer> map = new HashMap<String, Integer>();
		String line;
		while(!"".equals(line = scanner.nextLine())) {
			array.add(line);
		}
		for(String str : array){
			String[] strArray = str.split("\\s+");
			StringBuilder builder = new StringBuilder();
			for(int i=0; i<strArray.length; ++i){
				String temp = strArray[i];
				strArray[i] = temp.substring(temp.lastIndexOf("\\")+1, temp.length());
				if(i==0 && strArray[i].length()>=16){
					strArray[i] = strArray[i].substring(strArray[i].length()-16, strArray[i].length());
				}
				builder.append(strArray[i]);
				if(i!=strArray.length-1){
					builder.append(" ");
				}
			}
			String newStr = builder.toString();
			if(map.containsKey(newStr)){
				int num = map.get(newStr);
				num++;
				map.remove(newStr);
				map.put(newStr, num);
			} else {
				map.put(newStr, 1);
			}
		}
		Set<Entry<String, Integer>> entrySet = map.entrySet();
		Iterator<Entry<String, Integer>> ite = entrySet.iterator();
		int count = 0;
		while(ite.hasNext()&&count<8){
			Map.Entry<String, Integer> entry = (Map.Entry<String, Integer>) ite.next();
			System.out.println(entry.getKey()+" "+entry.getValue());
			count++;
		}
		scanner.close();
	}
}