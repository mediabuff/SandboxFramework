#pragma once

#define NULL 0

namespace Collections {
	template<class T>
	class LinkedElement
	{
	public:
		T* Value;
		LinkedElement<T>* Previous;
		LinkedElement<T>* Next;

		LinkedElement()
		{
			Value = NULL;
		}
		
		LinkedElement(T value)
		{
			Value = new T(value);
		}

		~LinkedElement()
		{
			if (Value) delete Value;
		}

		void linkBefore(LinkedElement<T>* next)
		{
			Previous = next->Previous;
			Previous->Next = this;
			next->Previous = this;
			Next = next;
		}

		void linkOut()
		{
			Previous->Next = Next;
			Next->Previous = Previous;
		}
	};
}