package project4;

public class BST<K extends Comparable<K>, E> implements Dictionary<K, E> {
	// bin node와 달리 key를 받음
	class Entry{
		public K key;
		public E element;
		public Entry(K key, E element) {
			this.key = key;
			this.element = element;
		}
	}
	// binNode k와 e가 함께 있는 entry가 들어감
	private BinNode<Entry> root;
	private int size;
	
	public BST() { // 생성자
		root = null;
		size = 0;
	}
	
	@Override
	public void clear() {
		size = 0;
		root = null;
	}

	@Override
	public void insert(K k, E e) {
		root = insert_helper(k, e, root);
		size++;
	}
	
	public BinNode<Entry> insert_helper(K k, E e, BinNode<Entry> rt) {
		if (rt == null)                                      // search를 끝내고 k에 해당하는 값이없음 >> k에 값을 추가함
			rt = new LNode<>(new Entry(k, e));
		else if (rt.element().key.compareTo(k) == 0)         // >> update
			rt.element().element = e;
		else {
			if (rt.right() == null && rt.left() == null) {
				rt = new INode<>(new Entry(rt.element().key, rt.element().element), null, null);
			}
			if (rt.element().key.compareTo(k) < 0) {         // >> key가 찾고자 하는 k보다 작음
				rt.setRight(insert_helper(k, e, rt.right())); // >> 오른쪽으로 이동
			}
			else {
				rt.setLeft(insert_helper(k, e, rt.left()));   // >> 왼쪽으로 이동
			}
		}
		return rt;
	}

	@Override
	public E remove(K k) {
		E ret = find_helper(k, root);
		if (ret != null) {
			root = remove_helper(k, root);
			size--;
		}
		return ret;
	}
	private BinNode<Entry> remove_helper(K k, BinNode<Entry> rt) {
		if (rt.element().key.compareTo(k) > 0) {
			rt.setLeft(remove_helper(k, rt.left()));
		}
		else if (rt.element().key.compareTo(k) < 0) { // key가 찾고 있는 k보다 작으면
			rt.setRight(remove_helper(k, rt.right()));
		}
		else { // 찾음
			if (rt.left() == null && rt.right() == null) { // 없어도 되는 line
				rt = new LNode<>(new Entry(rt.element().key, rt.element().element));
				return null; // 연결을 끊음
  			}
  			else if (rt.left() == null) {
				return rt.right();
			}
			else if (rt.right() == null) {
				return rt.left();
			}
			else {                                        // 지워야하는 node 양쪽에 자식이 있음
				Entry leftmost = getLeftMost(rt.right()); // 오른쪽의 가장 왼쪽 끝 minimum node 찾기
				rt.setElement(leftmost);
				rt.setRight(removeLeftMost(rt.right()));
			}
		}
		return rt;
	}
	private Entry getLeftMost(BinNode<Entry> rt) {
		BinNode<Entry> cur = rt;
		while (cur.left() != null) {
			cur = cur.left();
		}
		return cur.element();
	}
	private BinNode<Entry> removeLeftMost(BinNode<Entry> rt) {
		if (rt.left() == null) return rt.right();
		else {
			rt.setLeft(removeLeftMost(rt.left()));
			return rt;
		}
	}

	@Override
	public E removeAny() {
	    size--;
		return remove(root.element().key);
	}

	@Override
	public E find(K k) {
		return find_helper(k, root);
	}
	public E find_helper(K k, BinNode<Entry> rt) {
		if (rt == null) return null;
		else if (rt.element().key.compareTo(k) == 0)
			return rt.element().element;
		else if (rt.element().key.compareTo(k) < 0)  //key가 k보다 작으면
			return find_helper(k, rt.right());
		else
			return find_helper(k, rt.left());
	}

	@Override
	public int size() {
		return size;
	}
	@Override
	public void inorder() {
		inorder_helper(root);
		System.out.println();
	}
	public void inorder_helper(BinNode<Entry> rt) {
		if (rt == null) return;
		inorder_helper(rt.left());
		System.out.print(rt.element().key + " " + rt.element().element); // visit
		if (rt instanceof INode) System.out.print("(INode) ");
		else if (rt instanceof LNode) System.out.print("(Lnode) ");
		inorder_helper(rt.right());
	}
}