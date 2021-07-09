template <typename T>
	Stack<T> push(Stack<T> s ,T data)
	{
		s.arr[s.top] = data;
		s.top++;
		return s;
	}
template <typename T>
	Stack<T> pop(Stack<T> s)
	{
		if(s.top!=0)
			s.top--;
		return s;
	}
template <typename T>
	bool isEmpty(Stack<T> s)
	{
		if(s.top==0)
			return 1;
		else
			return 0;
	}
