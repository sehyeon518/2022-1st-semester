package project2;

public class DList<E> implements List<E>{
	DList<E> head, tail;
	int size;
	
	private E item;
	private DList<E> next;
	private DList<E> prev;
	public DList(E item, DList<E> prev, DList<E> next) {
		this.item  = item; this.prev = prev; this.next = next;
	}

	public DList() {
		head = tail = new DList<E>(null, null, null);
		size = 0;
	}
	
	public void clear() {
		head = tail = new DList<E>(null, null, null);
		size = 0;
	}
	
	public void insert(int pos, E item) {
		DList<E> curr = head;
		for(int i = 0; i < pos; i++) {
			curr = curr.next;
		}
		curr.next = new DList<E>(item, curr, curr.next);
		curr.next.next.prev = (curr.next);
		size++;
	}
	public void append(E item) {
		DList<E> n = new DList(item, tail, null);
		tail.next = n;
		tail = n;
		size++;
	}

	public void update(int pos, E item) {
		DList<E> curr = head;
		for(int i = 0; i < pos; i++) {
			curr = curr.next;
		}
		curr.next.item = item;
	}
	
	public E getValue(int pos) {
		DList<E> curr = head;
		for(int i = 0; i < pos; i++) {
			curr = curr.next;
		}
		return curr.next.item;
	}
	public E remove (int pos) {
		DList<E> curr = head;
		for(int i = 0; i < pos; i++) {
			curr = curr.next;
		}
		E ret = curr.next.item;
		curr.next.next.prev = (curr);
		curr.next = (curr.next.next);
		size--;
		return ret;
	}
	public int length() {
		return size;
	}
	public String toString() {
		String a = "";
		DList<E> curr = head;
		for(int i = 0; i < size; i++) {
			a += curr.next.item + " ";
			curr = curr.next;
		}
		String b = "";
		DList<E> rear = tail;
		for(int i = size; i > 0; i--) {
			b += rear.item + " ";
			rear = rear.prev;
		}
		return a + "reverse : " + b;
	}
//	public static void main(String[] args) {
//		DList mylist = new DList<>();
//		System.out.println(mylist);
//		mylist.append(3);
//		System.out.println(mylist);
//		mylist.insert(0,1);
//		System.out.println(mylist);
//		mylist.append(10);
//		System.out.println(mylist);
//		mylist.insert(1,5);
//		System.out.println(mylist);
//		System.out.println("length : " + mylist.length());
//		mylist.clear();
//		System.out.println("length : " + mylist.length());
//	}
	public ListIterator<E> listIterator() {
		return new DoublyLinkedListIterator();
	}
	
	class DoublyLinkedListIterator implements ListIterator<E> {
		DList<E> curr = head;

		@Override
		public boolean hasNext() {
			return curr !=  tail;
		}
		@Override
		public E next() {
			curr = curr.next;
			return curr.item;
		}
		@Override
		public boolean hasPrevious() {
			return curr != head;
		}
		@Override
		public E previous() {
			curr = curr.prev;
			return curr.next.item;
		}
	}

}
