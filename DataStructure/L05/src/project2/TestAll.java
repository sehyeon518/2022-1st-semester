package project2;

public class TestAll {

	public static void main(String[] args) {
		System.out.println("**********DoublyLinkedList**********");
		DList myDoublylist = new DList<>();
		myDoublylist.append(1);
		myDoublylist.insert(0,0);
		myDoublylist.append(3);
		myDoublylist.insert(2,2);
		myDoublylist.append(5);
		myDoublylist.update(4,100);
		System.out.println("DOUBLY mylist : " + myDoublylist);
		System.out.println("get value : " + myDoublylist.getValue(4));
		System.out.println("length : " + myDoublylist.length());
		myDoublylist.clear();
		System.out.println("length clear : " + myDoublylist.length());
		System.out.println();
		
		System.out.println("*************ArrayStack*************");
		ArrayStack<Integer> myStacklist = new ArrayStack<>();
    	myStacklist.push(0);
    	myStacklist.push(1);
    	myStacklist.push(2);
    	myStacklist.push(3);
    	myStacklist.push(100);
    	System.out.println("STACK mylist : " + myStacklist.toString());
    	System.out.println("top value : " + myStacklist.topValue());
    	System.out.println("length : " + myStacklist.length());
    	System.out.println("pop : " + myStacklist.pop());
    	System.out.println("STACK mylist : " + myStacklist.toString());
    	myStacklist.clear();
    	System.out.println("length : " + myStacklist.length());
    	System.out.println();
    	
    	System.out.println("*************LinkedQueue************");
		Queue<Integer> mylist = new LinkedQueue<>();
		mylist.enqueue(-100);
		mylist.enqueue(0);
		mylist.enqueue(1);
		mylist.enqueue(2);
		mylist.enqueue(3);
		System.out.println("QUEUE mylist : " + mylist);
		mylist.dequeue();
		System.out.println("QUEUE mylist deque : " + mylist);
		System.out.println("length : " + mylist.length());
		System.out.println("front value : " + mylist.frontValue());
		mylist.clear();
		System.out.println("length clear : " + mylist.length());

	}
}