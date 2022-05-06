package project4;

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
	public E setElement(E item) {
		return this.data = item;
	}
	public BinNode<E> left() {
		return l;
	}
	public BinNode<E> right() {
		return r;
	}
	public boolean isLeaf() {
		return (l == null && r == null);
	}
	public void setLeft(BinNode<E> n) {
		this.l = n; 
	}
	public void setRight(BinNode<E> n) {
		this.r = n;
	}
}