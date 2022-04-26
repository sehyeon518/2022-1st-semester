package project3;
/* 구현한 BinNode와 INode를 이용하여 본인이 좋아하는 10자 이상의 영어 단어 혹은 구의 글자들로 tree를 구성하세요.
   tree의 모양은 너무 단조롭지만 않으면 아무렇게나 구성해도 좋습니다.
   단, root에서부터 inorder traversal 을 수행하였을 때, 문구가 올바르게 출력되도록 구성하세요.
*/
public class Task3 {

	public static void main(String[] args) {
//	   	INode
		BinNode<String> h = new INode<>("M", null, null);
		BinNode<String> i = new INode<>("K", null, null);
		BinNode<String> j = new INode<>("O", null, null);
		BinNode<String> k = new INode<>("O", null, null);
		
		BinNode<String> f = new INode<>("I", h, i);
		BinNode<String> g = new INode<>("K", j, k);

		BinNode<String> d = new INode<>("R", f, g);
		BinNode<String> e = new INode<>("M", null, null);
			
		BinNode<String> b = new INode<>("S", d, e);
		BinNode<String> c = new INode<>("S", null, null);
			
		BinNode<String> a = new INode<>("O", b, c);

		System.out.println("========Task3========");
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