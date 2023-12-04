template<class T>
void Heap<T>::push(T item){
    if(this->count == this->capacity) this->ensureCapacity(this->capacity*2);
    elements[this->count] = item;
    reheapUp(this->count);
    this->count++;
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    T* newElements = new T[minCapacity];
    for (int i = 0; i < this->count; ++i) {
        newElements[i] = this->elements[i];
    }
    delete[] this->elements;
    this->elements = newElements;
    this->capacity = minCapacity;
}

template<class T>
void Heap<T>::reheapUp(int position){
    if(position<=0 || this->count < position) return;
    int index = (position-1)/2;
    if(elements[position] > elements[index]){
        T temp = elements[index];
        elements[index] = elements[position];
        elements[position] = temp;
        reheapUp(index);
    }
}
