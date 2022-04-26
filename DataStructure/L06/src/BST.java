
public class BST<K extends Comparable<K>, E> implements Dictionary<K, E> {

	// bst에서는 binnode와 달리 key를 받음
	class Entry{
		public K key;
		public E element;
		public Entry(K key, E element) {
			this.key = key;
			this.element = element;
		}
	}
	// binNode로는 k와 e가 함께 있는 entry가 들어감
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
	}
	
	public BinNode<Entry> insert_helper(K k, E e, BinNode<Entry> rt) {
		if (rt == null) // search를 끝내고 k에 해당하는 값이 없음>> k에 값을 추가함
			return new INode<>(new Entry(k, e), null, null);
		else if (rt.element().key.compareTo(k) == 0) // >> update
			rt.element().element = e;
		else if (rt.element().key.compareTo(k) < 0) // >> key가 찾고자 하는 k보다 작음
			rt.setRight(insert_helper(k, e, rt.right()));
		else
			rt.setLeft(insert_helper(k, e, rt.left()));
		
		return rt;
	}

	@Override
	public E remove(K k) {
		
		return null;
	}

	@Override
	public E removeAny() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public E find(K k) {
		return find_helper(k, root);
	}
	public E find_helper(K k, BinNode<Entry> rt) {
		if (rt == null)
			return null;
		else if (rt.element().key.compareTo(k) == 0)
			return rt.element().element;
//		rt.element().key < k	
		else if (rt.element().key.compareTo(k) < 0)
			return find_helper(k, rt.right());//key가 k보다 작으면 음수가 나옴
		else
			return find_helper(k, rt.left());
	}

	@Override
	public int size() {
		return size;
	}

}
