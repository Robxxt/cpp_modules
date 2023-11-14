/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:31:18 by rdragan           #+#    #+#             */
/*   Updated: 2023/11/14 09:40:45 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default form"), _signed(false), _grade_to_sign(10), _grade_to_exec(5) {}

Form::Form(std::string name) : _name(name), _signed(false), _grade_to_sign(10), _grade_to_exec(5) {}

// Form::~Form() {}