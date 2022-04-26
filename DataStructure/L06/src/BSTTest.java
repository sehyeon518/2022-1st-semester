
public class BSTTest {

	public static void main(String[] args) {
		
		Dictionary<Integer, String> bst = new BST();
		bst.insert(11, "a");
		bst.insert(3, "b");
		bst.insert(5, "c");
		bst.insert(2, "d");
		
		System.out.println(bst.find(11));
		System.out.println(bst.find(5));
		System.out.println(bst.find(3));
		System.out.println(bst.find(2));
		System.out.println(bst.find(10));
	}

}
