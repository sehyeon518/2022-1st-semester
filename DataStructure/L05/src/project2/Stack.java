package project2;
public interface Stack<E> {
	public void clear();
	public void push(E it);
	public E pop();
	public E topValue();
	public int length();
}
