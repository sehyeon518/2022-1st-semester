
public class LNode<E> implements BinNode<E>{
	
	public E data;
	// left right 필요 없음
	public LNode(E data) {
		this.data = data;
	}
	
	@Override
	public E element() {
		return data;
	}

	@Override
	public E setElement(E v) {
		return this.data = v;
	}

	@Override
	public BinNode<E> left() {
		return null;
	}

	@Override
	public BinNode<E> right() {
		return null;
	}

	@Override
	public boolean isLeaf() {
		return true;
	}
	public void setLeft(BinNode<E> n) {
	}
	public void setRight(BinNode<E> n) {
	}

}
