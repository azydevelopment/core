/* The MIT License (MIT)
*
* Copyright (c) 2017 Andrew Yeung/Bhavya Kashyap <ab.deveng@gmail.com>
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE. */

#pragma once

#include <abdeveng/core/test/common/evaluator.h>

#include <abdeveng/core/service/logger.h>
#include <abdeveng/core/test/common/evaluator.h>

template<typename DUT_TYPE>
class CTestCase
{
public:
    CTestCase(CEvaluator&);
    virtual ~CTestCase();

    virtual void Run(DUT_TYPE& dut) = 0;

    // TODO IMPLEMENT: Copy constructor

protected:
    // Helpers: CEvaluator
    bool Validate(bool checkIfTrue) const;

    template<typename PRIMITIVE>
    bool Validate(PRIMITIVE actual, CEvaluator::COMPARATOR, PRIMITIVE expected) const;

    template<typename PRIMITIVE>
    bool Validate(CEvaluator::EVALUATION<PRIMITIVE>, CEvaluator::COMPARATOR) const;

private:
    CEvaluator& m_evaluator;
};