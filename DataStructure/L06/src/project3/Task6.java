package project3;
/* task 3에서 구현한 tree에서 leaf node를 기존 INode에서 LNode로 교체하고,
   task 5를 수행하여 기존 결과와 동일함을 확인하세요.
 */
public class Task6 {
	public static void main(String[] args) {
		BinNode<String> h = new LNode<>("M");
		BinNode<String> i = new LNode<>("K");
		BinNode<String> j = new LNode<>("O");
		BinNode<String> k = new LNode<>("O");
		
		BinNode<String> f = new INode<>("I", h, i);
		BinNode<String> g = new INode<>("K", j, k);

		BinNode<String> d = new INode<>("R", f, g);
		BinNode<String> e = new LNode<>("M");
			
		BinNode<String> b = new INode<>("S", d, e);
		BinNode<String> c = new LNode<>("S");
			
		BinNode<String> a = new INode<>("O", b, c);
		
		System.out.println("========Task6========");
		inorder(a);
		System.out.println();
	}

	static public <E> void inorder(BinNode<E> rt) {
		if (rt==null) return;
		inorder(rt.left());
		System.out.print(rt.element() + " "); // visit
		inorder(rt.right());
	}
}