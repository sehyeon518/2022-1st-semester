package project2;
//후입선출 Stack
import java.util.Arrays;

public class ArrayStack<E> implements Stack<E> {
	private static int maxSize = 10;
	private int top; // 사이즈
	private  E [] listArray;
	private static int DefaultSize = 10;
	
	public ArrayStack() {
		this(DefaultSize);
	}
	public ArrayStack(int maxSize) {
		top = 0;
		listArray = (E[]) new Object[maxSize];
	}
	public void clear() {
		top = 0;
	}
	public void push(E it) {
		listArray[top++] = it;
	}
	public E pop() {
		E ret = listArray[top-- - 1];
		return ret;
	}
	public E topValue() {
		return listArray[top-1];
	}
	public int length() {
		return top;
	}
	
    public String toString() {
    	String a = "";
    	for (int i = 0; i < top; i++) {
    		a += listArray[i] + " ";
    	}
    	return a;
    }
    
//    public static void main(String[] args) {
//    	ArrayStack<Integer> mylist = new ArrayStack<>();
//    	mylist.push(1);
//    	System.out.println(mylist.toString());
//    	mylist.push(3);
//    	System.out.println(mylist.toString());
//    	mylist.push(5);
//    	System.out.println(mylist.toString());
//    	System.out.println("top value : " + mylist.topValue());
//    	mylist.push(11);
//    	System.out.println(mylist.toString());
//    	System.out.println("pop : " + mylist.pop());
//    	System.out.println(mylist.toString());
//    	System.out.println("length : " + mylist.length());
//    }
}