
public interface List<E> { // List에 숫자, 문자열 모두 넣을 수 있다 >> 제네릭
	public void clear();
	public void insert(int pos, E item);
	public void append(E item);
	public void update(int pos, E item);
	public E getValue(int pos);
	public E remove(int pos);
	public int length();
}