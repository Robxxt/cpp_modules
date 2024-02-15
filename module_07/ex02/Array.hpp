/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:52:27 by rdragan           #+#    #+#             */
/*   Updated: 2023/12/13 13:15:09 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>
template <typename T>
class Array {
private:
    T* _arr;
    int _length;

public:
    Array();
    Array(int n);
    Array(const Array& a);
    Array&  operator=(const Array& a);
    ~Array();
    int     size() const;
    T&    operator[](int index);
};

# include "Array.tpp"

#endif
