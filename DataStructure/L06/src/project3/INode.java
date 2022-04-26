package project3;
/* BinNode를 상속하여 INode를 구현하세요.
   INode는 값, 왼쪽 자식 포인터, 오른쪽 자식 포인터를 가집니다.
*/
public class INode<E> implements BinNode<E> {
	
	private E data;
	private BinNode<E> l, r;
	
	public INode(E data, BinNode<E> l, BinNode<E> r) {
		this.data = data;
		this.l = l;
		this.r = r;		
	}
	
	@Override
	public E element() {
		return data;
	}

	@Override
	public E setElement(E item) {
		return this.data = item;
	}

	@Override
	public BinNode<E> left() {
		return l;
	}

	@Override
	public BinNode<E> right() {
		return r;
	}

	@Override
	public boolean isLeaf() {
		return (l == null && r == null);
	}

}
