package project4;

public class BSTTest {

	public static void main(String[] args) {
		
		Dictionary<Integer, String> bst = new BST<>();
		bst.insert(50, "I");
		bst.insert(25, "M");
		bst.insert(75, "Y");
		bst.insert(11, "M");
		bst.insert(30, "I");
		bst.insert(60, "N");
		bst.insert(90, "Q");
		bst.insert(5, "E");
		bst.insert(27, "G");
		bst.insert(20, "O");
		bst.insert(80, "E");
		bst.inorder();
		System.out.println("Size    : " + bst.size());
		System.out.println("Find 90 : " + bst.find(90));
		
		bst.remove(90);
		System.out.println("=====After Remove 90=====");
		System.out.print("Inorder : ");
		bst.inorder();
		System.out.println("Size    : " + bst.size());
		System.out.println("Find 90 : " + bst.find(90));
		
		bst.removeAny();
		System.out.println("=====After RemoveAny=====");
		System.out.print("Inorder : ");
		bst.inorder();
		System.out.println("Size    : " + bst.size());
		
		bst.clear();
		System.out.println("=======After Clear=======");
		System.out.print("Inorder : ");
		bst.inorder();
		System.out.println("Size    : " + bst.size());	}
}