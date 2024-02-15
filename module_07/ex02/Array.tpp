/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:52:19 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/13 13:15:29 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : _arr(new T[0]), _length(0) {}

template <typename T>
Array<T>::Array(int n) : _arr(new T[n]), _length(n)
{
    for (int i = 0; i < n; i++)
        _arr[i] = 42;
}

template <typename T>
Array<T>::Array(const Array& a) : _arr(new T[a._length]), _length(a._length)
{
    for (int i = 0; i < _length; i++)
        _arr[i] = a._arr[i];
}

template <typename T>
Array<T>&  Array<T>::operator=(const Array& a)
{
    if (*this != a)
    {
        _length = a._length;
        _arr = new T[_length];
        for (int i = 0; i < _length; i++)
            _arr[i] = a._arr[i];
    }
    return (*this);
}

template <typename T>
T&    Array<T>::operator[](int index)
{
    if (index >= _length)
        throw std::exception();
    return (_arr[index]);
}

template <typename T>
Array<T>::~Array() {
    delete[] _arr;
}

template <typename T>
int     Array<T>::size() const
{
    return _length;
}

#endif