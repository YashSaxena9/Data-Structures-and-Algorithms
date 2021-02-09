import java.util.Arrays;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

public class myArrayList<E> implements List<E> {
	private int capacity;
	private Object dataArray[];
	private int endIdx;
	private final int MAX_ALLOWED_SIZE = (int) 1e4;

	public myArrayList() {
		this(15);
	}

	public myArrayList(int size) {
		this.capacity = size;
		this.dataArray = new Object[this.capacity];
		this.endIdx = -1;
	}

	private int sutableNewCapacity(int minCapacityRequired) {
		if (this.capacity < 64) {
			return this.capacity + (this.capacity + 2);
		} else if (this.capacity < 256) {
			return this.capacity + (this.capacity >> 1);
		} else {
			if (minCapacityRequired - this.MAX_ALLOWED_SIZE > 0) {
				return Integer.MAX_VALUE - 1024; // risky
			} else {
				return MAX_ALLOWED_SIZE;
			}
		}
	}

	@Override
	public int size() {
		return this.endIdx + 1;
	}

	@Override
	public boolean isEmpty() {
		return this.endIdx == -1;
	}

	@Override
	public boolean contains(Object o) {
		return indexOf(o) != -1;
	}

	@Override
	public Iterator<E> iterator() {
		return new itr();
	}

	@Override @SuppressWarnings("unchecked")
	public Object[] toArray() {
		Object arrToReturn[] = Arrays.copyOf(this.dataArray, this.endIdx + 1);
		return arrToReturn;
	}

	@Override @SuppressWarnings("unchecked")
    public <T> T[] toArray(T[] a) {
        if (a.length < endIdx + 1) {
            return (T[]) Arrays.copyOf(this.dataArray, endIdx + 1, a.getClass());
		}
        System.arraycopy(this.dataArray, 0, a, 0, endIdx + 1);
        if (a.length > endIdx + 1)
            a[this.endIdx + 1] = null;
        return a;
    }

	@Override
	public boolean add(E e) {
		if (this.endIdx + 1 == this.capacity) {
			if (this.capacity == this.MAX_ALLOWED_SIZE) {
				System.err.println("not enough memory");
				System.err.println("maximum length of myArrayList reached reached");
				return false;
			}
			grow(this.endIdx + 1);
		}
		this.dataArray[++this.endIdx] = e;
		return true;
	}

	private void grow(int minCapacityRequired) {
		int sutableNewCapacity = sutableNewCapacity(minCapacityRequired);
		Object[] newDataArray = new Object[sutableNewCapacity];
		for (int i = 0; i <= this.endIdx; i++) {
			newDataArray[i] = this.dataArray[i];
		}
		this.dataArray = newDataArray;
		System.gc();	//  garbage collector call
	}

	@Override
	public boolean remove(Object o) {
		final Object[] es = this.dataArray;
		final int size = this.endIdx + 1;
        int i = 0;
        found: {
            if (o == null) {
                for (; i < size; i++)
                    if (es[i] == null)
                        break found;
            } else {
                for (; i < size; i++)
                    if (o.equals(es[i]))
                        break found;
            }
            return false;
        }
        fastRemove(es, i);
        return true;
	}

	private void fastRemove(Object[] arr, int idx) {
		for (int i = idx; i < this.endIdx; i++) {
			this.dataArray[i] = this.dataArray[i + 1];
		}
		this.dataArray[this.endIdx--] = null;
	}


	@Override
	public boolean addAll(Collection<? extends E> c) {
		Object[] toAdd = c.toArray();
		if (toAdd.length + this.endIdx + 1 >= this.capacity) {
			grow(toAdd.length + this.endIdx + 2);
		}
		for (int i = 0; i < toAdd.length; i++) {
			this.dataArray[++this.endIdx] = toAdd[i];
		}
		System.gc();
		return true;
	}

	@Override
	public boolean addAll(int index, Collection<? extends E> c) {
		Object[] toAdd = c.toArray();
		if (toAdd.length + this.endIdx + 1 >= this.capacity) {
			grow(toAdd.length + this.endIdx + 2);
		}
		for (int i = 0; i < toAdd.length; i++) {
			this.dataArray[++this.endIdx] = toAdd[i];
		}
		System.gc();
		return false;
	}

	@Override
	public boolean removeAll(Collection<?> c) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public boolean retainAll(Collection<?> c) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public void clear() {
		// TODO Auto-generated method stub

	}

	@Override
	public E get(int index) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public E set(int index, E element) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void add(int index, E element) {
		// TODO Auto-generated method stub

	}

	@Override @SuppressWarnings("unchecked")
	public E remove(int index) {		
		if (this.endIdx == -1) {
			System.err.println("UnderFlow, myArrayList is empty");
			System.err.println("no object found to delete");
			return (E)null;
		}
		Object oldVal = this.dataArray[this.endIdx];
		this.dataArray[this.endIdx--] = null;
		return (E)oldVal;
	}

	@Override
	public int indexOf(Object o) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int lastIndexOf(Object o) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public ListIterator<E> listIterator() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public ListIterator<E> listIterator(int index) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public List<E> subList(int fromIndex, int toIndex) {
		// TODO Auto-generated method stub
		return null;
	}

	// #----------------------------------------------------#

	public class itr implements Iterator<E> {
		private int cursor;

		itr() {
			this.cursor = 0;
		}

		@Override
		public boolean hasNext() {
			return this.cursor < myArrayList.this.endIdx;
		}

		@Override
		@SuppressWarnings("unchecked")
		public E next() {
			E data = (E) myArrayList.this.dataArray[this.cursor];
			this.cursor++;
			return data;
		}
	}

	//  # =================================================
	@Override
	public boolean containsAll(Collection<?> c) {
		return false;
	}

}    
