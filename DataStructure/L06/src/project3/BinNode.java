package project3;

public interface BinNode<E> { // node 안에 int string 모두 가등
	public E element(); // node item 가져오기
	public E setElement(E v); // element 수정, 설정하기
	
	public BinNode<E> left();
	public BinNode<E> right();
	
	public boolean isLeaf();
}
