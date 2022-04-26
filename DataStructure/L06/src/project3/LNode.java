package project3;
/* BinNode를 상속하여 LNode를 구현하세요.
   LNode는 양쪽 자식이 모두 없는 Leaf node만을 위한 구현입니다.
*/
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

}
