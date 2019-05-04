/**
 * @file deque.cpp
 * Implementation of the Deque class.
 *
 */

/* Constructor for the Deque class */
template <class T>
Deque<T>::Deque(){

/* your code here */
    k1 = 0;
    k2 = 0;
}

/**
 * Adds the parameter object to the right of the Deque.
 *
 * @param newItem object to be added to the Deque.
 */
template <class T>
void Deque<T>::pushR(T const& newItem)
{
    /**
     * @todo Your code here!
     */
    data.push_back(newItem);
    k2++;
}

/**
 * Removes the object at the left of the Deque, and returns it to the
 * caller.
 *
 * See .h file for implementation notes. 
 *
 * @return The leftmost item of the Deque.
 */
template <class T>
T Deque<T>::popL()
{
    T retVal = data[k1];
    k1++;

    // Check for resizing
    if (2*k1 >= k2)
    {
        vector<T> temp;
        for (int i = k1; i < k2; i++)
        {
            temp.push_back(data[i]);
        }
        data = temp;
        k2 = k2 - k1;
        k1 = 0;
    }
    return retVal;
}

/**
 * Removes the object at the right of the Deque, and returns it to the
 * caller.
 *
 * @return The rightmost item of the Deque.
 */
template <class T>
T Deque<T>::popR()
{
    T retVal = data[k2-1];
    data.pop_back();
    k2--;

    // Check for resizing
    if (2*k1 >= k2)
    {
        vector<T> temp;
        for (int i = k1; i < k2; i++)
        {
            temp.push_back(data[i]);
        }
        data = temp;
        k2 = k2 - k1;
        k1 = 0;
    }

    return retVal;
}

/**
 * Finds the object at the left of the Deque, and returns it to the
 * caller. Unlike popL(), this operation does not alter the deque.
 *
 * @return The item at the left of the deque.
 */
template <class T>
T Deque<T>::peekL()
{
    return data[k1];
    
}

/**
 * Finds the object at the right of the Deque, and returns it to the
 * caller. Unlike popR(), this operation does not alter the deque.
 *
 * @return the value of The item at the right of the deque.
 */
template <class T>
T Deque<T>::peekR()
{
    return data[k2-1];
}

/**
 * Determines if the Deque is empty.
 *
 * @return bool which is true if the Deque is empty, false otherwise.
 */
template <class T>
bool Deque<T>::isEmpty() const
{
    /**
     * @todo Your code here! 
     */
    return (k1 == 0 && k2 == 0);
}
