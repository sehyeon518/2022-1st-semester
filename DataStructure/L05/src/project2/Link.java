package project2;
public class Link<E> {
	E item;
	Link<E> next;
	
	public Link(E item, Link<E> next) {
		this.item = item;
		this.next = next;
	}
	
	Link<E> next() {return next;}
	Link<E> setNext(Link<E> next) {return this.next = next;}
	
	E item() {return item;}
	E setItem(E item) {return this.item = item;}
}

