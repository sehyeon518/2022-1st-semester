package project3;
/* preorder, inorder, postorder traversal을 수행하는 함수를 구현하고,
   함수를 수행한 결과를 확인하세요.
*/
public class Task4 {
	public static void main(String[] args) {
		BinNode<String> d = new INode<>("D", null, null);
		BinNode<String> g = new INode<>("G", null, null);
		BinNode<String> h = new INode<>("H", null, null);
		BinNode<String> i = new INode<>("I", null, null);
		
		BinNode<String> b = new INode<>("B", null, d);
		BinNode<String> e = new INode<>("E", g, null);
		BinNode<String> f = new INode<>("F", h, i);
			
		BinNode<String> c = new INode<>("C", e, f);
	
		BinNode<String> a = new INode<>("A", b, c);
							   
		System.out.println("===Task4 preorder===");
		preorder(a);
		System.out.println();
		System.out.println("====Task4inorder====");
		inorder(a);
		System.out.println();
		System.out.println("===Task4postorder===");
		postorder(a);
		}

	static public <E> void preorder(BinNode<E> rt) {
		if (rt==null) return;
		System.out.print(rt.element() + " "); // visit
		preorder(rt.left());
		preorder(rt.right());
	}
	static public <E> void inorder(BinNode<E> rt) {
		if (rt==null) return;
		inorder(rt.left());
		System.out.print(rt.element() + " "); // visit
		inorder(rt.right());
	}
	static public <E> void postorder(BinNode<E> rt) {
		if (rt==null) return;
		postorder(rt.left());
		postorder(rt.right());
		System.out.print(rt.element() + " "); // visit
	}
}