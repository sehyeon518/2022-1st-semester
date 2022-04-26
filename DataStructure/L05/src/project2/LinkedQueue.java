package project2;

//선입선출 Queue
public class LinkedQueue<E> implements Queue<E> {
	Link<E> front, rear;
	int size;
	
	public LinkedQueue() {
		front = rear = new Link<E>(null, null);
		size = 0;
	}

    public void clear() {
    	front.next = null;
    	rear = front;
    	size = 0;
    }
    public void enqueue(E it) { // append
    	Link<E> n = new Link<E>(it, null);
    	rear.next = n;
    	rear = n;
    	size++;
    }
    public E dequeue() { // 선출
    	E ret = front.next.item;
    	front.next.item = null;
    	front = front.next;
    	size--;
    	return ret;
    }
    public E frontValue() {
    	E ret = front.next.item;
    	return ret;
    }
    public int length() {
    	return size;
    }
    public String toString() {
    	String a = "";
    	Link<E> curr = front;
    	for (int i = 0; i < size; i++) {
    		a += curr.next.item + " ";
    		curr = curr.next;
    	}
    	return a;
    }
    
//    public static void main(String[] args) {
//		Queue<Integer> mylist = new LinkedQueue<>();
//		mylist.enqueue(-1);
//		System.out.println(mylist);
//		mylist.enqueue(1);
//		System.out.println(mylist);
//		mylist.enqueue(3);
//		System.out.println(mylist);
//		mylist.enqueue(5);
//		System.out.println(mylist);
//		mylist.dequeue();
//		System.out.println(mylist);
//		System.out.println("length : " + mylist.length());
//		mylist.clear();
//		System.out.println("length : " + mylist.length());
//    }
}